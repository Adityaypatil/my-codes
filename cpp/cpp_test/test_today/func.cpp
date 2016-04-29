#include<iostream>
#include"header.h"
#include<string.h>
using namespace std;

int BankAccount :: srno=0;

BankAccount::BankAccount()
{
	++srno;
	m_cust_id=srno;
	m_account_no=0;
	m_balance=0;
}

BankAccount::BankAccount(int account_no,float balance,char *name)
{
	++srno;
	m_cust_id=srno;
	m_account_no=account_no;
	m_balance=balance;	
	m_name=name;
}


void BankAccount::SetAcInfo(int account,float bal,char *name)
{
	//cout<<"In SetAcINfo Function"<<endl;
	m_account_no=account;
	
	m_balance=bal;
	//m_name=new char[strlen(name)];
	m_name=name;
}

void BankAccount::DisplayAcInfo() const
{
	cout<<"Account No:"<<m_account_no<<endl;		
	cout<<"Customer Id:"<<m_cust_id<<endl;
	cout<<"Balance:"<<m_balance<<endl;
//	cout<<"Name of Customer:"<<m_name<<endl;
}
