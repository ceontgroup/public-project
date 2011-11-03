// Class automatically generated by Dev-C++ New Class wizard

#ifndef NODE_H
#define NODE_H

// Author: Kem
class node
{	
	public:
		int item;
		node *next;
		static int count;
		int id;
		// class constructor
		node();
		node(const node &);
		// class destructor
		~node();
		int SetItem(int);
		int GetItem() const;
		node *GetNext(void) const; //Return next pointer 
		node *SetNext(node *); //Set value for next pointer
		void Print()const;
};

#endif // NODE_H