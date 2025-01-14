import socket
import hashlib
import subprocess

def calculate_hash(filename):
    """Calculate SHA256 hash of the given file."""
    sha256 = hashlib.sha256()
    with open(filename, 'rb') as f:
        while chunk := f.read(4096):
            sha256.update(chunk)
    return sha256.hexdigest()

def handle_client(conn, addr):
    print(f"Connected by {addr}")

    #This hashes the file
    file_data = conn.recv(1024).decode()
    received_hash = conn.recv(1024).decode()

    with open('sha_sum.txt', 'w') as f:
        f.write(file_data)

    #compare and verify
    calculated_hash = calculate_hash('hash_code.txt')
    if calculated_hash != received_hash:
        conn.sendall(b"Hash mismatch. File verification failed.")
        print("Hash mismatch. Connection closed.")
        return
    conn.sendall(b"File received and verified.")

    # Allows user to send commants
    while True:
        command = conn.recv(1024).decode()
        if command.lower() == 'exit':
            conn.sendall(b"Connection closed.")
            print("Client disconnected.")
            break
        try:
            #subprocesses module used to send commands to the shell
            output = subprocess.check_output(command, shell=True, stderr=subprocess.STDOUT, text=True)
            conn.sendall(output.encode())
            #built in error handling
        except subprocess.CalledProcessError as e:
            conn.sendall(f"Command error: {e.output}".encode())

def start_server():
    """Start the server to accept connections and handle client requests."""
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind(('localhost', 8000))
        s.listen()
        print('Server is listening on port 8000...')
        while True:
            conn, addr = s.accept()
            with conn:
                handle_client(conn, addr)

if __name__ == '__main__':
    start_server()
