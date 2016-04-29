import sys

#print 'First argument:',sys.argv[1]
#		print 'Second argument:',sys.argv[2]


f1=sys.argv[1]
f2=sys.argv[2]
lst1=[]
obj1=open(f1,'r')

lst=obj1.readlines()
for i in lst:
	lst1.append(i.split(' '))

add=0 
for i in lst1:
	add=add+int(i)
	
obj1.close();

obj2=open(f2,'w')
obj2.write(str(add))
obj2.write('\n')

obj2.close();
