import socket
import sys

HOST = '127.0.0.58'
PORT = 5005

s = socket.socket (socket.AF_INET, socket.SOCK_STREAM)
s.bind ((HOST, PORT))
s.listen (1)

print ("Listening...")

conn, addr = s.accept ()
print ("Client Connected: ", addr)

ack = "ack"

while True:
    data = conn.recv (1024)
    if (data.decode('utf-8') == 'exit'):
        break
    if not data:
        break
    if (data.decode('utf-8')[0:4] == "ECHO" or data.decode('utf-8')[0:4] == "echo"):
        conn.sendall (data[5:])
        continue
    conn.sendall (ack.encode())
conn.close()
