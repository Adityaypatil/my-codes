
inputlist =[]
daytype = []
demands = []
good_list = []
avg_list = []
poor_list =[]
good_cdf_list = []
average_cdf_list = []
poor_cdf_list = []
day_cdf_list = []
day_prob = []
demand_prob = []

f = open("daytype.txt","r")

print "\nGood\tAverage\tPoor\n"

for i in f:
	daytype.append(float(i[:-1]))
	
	print str(i[:-1]+"\t"), 
	
print "\nDemand\tGood\tAverage\tPoor\n"

f1 = open("datafile.txt","r")

for i in f1:
	i=i.split(" ")
	demands.append(float(i[0]))
	good_list.append(float(i[1]))
	avg_list.append(float(i[2]))
	poor_list.append(float(i[3][:-1]))	
	print i[0] + "\t" +i[1] +"\t" + i[2] +"\t"+ i[3][:-1]


day_cdf_list.append(daytype[0])
for i in range(1,(len (daytype))):
	day_cdf_list.append(day_cdf_list[i-1] + daytype[i]) 

print day_cdf_list

good_cdf_list.append(good_list[0])
for i in range(1,(len (good_list))):
	good_cdf_list.append(good_cdf_list[i-1] + good_list[i]) 

average_cdf_list.append(avg_list[0])
for i in range(1,(len (avg_list))):
	average_cdf_list.append(average_cdf_list[i-1] + avg_list[i]) 

print average_cdf_list

poor_cdf_list.append(poor_list[0])
for i in range(1,(len (poor_list))):
	poor_cdf_list.append(poor_cdf_list[i-1] + poor_list[i]) 


f=open("input.txt","r")

print "\nDay\tDemand\n"	
for i in f:
	i=i.split(" ")
	day_prob.append(float (i[0]))
	demand_prob.append(float (i[1][:-1]))
	print i[0]+"\t"+i[1] 
	
dayType =0
demand=0
revenue=0
profit =0
scrap=0
loss=0	
earn=0

for i in range(0, len(day_prob)):
	dayProbab = day_prob[i]
	demandProbab = demand_prob[i]

	for j in range(0,len(day_cdf_list)):
		if dayProbab <= day_cdf_list[j]:
			dayType = j
			break
	
	if dayType == 0:
		referdemandlist = good_cdf_list
	elif dayType == 1:
		referdemandlist = average_cdf_list
	else:
		referdemandlist = poor_cdf_list

	for k in range(0,len(referdemandlist)):
		if demandProbab <= referdemandlist[k]:
#			print demandProbab
#			print referdemandlist[i]
			demand = demands[k]
#			print demand
			break

	stock=400
	costprice=400
	if demand <=stock:
		revenue=demand*2
		#profit=demand
		profit=revenue-costprice
		loss=0
		scrap=(((stock-demand)/100)*50)
		earn=profit+scrap
		#earn=revenue-scrap
		if earn >=0:
			p_L= str("p")
		else:
			p_L=str("L")
	else:
		revenue=stock*2
		profit=revenue-costprice
		scrap =0
		loss=(demand-stock)*2
		earn=profit+scrap
	 	#earn=revenue-scrap
		if earn >=0:
			p_L= str("p")
		else:
			p_L=str("L")

	print "\nR.N_Day\tDay_type\tR.N_Dem\tDem\tRev\tProf\tLoss\tScrap\tEarn\tP/L" 

	print str(dayProbab)+"\t"+str(dayType)+"\t\t"+str(demandProbab)+"\t"+str(demand)+"\t"+str(revenue)+"\t"+str(profit)+"\t"+str(loss)+"\t"+str(scrap)+"\t"+str(earn)+"\t"+str(p_L)
