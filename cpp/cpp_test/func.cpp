#include<iostream>
#include"header.h"
using namespace std;

int meter:: total_dis_k=50000;
int meter:: trip_m=300;

meter::meter()
{
	
}

void meter::disp_totaldis()
{

	 cout<<"\nTotal Distance in kilometeres:"<<++total_dis_k<<endl;
	
}

void meter::disp_trip_dis()
{
	 cout<<"\nTrip Distance in meters:"<<++trip_m<<endl;

}

void meter::set_trip(int val)
{
	meter m;
	m.trip_m=0;
	cout<<"\nNow Total trip is :"<<trip_m<<endl;
}	
	
void meter::details()
{
	meter m;
	//m.model_name="Bajaj";
//	m.serial_num=9249;
	cout<<"Model name : Bajaj"<<endl<<endl;
//	cout<<"Serial Number:"<<serial_num<<endl;
}
