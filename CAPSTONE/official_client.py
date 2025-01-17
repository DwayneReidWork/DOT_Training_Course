import socket
import sys
import os
import hashlib
 
# Function to send commands and receive output
def send_command(socket, command):
    socket.sendall(command.encode())  # Send the command
    output = socket.recv(4096).decode()  # Receive the output
    print(f"Command Output:\n{output}")
 
# Funtion to compute the SHA-256 hash of a file
def calculate_file_hash(file_path):
    with open(file_path, "rb") as file:
        file_contents = file.read()
        sha256_hash = hashlib.sha256(file_contents).hexdigest()
    return sha256_hash
 
# Function to send a file to the server
def send_file(socket, file_path):
    if not os.path.isfile(file_path):
        print(f"File {file_path} does not exist.")
        return False
 
    file_name = os.path.basename(file_path)
    file_hash = calculate_file_hash(file_path)
 
    # Send the hash and the content in the format "hash-content"
    # socket.sendall(f"{file_hash}-".encode())  # Send the file's hash first, followed by a hyphen
    
 
    with open(file_path, "r") as file:
        while (chunk := file.read(4096)):
            socket.sendall(f"{file_hash}-{chunk}".encode())
 
    print(f"File {file_name} sent successfully.")
    return file_hash  # Return the hash for later verification

#Function to open a socket and connect to the server
def open_socket(svr_addr):
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect(svr_addr)
    print("Connected to the server.")
    return s

def main():
    #server address and prompt for user to specify file sent
    server_address = ('127.0.0.1', 8000)
    file_path = input("Enter the path of the file to upload: ")
 
    try:
        sock = open_socket(server_address)
        file_hash = send_file(sock, file_path)
 
        # Wait for verification response
        server_response = sock.recv(1024).decode()  # Expecting 'VERIFY_OK' or 'VERIFY_FAIL'
        if server_response == "VERIFY_OK":
            print("File verified successfully.")
           
            # Now send commands
            while True:
                command = input("Enter a system command to execute on the server (or 'exit' to quit):\n>>> ")
                #Accepts keyword to end sending commands
                if command.lower() == 'exit':
                    sock.sendall("exit".encode())
                    break
                send_command(sock, command)
 
        else:
            #Error handling
            print("File verification failed.")
            sock.close()
 
    except Exception as e:
        print(f"An error occurred: {e}")
        sock.close()
        sys.exit(1)
 
if __name__ == "__main__":
    main()