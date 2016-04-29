a=10

def rec(a):
	if a==1:
		return 1
	return (rec(a-1), a)
	#print rec(a)
print rec(a)
