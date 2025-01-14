#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdbool.h>

#define PORT 8000
#define BUFFER_SIZE 1024

bool check_hash(char *hash1, char *hash2)
{
    return strcmp(hash1, hash2) == 0;
}

char* read_sha()
{
    char *sha_sum = "sha_sum.txt";
    FILE *sha = fopen(sha_sum, "r");
    if (sha == NULL) {
        perror("Error opening file");
        return NULL;
    }

    fseek(sha, 0, SEEK_END);
    int length = ftell(sha);
    fseek(sha, 0, SEEK_SET);

    char *sha_buf = (char *)malloc(length + 1);
    if (sha_buf == NULL)
    {
        perror("Error allocating memory");
        fclose(sha);
        return NULL;
    }

    fread(sha_buf, 1, length, sha);
    sha_buf[length] = '\0';
    fclose(sha);

    return sha_buf;
}

int main()
{
    int server_fd, client_socket, val_read;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];
    char *filename = "server_hash_code.txt";
    char *sha_read = NULL;
    FILE *fp;

    // Create Socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) 
    {
        perror("Socket creation failed!");
        exit(EXIT_FAILURE);
    }

    // Configure Server Address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind Socket
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) 
    {
        perror("Binding Failed!");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen for Connection
    if (listen(server_fd, 1) == -1) 
    {
        perror("Listening Failed!");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server running, waiting for connection on port %d...\n", PORT);

    while (1) 
    {
        // Accept client connection
        client_socket = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len);
        if (client_socket == -1) {
            perror("Accept Failed!");
            close(server_fd);
            exit(EXIT_FAILURE);
        }
        printf("Client connected.\n");

        // Open the file for writing
        fp = fopen(filename, "w+");
        if (fp == NULL)
        {
            perror("fopen");
            close(client_socket);
            continue;
        }

        // Receive and write data to file
        while ((val_read = read(client_socket, buffer, BUFFER_SIZE)) > 0) 
        {
            fwrite(buffer, 1, val_read, fp);
        }
        fclose(fp);

        // Compute hash and read it
        system("cat server_hash_code.txt | sha256sum > sha_sum.txt");
        sha_read = read_sha();
        printf("%s", sha_read);
        if (sha_read == NULL)
        {
            printf("Failed to read SHA sum. Closing connection...\n");
            close(client_socket);
            continue;
        }

        // Print the received hash
        printf("Received hash: %s\n", sha_read);

        // Compare hashes
        char *expected_hash = "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855";

        if (check_hash(sha_read, expected_hash))
        {
            printf("Hashes match! Allowing client to execute commands...\n");

            // Send a verification message to the client
            send(client_socket, "VERIFY_OK", 9, 0);

            while (1) 
            {
                memset(buffer, 0, BUFFER_SIZE);
                //use recv convert to text decode and compare

            val_read = recv(client_socket, buffer, BUFFER_SIZE, 0);
                if (val_read <= 0) 
                {
                    break;
                }

                if (strncmp(buffer, "exit", 4) == 0)
                {
                    break;
                }

                // Execute command and send output to client
                FILE *cmd_fp = popen(buffer, "r");
                if (cmd_fp == NULL) 
                {
                    perror("popen");
                    continue;
                }

                while (fgets(buffer, BUFFER_SIZE, cmd_fp) != NULL) 
                {
                    send(client_socket, buffer, strlen(buffer), 0);
                }
                pclose(cmd_fp);
            }
        }
        else
        {
            // If hashes do not match, send failure to client
            send(client_socket, "VERIFY_FAIL", 11, 0);
            printf("Hashes do not match! Closing connection...\n");
        }

        free(sha_read);
        close(client_socket);
    }

    close(server_fd);
    return 0;
}