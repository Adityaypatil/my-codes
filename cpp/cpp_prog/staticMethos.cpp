#include<iostream>
using namespace std;

class student
{

  int roll_no;
  string name;
  int static count;
public:
  student()
  {
    count++;
  }
  student(int roll_no,string name)
  {
    this->roll_no=roll_no;
    this->name=name;
    count++;
  }
  static void Count()
  {
    cout<<"Object:"<<count<<endl;
  }
  void Display()
  {
    cout<<"Roll Nmber="<<roll_no<<endl;
    cout<<"Name="<<name<<endl;
    
  }
};
int student::count=0; 
int main()
{
  student s2;
  student::Count();
  s2.Display();
  student s1(100,"abc");
  student::Count();				
  s1.Display();	  
  
  
}
