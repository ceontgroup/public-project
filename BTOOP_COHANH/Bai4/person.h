// Class automatically generated by Dev-C++ New Class wizard

#ifndef PERSON_H
#define PERSON_H

/*
 * Author: Kem
 * Base class
 */
#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
class person
{
	protected:
		char name[30];
		char address[50];
		int age;
	public:
		// class constructor
		person(char *s1="",char *s2="",int=0);
		// class destructor
		~person();
		friend istream &operator>>(istream &,person &);
		friend ostream &operator<<(ostream &,const person &);
};

#endif // PERSON_H