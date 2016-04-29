#include<iostream>
using namespace std;

class time1{
	private: int h;
			int m;
			
	public:	
			time1()
				{
					cout<<"In Default Constructor\n";
					//h=0;
					//m=0;
					cout<<"Hrs:"<<h<<endl;
					cout<<"Min:"<<m<<endl;
				}
			time1(int x,int y)
				{
					cout<<"In parameterised constructor\n";
					h=x;
					m=y;		
					cout<<"Hrs:"<<h<<endl;
					cout<<"MIn:"<<m<<endl;
				}
			time1 (int x)
				{
				cout<<"Sinlge para. Constructor\n";
				h=x;
				cout<<"Hrs:"<<h<<endl;
				}	
};
int main()
{
	time1 t1;
	//time1 t2(5,10);
	//time1 t3(4);
	//time1 t4=t2;
	return 0;	
}
