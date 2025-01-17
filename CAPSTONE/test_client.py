import socket
import hashlib

def calculate_hash(filename):
    """Calculate SHA256 hash of the given file."""
    sha256 = hashlib.sha256()
    with open(filename, 'rb') as f:
        while chunk := f.read(4096):
            sha256.update(chunk)
    return sha256.hexdigest()

def connect_to_server(filename):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect(('localhost', 8000))
        with open(filename, 'r') as f:
            file_data = f.read()

        file_hash = calculate_hash(filename)
        s.sendall(file_data.encode())
        s.sendall(file_hash.encode())

        response = s.recv(1024).decode()
        print('Server:', response)

        if response == "File received and verified.":
            while True:
                command = input("Enter command (type 'exit' to quit): ")
                s.sendall(command.encode())
                if command.lower() == 'exit':
                    break
                output = s.recv(1024).decode()
                print("Command Output:\n", output)

if __name__ == '__main__':
    connect_to_server('hash_code.txt')