def main1():
fp=open("xxx.txt","r")
print "Name of the file :",fp.name
line = fp.readline()
print "Number of total matrices are:%s" % (line)
n=int(line)
line1=fp.readline()

temp=[]
temp1=[]

for i in range (len(line1)):
if (line1[i].isdigit()):
temp=temp+[int(line1[i])]
		
if(len(temp)==2):
temp1.append(temp)
temp=[]			
print temp1
main1()
