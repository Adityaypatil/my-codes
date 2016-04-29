#include<iostream>
using namespace std;

class student{
	private:
	  int roll_no;
	  string name;
	public:
	  student(int,string);
	  void display();
};

student::student(int roll,string n)
{
	  roll_no=roll;
	  name=n;
  
}

void student::display()
{
	  cout<<"Roll no:"<<roll_no<<"\tName:"<<name<<endl;
  
}

int main()
{
	  student s1(11,"sandesh");
	  s1.display();	
	  student s2=s1;
	  s2.display();
	  student s3(s2);
	  s3.display();
}
