import socket, time, sys

message = sys.argv[1]

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(('localhost', 27015))
print (client.send(message.encode('utf-8')), b'bytes sent.')
time.sleep(0.2)
print (b'Received message:', client.recv(1024))
