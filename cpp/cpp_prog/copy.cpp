#include<iostream>
using namespace std;

class coppy{
	private : int v1,v2,v3;
	
	public :
			coppy()
			{
				v1=100;
				v2=200;
				v3=300;
			}		
			coppy(const coppy &c)
			{
				v1=c.v1;
				v2=c.v2;
				v3=c.v3;
			}			
		
		void disp()
		{
			cout<<"Value 1 :"<<v1;
			cout<<"\nValue 2 :"<<v2;
			cout<<"\nValue 3 :"<<v3;
		}
};

int main()
{
	coppy c1;
//	c1.disp();
	
	coppy c2(c1);
//	c2.disp();
	
	coppy c3=c1;
//	c3.disp();

	c1.disp();
	c2.disp();
	c3.disp();
	return 0;
}
