#include "iostream"
#include"header.h"
using namespace std;

student::student()
{
	
	//++m_roll_no;
	/*m_name=new char[10];
	m_name=(char*)"ankush";
	m_course= new char[10];
	m_course= (char*)"cpp";
	m_per=70.90;*/
	
}

student::student(char * m_name,char * m_course, float m_per)
{
	++m_roll_no ;
	//this->m_roll_no=m_roll_no;
	this->m_name=m_name;
	this->m_course=m_course;
	this->m_per=m_per;
	
}

void student::display() const
{
	cout<<"Roll NO:"<<m_roll_no<<endl;
	cout<<"Name:"<<m_name<<endl;
	cout<<"Course:"<<m_course<<endl;
	cout<<"Per:"<<m_per<<endl;
	
}

int student :: m_roll_no =1000;
int main()
{
	student s2((char*)"aditya",(char*)"cpp",90.90);
	s2.display();
	student s3((char*)"ankush",(char*)"cpp",80.90);
	s3.display();
	student s4((char*)"a",(char*)"cpp",90.90);
		
	//s1.display();	
	
	
	s4.display();
	return 0;
}
