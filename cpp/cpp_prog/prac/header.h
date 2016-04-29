#ifndef STUDENT 
#define STUDENT

class student{
	private:
		static int  m_roll_no;
		char *m_name;
		char *m_course;
		float m_per;
	public:	
			student();
			student(char *,char *,float);
			void display()const;
	//		student(const student &obj);
};

#endif
