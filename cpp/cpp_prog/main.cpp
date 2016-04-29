#include<iostream>
#include<string>
using namespace std;

class Human{
	private: 
		string *Name;
		int *age;
	public:
		Human(string *iname,int *iage)
		{
			name= new string;
			*name =iname;
			age = new int;
			*age=iage;
		}
		
		void display()
 		{
			cout <<"HI i am "<< *name <<"and i am"<<*age<<"years old";
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
