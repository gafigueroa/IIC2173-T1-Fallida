//
//  simple_list.h
//  webserver-C
//
//  Created by Guillermo Figueroa on 9/10/17.
//  Copyright © 2017 Guillermo Figueroa. All rights reserved.
//

#ifndef simple_list_h
#define simple_list_h

#include <stdio.h>
#include "connection.h"

struct list_node{
    struct list_node* next;
    struct list_node* previous;
    connection* conn;
};
typedef struct list_node list_node;

struct simple_list{
    list_node* head;
    list_node* tail;
    int size;
};
typedef struct simple_list simple_list;

simple_list* init_simple_list();

void add_element(simple_list* list, connection* conn);

connection* last_n_elements(simple_list* list, int amount, int* size);



#endif /* simple_list_h */
