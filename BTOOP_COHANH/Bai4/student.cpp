// Class automatically generated by Dev-C++ New Class wizard

#include "student.h" // class's header file

// class constructor
student::student(char *s1,char *s2,int age,char *s3):person(s1,s2,age)
{
	strcpy(className,s3);
}

// class destructor
student::~student()
{
	// insert your code here
}
istream &operator>>(istream &is,student &obj){
	is>>static_cast<person &>(obj);
	cout<<"Class name: ";
	is.getline(obj.className,6);
	fflush(stdin);	
	return is;
	};
ostream &operator<<(ostream &os,const student &obj){
	os<<(person &)obj<<endl<<"Class name: "<<obj.className;
	return os;
	};