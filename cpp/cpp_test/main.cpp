#include<iostream>
#include"header.h"
#include"cstdlib"

using namespace std;

int main()
{
	meter m1;
	int n,set;
	m1.details();
	
	cout<<"One interation is one kilometer"<<endl<<endl;
	cout<< "Enter number of interation to see distance cover in that interation:";
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		
		m1.disp_totaldis();
		m1.disp_trip_dis();
					
	}
	cout<<"\nIf you want reset trip distance then Enter 0 or if not then enter value=>\n";
	cin>>set;
	
	if(set==0)
		m1.set_trip(0);
	else
		exit(0);
	return 0;
}


