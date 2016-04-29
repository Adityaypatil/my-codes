import socket
import sys

sock=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

server_Add=("localhost",10001)
#data= 'Hello'
while(1):
	data = raw_input('Enter any data :')

	print 'sending data :%s' % data

	sent=sock.sendto(data,server_Add)

	print 'Waiting :'

	data,server=sock.recvfrom(1024)

	print 'Recieve data :%s' % data
	
	print 'CLosing socket'


sock.close()	

