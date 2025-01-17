//Header Files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdbool.h>

//Constants
#define PORT 8000
#define BUFFER_SIZE 1024
#define SHA_SIZE 256

//Function for hash comparison
bool check_hash(char *hash1, char *hash2)
{
    return hash1 && hash2 && strcmp(hash1, hash2) == 0;
}

int main()
{
    //Variables
    int server_fd, client_socket, val_read;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];
    char command_output[BUFFER_SIZE];
    char sha_read[SHA_SIZE];
    char hash_value[65];
    char buffer3[BUFFER_SIZE];
    FILE *fp;

    //Creates the socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    //Error handling for failure to create socket.
    if (server_fd == -1)
    {
        perror("Socket creation failed!");
        exit(EXIT_FAILURE);
    }

    /*Variables to specify which address and port to connect to.
    INADDR_ANY binds to all available networks on host machine.*/
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    //Error handling for failure to bind or listen.
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("Binding Failed!");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 1) == -1)
    {
        perror("Listening Failed!");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    //Message for a successful connection
    printf("Server running, waiting for connection on port %d...\n", PORT);
    
    while (1)
    {
        //Accepts client connection
        client_socket = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len);
        //Error handling for unsuccessful connection.
        if (client_socket == -1)
        {
            perror("Accept Failed!");
            close(server_fd);
            exit(EXIT_FAILURE);
        }
        printf("Client connected.\n");

        //clear the buffer to prepare for user data
        memset(buffer, 0, BUFFER_SIZE);
        val_read = recv(client_socket, buffer, BUFFER_SIZE, 0);

        //Error handling for non-input from user.
        if (val_read <= 0)
        {
            printf("Error or no data received from client\n");
            close(client_socket);
            continue;
        }

        buffer[val_read] = '\0';  // Null-terminate received data

        //Take in recived data and tokenice is split by a hyphen.
        char *hash_get = strtok(buffer, "-");
        if (hash_get)
        {
            /*Saves the first 64 chars [the hash of the data the user sends]
            to a new variable then null terminates it.*/
            strncpy(hash_value, hash_get, 64);
            hash_value[64] = '\0';

            char *f_content = strtok(NULL, "");
            if (f_content)
            {
                //Server side opens their file to get the server side hash
                fp = fopen("server_hash_code.txt", "w");
                if (!fp)
                {
                    perror("Error opening file");
                    close(client_socket);
                    continue;
                }
                fputs(f_content, fp);
                fclose(fp);
            }
        }
        //create server hash
        fp = popen("sha256sum server_hash_code.txt", "r");
        if (!fp)
        {
            perror("popen");
            close(client_socket);
            continue;
        }
        fgets(buffer, BUFFER_SIZE, fp);
        pclose(fp);

        sscanf(buffer, "%64s", sha_read);
        sha_read[64] = '\0';
        
        /*This check compares the hashes and on successful compare
        allows the user to send commands otherwise it terminates the connection*/
        if (check_hash(sha_read, hash_value))
        {
            printf("Hashes match! Allowing client to execute commands...\n");
            send(client_socket, "VERIFY_OK", 9, 0);
        }
        else
        {
            send(client_socket, "VERIFY_FAIL", 11, 0);
            printf("Hashes do not match! Closing connection...\n");
            close(client_socket);
            break;
        }

        while (1)
        {
            //Clears the buffer to prepare for user commands
            memset(buffer3, 0, BUFFER_SIZE);
            val_read = recv(client_socket, buffer3, BUFFER_SIZE, 0);
            if (val_read <= 0)
            {
                printf("No command received or connection closed.\n");
                printf("Server running, waiting for connection on port %d...\n", PORT);
                break;
            }

            buffer[val_read] = '\0';  // Null-terminate the received command
            printf("Received command: %s\n", buffer3);

            //Write the user command to a file.
            FILE *cmd_log_fp = fopen("client_commands.txt", "a");
            if (cmd_log_fp)
            {
                fprintf(cmd_log_fp, "%s\n", buffer3);
                fclose(cmd_log_fp);
            }
            else
            {
                perror("Error opening client_commands.txt for logging");
            }
            //Code to exit if the user specifies
            if (strncmp(buffer3, "exit", 4) == 0)
            {
                printf("Client requested to exit.\n");
                printf("Server running, waiting for connection on port %d...\n", PORT);
                break;
            }

            FILE *cmd_fp = popen(buffer3, "r");
            if (!cmd_fp)
            {
                perror("popen");
                continue;
            }
            //Sends the command to the server shell to be executed
            while (fgets(command_output, BUFFER_SIZE, cmd_fp) != NULL)
            {
                send(client_socket, command_output, strlen(command_output), 0);
            }
            pclose(cmd_fp);

            // Send end-of-output marker
            send(client_socket, "### END_OF_OUTPUT ###", strlen("### END_OF_OUTPUT ###"), 0);
        }
    }
    //Close both sides on program exit.
    close(server_fd);
    close(client_socket);
    return 0;
}