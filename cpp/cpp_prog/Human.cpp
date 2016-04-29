#include<iostream>
#include<string>
using namespace std;
class Human{
	
		string *Name;
		int *age;
	public:
		Human(string *name,int *age)
		{
			name= new string;
			*name =name;
			*age = new int;
		}
		
		void disp()
		{
		cout <<"HI i am "<< name <<"and i am"<<age<<"years old";
		}	
		
		~Human()
		{
		delete name;
		delete age;
		cout<<"All memory are realsed"<<endl;
		}
};


int main()
{
	Human *adi=new Human("adi",23);
	adi->display();	
	return 0;
}
