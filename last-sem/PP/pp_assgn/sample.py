roll_num=[]
proj_num=[]
grp_nums=[]

f1=open("samplegrp.txt","r")

for i in f1:
	i=i.split(",")
	roll_num.append(i[0])
	proj_num.append(i[1])
	grp_nums.append(i[2])

print roll_num
