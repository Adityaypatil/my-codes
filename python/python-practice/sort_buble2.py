list=[11,4,2,8,5]
print list

length=len(list)

for i in range(length):
	for j in range(length-1):
		if list[j]>list[j+1]:
			list[j],list[j+1]=list[j+1],list[j]
			print list
