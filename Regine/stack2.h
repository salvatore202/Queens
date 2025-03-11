/*
 * stack2.h
 *
 *  Created on: 11 ott 2023
 *      Author: salva
 */

#ifndef STACK2_H_
#define STACK2_H_


#include "node2.h"

template <class item>
class stack
{

public:

	//TYPEDEF
	typedef std::size_t size_type;

	//CONSTRUCTOR AND DESTRUCTOR
	stack(){top_ptr = NULL;}
	stack( const stack<item>& source);  //copy constructor
	~stack() { linked_list::list_clear(top_ptr);}  //destructor

	//MODIFICATION MEMBER FUNCTION
	void push( const item& entry);
	void pop();
	void operator =( const stack<item>& source);

	//CONSTANT MEMEBER FUNCTION
	size_type size() const  { return linked_list::list_length(top_ptr); }
	bool empty() const { return (top_ptr == NULL); }
	item top() const;
	item seek(size_t n)const;
	const linked_list::node<item>* make_ptr(){return top_ptr;}

private:

	linked_list::node<item>* top_ptr;
};

#include "stack2_implementation.template"


#endif /* STACK2_H_ */
