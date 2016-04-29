#include<iostream>
#include"header.h"


int main()
{
	BankAccount b1();
	BankAccount b2(1,1500.10,(char*)"Aditya");
	

	BankAccount b3(2,1669.90,(char *)"Manoj");
	
	
	BankAccount b4;
	
	b4.SetAcInfo(105,500.10,(char*)"Patil");
	
	b2.DisplayAcInfo();
	b3.DisplayAcInfo();
	b4.DisplayAcInfo();

	return 0;
}
