#include<iostream>
using namespace std;

class construct
{

	public:	
		int a,b;
		construct();
		construct(int x,int y);			
};

construct::construct()
{

	cout<<"Hello !!";
			
}

construct::construct(int x, int y)
{
	a=x;
	b=y;
	cout<<"Hours is:"<<a;
	cout<<"MINute is :"<<b;
}



int main()
{
	construct c;
	construct c1(10,20);
	
	return 0;
}

