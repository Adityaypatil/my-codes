import socket
import sys


sock=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)# create udp socket

server_Add=("localhost",10001)
#data= 'Hello'
while (True) :

	data = raw_input('Enter any data :')
	if (data !=0):
		print 'sending data :%s' % data

		sent=sock.sendto(data,server_Add)

		print 'Waiting :'

		data,server=sock.recvfrom(4000)

		print 'Recieve data :%s' % data
	
		print 'CLosing socket'
	elif(data==0):
		sock.close()
		exit()
		#break	

