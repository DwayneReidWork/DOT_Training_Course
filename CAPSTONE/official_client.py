import socket
import sys
import os
import hashlib

# Function to send commands and receive output
def send_command(socket, command):
    socket.sendall(f"CMD {command}".encode())  # Send command
    output = socket.recv(4096).decode()  # Receive the output
    print(f"Command Output:\n{output}")

# Function to compute the SHA-256 hash of a file
def calculate_file_hash(file_path):
    with open(file_path, "rb") as file:
        file_contents = file.read()
        sha256_hash = hashlib.sha256(file_contents).hexdigest()

    print(f"File SHA-256 Hash: {sha256_hash}")
    return sha256_hash

# Function to send a file to the server
def send_file(socket, file_path):
    if not os.path.isfile(file_path):
        print(f"File {file_path} does not exist.")
        return False

    # Send file metadata (name and size)
    file_name = os.path.basename(file_path)
    file_size = os.path.getsize(file_path)
    file_hash = calculate_file_hash(file_path)

    socket.sendall(f"FILE {file_name} {file_size} {file_hash}".encode())  # Send file info

    # Send the file content in chunks
    with open(file_path, "rb") as file:
        while (chunk := file.read(4096)):
            socket.sendall(chunk)

    print(f"File {file_name} sent successfully.")
    return file_hash  # Return the hash for later verification

def main():
    # Connection details
    server_address = ('127.0.0.1', 8000)  # Server IP and port
    file_path = "hash_code.txt"

    try:
        # Create a socket and connect to the server
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.connect(server_address)
            print("Connected to the server.")

            # Send the file and its hash
            send_file(s, file_path)

            # Wait for file verification response
            server_response = s.recv(1024).decode()  # Expecting 'VERIFY_OK' or 'VERIFY_FAIL'
            print(f"Server response after file: {server_response}")

            if server_response == "VERIFY_OK":
                print("File verified successfully.")
            else:
                print("File verification failed.")
                return

            # Send commands to the server
            while True:
                command = input("Enter a system command to execute on the server (or 'exit' to quit): ")
                if command.lower() == 'exit':
                    break
                send_command(s, command)

    except Exception as e:
        print(f"An error occurred: {e}")
        sys.exit(1)

if __name__ == "__main__":
    main()
