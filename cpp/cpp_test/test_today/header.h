#ifndef HEADERS_H
#define HEADERS_H

class BankAccount{
	private: 
			int m_account_no;
			int m_cust_id;
			static int srno;
			float m_balance;
			char *m_name;

	public:
		BankAccount();
		BankAccount(int,float,char *);
		void DisplayAcInfo() const;
		void SetAcInfo(int,float,char*);
};
#endif
