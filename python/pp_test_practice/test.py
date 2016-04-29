import sys
a=open(sys.argv[1],"r+")
b=open(sys.argv[2],"w+")

c="<html>\n<body>\n<table>\n<tr>\n<td>"	
b.write(c)
c=a.readline()
b.write(c)
c="</td>\n</tr>"
b.write(c)
d="<tr>\n<td>"
for i in a:
	b.write(d)
	if i[0]!='{':
        	if i[0]!='}':
			for j in range(0,len(i)):
				if 'for' in i:
					for k in range(0,len(i)):
						if i[k]==';':
							b.write(" ")	
						else:
							b.write(i[k])					
if i[0]=='{':
	if i[0]=='}':	
		for j in range(0,len(i)):
			if i[j]==';' and i[j+1]=='\n':
				b.write(c)
			else:
				if i[j]==';':
					b.write(" ")
				else:	
					if i[j]=='<':
						b.write(i[j])
					else:
						b.write(i[j])
	

		
b.write("</table>\n</body>\n</html>")	
			

		

