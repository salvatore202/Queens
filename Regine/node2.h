/*
 * node2.h
 *
 *  Created on: 11 ott 2023
 *      Author: salva
 */

#ifndef NODE2_H_
#define NODE2_H_


#include<cstdlib>


namespace linked_list
{
	//NODE
	template <class item>
	class node
	{
	public:

		//TYPEDEF
		typedef item value_type;

		//CONSTRUCTOR
		node(const item& init_data=item(),node*init_link=NULL)
		{data_field= init_data; link_field=init_link;}


		//MODIFICATION MEMBER FUNCTION
		node* link(){return link_field;}
		void set_data (const item& new_data) {data_field = new_data;}
		void set_link( node* new_link) {link_field = new_link; }


		//CONST MEMBER FUNCTION
		const item& data() const {return data_field;}
		const node* link() const {return link_field;}


	private:
		item data_field;
		node* link_field;
	};



	//LINKED LIST TOOLKIT-WITH TEMPLATE
	template <class item>
	std::size_t list_length(const node<item>* head_ptr);

	template <class item>
	void list_head_insert(node<item>*& head_ptr, const item& entry);

	template <class item>
	void list_insert(node<item>* previous_ptr, const item& entry);

	template <class item>
	void list_tail_insert(node<item>*& head_ptr, node<item>*& tail_ptr, const item& entry);

	template <class item>
	node<item>* list_search(node<item>* head_ptr, const item& target);

	template  <class item>
	void list_head_remove(node<item>*& head_ptr);

	template  <class item>
	void list_clear(node<item>*& head_ptr);

	template  <class item>
	void list_copy(const node<item>* source_ptr, node<item>*& head_ptr, node<item>*& tail_ptr);

	template  <class item>
	void list_print_all(const node<item>* head_ptr);

	template <class item>
	node<item>* list_locate(node<item>* head_ptr, std::size_t position);
}

#include "node2_implementation.template"



#endif /* NODE2_H_ */
