/*
 * stack1.h
 *
 *  Created on: 26 gen 2024
 *      Author: salva
 */

// FILE: stack1.h (part of the namespace main_savitch_7A)
// TEMPLATE CLASS PROVIDED: stack<Item>
//
// TEMPLATE PARAMETER, TYPEDEFS and MEMBER CONSTANTS for the stack<Item> class:
//   The template parameter, Item, is the data type of the items in the stack,
//   also defined as stack<Item>::value_type. It may be any of the C++ built-in
//   types (int, char, etc.), or a class with a default constructor, a copy
//   constructor, and an assignment operator. The definition
//   stack<Item>::size_type is the data type of any variable that keeps track of
//   how many items are in a stack. The static const CAPACITY is the
//   maximum capacity of a stack for this first stack implementation.
// NOTE:
//   Many compilers require the use of the new keyword typename before using
//   the expressions stack<Item>::value_type and stack<Item>::size_type.
//   Otherwise the compiler doesn't have enough information to realize that it
//   is the name of a data type.
//
// CONSTRUCTOR for the stack<Item> template class:
//   stack( )
//     Postcondition: The stack has been initialized as an empty stack.
//
// MODIFICATION MEMBER FUNCTIONS for the stack<Item> class:
//   void push(const Item& entry)
//     Precondition: size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been pushed onto the stack.
//
//   void pop( )
//     Precondition: size( ) > 0.
//     Postcondition: The top item of the stack has been removed.
//
// CONSTANT MEMBER FUNCTIONS for the stack<Item> class:
//   bool empty( ) const
//     Postcondition: Return value is true if the stack is empty.
//
//   size_type size( ) const
//     Postcondition: Return value is the total number of items in the stack.
//
//   Item top( ) const
//     Precondition: size( ) > 0.
//     Postcondition: The return value is the top item of the stack (but the
//     stack is unchanged. This differs slightly from the STL stack (where
//     the top function returns a reference to the item on top of the stack).
//
//  VALUE SEMANTICS for the stack<Item> class:
//     Assignments and the copy constructor may be used with stack<Item>
//     objects.
#ifndef STACK1_H_
#define STACK1_H_
#include <cstdlib>

namespace main_savitch_7A
{
	template <class Item>
	class stack
	{
	public:
		typedef Item value_type;
		typedef std::size_t size_type;
		static const size_type CAPACITY=30;
		stack(){ used=0; }
		//funzioni membro modifica
		void push(const Item& entry);
		void pop();
		//funzioni membro constanti
		bool empty() const {return (used==0);}
		size_type size() const {return used;}
		Item top ( ) const;
		Item seek(std::size_t n ) const;
	private:
		Item data[CAPACITY];
		size_type used;
	};
}
#include "stack1.template"
#endif /* STACK1_H_ */
