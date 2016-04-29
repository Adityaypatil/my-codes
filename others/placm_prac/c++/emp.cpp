#include<iostream>

using namespace std;

class emp
{
	public:	int no1,no2;
	public :int ans;
	void add()
	{
	ans=no1+no2;
	}
	void sub()
	{
	ans=no1-no2;
	}

};

int main()
{
	emp obj1,obj2;

	cout<<"Enter two values:"<<endl;
	cin >>obj1.no1;
	cin>>obj1.no2;
	cin >>obj2.no1;
	cin>>obj2.no2;

	obj1.add();
	cout<<"Addition is :"<<obj1.ans;

	obj2.sub();
	cout<<"sub is :"<<obj2.ans;
	return 0;

}

