#!/usr/bin/python           # This is server.py file
import socket               # Import socket module

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		
server_Add=('localhost',10001)

#sock.bind(server_Add)
s = socket.socket()         # Create a socket object
      
		
for i in range(0,65536): 	
		if (sock== -1):
				print "Connection Failed"
		
		#serveraddr.sin_family=AF_INET
        	#serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1")
		#serveraddr.sin_port=i
		#serverlen=sizeof(serveraddr)
			
		#a=s.bind((server_Add)) 
		
	
		if(a ==-1):
			print 'Port in use :',i
		else:
			print 'Not in use :', i
			

sock.close()
