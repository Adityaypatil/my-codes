#include<iostream>
using namespace std;

class number
{
  int no;
  string name;
public:
  number(int no,string name)
  {
    this->no=no;
    this->name=name;
  }
  void Display() const
  {
    no=20;
    name="Patil";
    cout<<"No="<<no<<"Name="<<name<<endl;
  }
  
};
main()
{
  number n(10,"Aditya");
  n.Display();
  cout<<endl;
}
