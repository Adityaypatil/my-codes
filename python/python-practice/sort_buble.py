list=[21,45,11,77,33,10]
length=len(list)-1

for i in range(length):
	for j in range(length-1):
		if list[j]>list[j+1]:
			temp=list[j]
			list[j]=list[j+1]
			list[j+1]=temp
		
print list

