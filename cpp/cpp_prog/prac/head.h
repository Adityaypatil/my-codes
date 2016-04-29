#ifndef STUDENT 
#define STUDENT

class student{
		friend void print(student s5,student s6);
	private:
		static int  m_roll_no;
		char *m_name;
		char *m_course;
		float m_per;
	public:	
			student();
			student(char *,char *,float);
			void display()const;
			student(const student &);
	
			
};

#endif
