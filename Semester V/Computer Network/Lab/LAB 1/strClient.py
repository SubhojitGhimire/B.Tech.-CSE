import socket
import sys

HOST = input ("HOST: ")
PORT = int(input ("PORT: "))

s = socket.socket (socket.AF_INET, socket.SOCK_STREAM)
s.connect ((HOST, PORT))

print ("Client Connected...\n")

while True:
    msg = str (input("> "))
    if not msg:
        break
    s.sendall (msg.encode())
    data = s.recv (1024)
    if not data:
        break
    if (data.decode('utf-8') == 'ack'):
        continue
    print ("Server Msg: ", data.decode('utf-8'))