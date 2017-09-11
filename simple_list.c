//
//  simple_list.c
//  webserver-C
//
//  Created by Guillermo Figueroa on 9/10/17.
//  Copyright © 2017 Guillermo Figueroa. All rights reserved.
//

#include "simple_list.h"
#include <stdlib.h>

#define MAX_SIZE_LIST 20

simple_list* init_simple_list(){
    simple_list* list = calloc(sizeof(simple_list),1);
    return list;
}

void add_element(simple_list* list, connection* conn){
    list_node* node = malloc(sizeof(list_node));
    node -> next = NULL;
    node -> conn = conn;
    
    if (!list -> head){
        list -> head = node;
        list -> tail = node;
    } else {
        list -> tail -> next = node;
        node -> previous = list -> tail;
        list -> tail = node;
    }
    list -> size++;
    if (list -> size > MAX_SIZE_LIST){
        //clean
    }
}

connection* last_n_elements(simple_list* list, int amount, int* size){
    if (!list || !list -> size){
        return NULL;
    }
    amount = amount <= list -> size ? amount : list -> size;
    *size = amount;
    connection* conn_arr = malloc(sizeof(connection)* amount);
    
    int i;
    list_node* node = list->tail;
    for (i = 0; i < amount; i++){
        conn_arr[i] = *node -> conn;
        node = node -> previous;
    }
    
    return conn_arr;
}

