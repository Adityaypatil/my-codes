#include"iostream"

using namespace std;

class human
{
	public:
		void disp();
	//	{
	//		cout<<"program is working !!!";	
	//	}

};

void human::disp()
{
	cout<<"program is working !!!";
}	


int main()
{
	human adi;
	adi.disp();	
	return 0;
}
