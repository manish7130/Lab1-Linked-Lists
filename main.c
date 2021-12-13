#include "list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int main(void){
	node_t* node_4 =  node_alloc();
	node_4 -> value = 6;
	node_4 -> next = NULL;

	node_t* node_3 = node_alloc();
	node_3 -> value = 3;
	node_3 -> next = node_4;
	
	node_t* node_2 =  node_alloc();
	node_3 -> value = 1;
	node_2 -> next = node_3;

	node_t* node_1 =  node_alloc();
	node_1 -> value = 7;
	node_1 -> next = node_2;
	
	list_t* llist =  list_alloc();
	llist -> head = node_1;
  
  list_print(llist);
	
	//contains
	printf("Contains : %d\n", list_is_in(llist, 0));
	printf("Contains : %d\n", list_is_in(llist, 7));
	printf("Contains : %d\n", list_is_in(llist, 1));
	printf("Contains : %d\n", list_is_in(llist, 6));

	//get_elem_at
	printf("This element at this index is: %d\n", list_get_elem_at(llist, 0));
	printf("This element at this index is: %d\n", list_get_elem_at(llist, 2));
	printf("This element at this index is: %d\n", list_get_elem_at(llist, 3));
	printf("This element at this index is: %d\n", list_get_elem_at(llist, 4));

	//get_index_of
	printf("This elem is at index: %d \n", list_get_index_of(llist, 7));
	printf("This elem is at index: %d \n", list_get_index_of(llist, 3));
	printf("This elem is at index: %d \n", list_get_index_of(llist, 121));
	
	//Add at index
	list_add_at_index(llist, 12, 1);
	list_add_at_index(llist, 126, 2);
	list_add_at_index(llist, 127, 5);
	list_add_at_index(llist, 127, 8);	
	list_print(llist);

	//Add to back
	list_add_to_back(llist, 100);
	list_add_to_back(llist, 199);

	//Add to front
	list_add_to_front(llist, 99);
	list_add_to_front(llist, 89);

	//Remove and length and print
	list_print(llist);
	printf("Length:%d\n", list_length(llist));
	printf("Removed %d\n", list_remove_at_index(llist, 3));
	list_print(llist);
	printf("Length:%d\n", list_length(llist));

	printf("Removed %d\n", list_remove_at_index(llist, 1));
	list_print(llist);
	printf("Length after remove:%d\n", list_length(llist));

	//Remove from back
	list_remove_from_back(llist);
	list_remove_from_back(llist);
	list_print(llist);

	//Remove from back
	list_remove_from_front(llist);
	list_remove_from_front(llist);
	list_print(llist); 

	list_free(llist);
	free(node_1);
	free(node_2);
	free(node_3);
	free(node_4);

	printf("solti");

	return 0;

	// printf("Points to Null? %p\n", node_4);
	// printf("here", node_4 -> next);
	// printf("Length of linked list is %d", list_length(llist));
}



