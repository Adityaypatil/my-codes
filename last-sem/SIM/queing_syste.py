
s=0
avg=0
arrival_time = []
service_time = []
waiting_time = []
service_start_time = []
clock_arrival_time = []
end_time = []

f=open("arrival.txt","r")
#print "Ai \t  Si"

for i in f:
	i=i.split(" ")
	arrival_time.append(float(i[0]))
	service_time.append(float(i[1][:-1]))
#	print i[0] + "\t" + i[1][:-1]

waiting_time.append(0)
clock_arrival_time.append(arrival_time[0])
service_start_time.append(arrival_time[0])
end_time.append(service_start_time[0]+ service_time[0])



for i in range(1, len(arrival_time)):
	clock_arrival_time.append(clock_arrival_time[i-1] + arrival_time[i])
#print clock_arrival_time	 


for i in range(1,len(service_time)):
	if clock_arrival_time[i]<(service_start_time[i-1] +service_time[i-1]):
			service_start_time.append(service_start_time[i-1] + service_time[i-1])
	else:
			service_start_time.append(clock_arrival_time[i-1])
			

for i in range(1,(len(service_time))):
	end_time.append(service_start_time[i-1] + service_time[i-1])


for i in range(1,(len(service_time))):
	waiting_time.append(service_start_time[i]- clock_arrival_time[i])
	
for i in range(0,len(waiting_time)):
	s=s+waiting_time[i]

n=len(waiting_time)

avg =s/n	
	
print "Arr_Time\tSer_Time\tCl_Arr_Time\tS_Time\t\tE_Time\t\tW_Time"  

for i in range(0,len(service_time)):
	print arrival_time[i],"\t\t",service_time[i],"\t\t",clock_arrival_time[i],"\t\t",service_start_time[i],"\t\t",end_time[i],"\t\t",waiting_time[i]	 

			
print "Addition of waiting time:"+str(s)				
print "Average time:"+str(avg)
			
