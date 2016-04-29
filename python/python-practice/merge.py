list=[11,4,2,8,5,9,33,22,14]
print list

list1=list[0:4]
list2=list[5:8]

length=len(list1)
length1=len()

def merge(list1,list2):
	for i in range(length):
		for j in range(length-1):
			if list[j]>list[j+1]:
				list[j],list[j+1]=list[j+1],list[j]
				print list
