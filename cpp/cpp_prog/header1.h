#ifndef HEADERS_H
#define HEADERS_H
#include<iostream>
using namespace std;

class rectangle{
	private: float l,b;
			//static int count;
	public:	
	rectangle();	
  	rectangle(float ,float );
  	//Rectangle(const Rectangle &t);
 	float calc_area();
 	void Display(float);
  	//static void Count();  
  	//void Const_func() const;
  
};
#endif
