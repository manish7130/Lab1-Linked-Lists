#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

node_t* node_alloc(){
	return malloc(sizeof(node_t));
}

list_t* list_alloc(){
	return malloc(sizeof(list_t));
}

void list_free(list_t* l){
	free(l);
}

void list_print(list_t *l){
	node_t *curr = l -> head;
	while (curr){
		if (curr -> next){
			printf("%d -> ", curr -> value);
		}
		else{
			printf("%d\n", curr -> value);
		}
		curr = curr -> next; 
	}
}

/* Returns the length of the list. */
int list_length(list_t *l){
	int length =  0;

	node_t *curr = l -> head;
	while (curr){
		length ++;
		curr = curr -> next;
	}
	return length;
}

void list_add_to_back(list_t *l, elem value){
	list_add_at_index(l, value, list_length(l));
}

void list_add_to_front(list_t *l, elem value){
	list_add_at_index(l, value, 0);
}

void list_add_at_index(list_t *l, elem value, int index){
	if (index <= list_length(l) && index >= 0){
		if (l -> head){
			node_t *new_node = node_alloc();
			new_node -> value = value;
			// new_node -> 
			//changing the head node
			if (index == 0){
				node_t *curr_head = l -> head;
				l -> head = new_node;
				l -> head -> next = curr_head;
			}	
			else{	
				int my_index = 1;
				node_t *prev_node = l -> head;
				node_t *curr_node = l -> head -> next;
				while (prev_node){
					if (index == my_index){
						// curr_node -> next = l -> head;
						prev_node -> next = new_node;
						new_node -> next = curr_node;
						break;	
					} 
					prev_node = curr_node;
					curr_node = curr_node -> next;
					my_index ++;
				}
				// prev_node -> next = new_node;
			}
		}
	}
}

//Removes

elem list_remove_from_back(list_t *l){
	list_remove_at_index(l, list_length(l) - 1);
}

elem list_remove_from_front(list_t *l){
	list_remove_at_index(l, 0);
}

elem list_remove_at_index(list_t *l, int index){
	if (index < list_length(l) && index >= 0){
		if (l -> head){
			// new_node -> 
			//changing the head node
			if (index == 0){
				node_t *prev_head = l -> head;
				l -> head = l -> head -> next;
				return  prev_head -> value;
			}	
			else{	
				int my_index = 1;
				node_t *prev_node = l -> head;
				node_t *curr_node = l -> head -> next;
				while (prev_node){
					if (index == my_index){
						// curr_node -> next = l -> head;
						if (curr_node){
							int toRtn = curr_node -> value; 
							prev_node -> next = curr_node -> next;
							// new_node -> next = curr_node;
							return toRtn;	
						}
					} 
					prev_node = curr_node;
					curr_node = curr_node -> next;
					my_index ++;
				}
				// prev_node -> next = new_node;
			}
		}
	}

}

/* Checks to see if the given element exists in the list. */
bool list_is_in(list_t *l, elem value){
	if (l -> head){
		node_t *curr_node = l -> head;
		while (curr_node){
			if (curr_node -> value == value){
				return true;
			}
			curr_node = curr_node -> next;
		}return  false;
	}
	return  false;
}


elem list_get_elem_at(list_t *l, int index){
	if (l -> head){
		int my_counter = 0;
		node_t *curr_node = l -> head;
		while (curr_node){
			if (my_counter == index){
				return curr_node -> value;
			}
			curr_node = curr_node -> next;
			my_counter ++;
		}
	}
	return  -1;
}

elem list_get_index_of(list_t *l, elem value){
	if (l -> head){
		int my_counter = 0;
		node_t *curr_node = l -> head;
		while (curr_node){
			if (curr_node -> value == value){
				return my_counter;
			}
			curr_node = curr_node -> next;
			my_counter ++;
		}
	}
	return  -1;
}



// 7 -> 1

