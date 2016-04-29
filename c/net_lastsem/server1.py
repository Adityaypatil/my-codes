import socket
import sys

sock=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

server_Add=('localhost',10001)

sock.bind(server_Add)

while True:
	print 'Waiting to message :'
	data, address = sock.recvfrom(1024)
	
	print 'received %s bytes from %s' % (len(data), address)
	print data

	if not data:
		break
	
	elif data:
		sent=sock.sendto(data, address)
print address[1]
sock.close()
