
def getocc(a,size):
	
	temp= 0
	end= 0
	
	for i in range(0,size):
		temp=temp+a[i]
		
		if(end < 0):
			end=0
		
		if(temp < end):
			temp=end

	return temp
	
a = [-2,-3,4,-1,-2,1,5,-3]

print "Addition is :",getocc(a,len(a))
