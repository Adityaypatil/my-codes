#include<iostream>
#include<cstring>
using namespace std;

class stud{
	private: int rn;
			char n[10];
			int ns,*m;
	public:
		stud(int r,char *s,int sub)
		{
			rn=r;
			strcpy(n,s);
			ns=sub;
			m=new int[ns];
		}
	void getmarks()
	{
		for(int i=0;i<ns;i++)
		{
			cout<<"\nEnter marks:"<<i+1;
			cin>>m[i];
		}
	}
	void disp()
	{
		cout<<"\nRoll NO:"<<rn;
		cout<<"\nNmae:"<<n;
		for(int i=0;i<ns;i++)
		{
			cout<<"\nsubject:"<<i+1;
			cout<<m[i];
		}
	}
};

int main()
{
	stud s1(1,"Aditya",2);
	s1.getmarks();
	s1.disp();
	return 0;
}
