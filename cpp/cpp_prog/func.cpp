#include<iostream>
#include"header1.h"

using namespace std;

//int rectangle::count=0;

rectangle::rectangle()
{
	l=2.0;
	b=3.0;
}

rectangle::rectangle(float ll,float bb)
{
	l=ll;
	 b=bb;
}

rectangle::rectangle(const rectangle &t)
{
	l=t.l;
	b=t.b;
}

float rectangle::calc_area()
{
		
	return (l*b);
}

void rectangle::Display(float area)
{
	cout<<"\nArea:"<<area<<endl;
}
