//
//  data.c
//  webserver-C
//
//  Created by Guillermo Figueroa on 9/10/17.
//  Copyright © 2017 Guillermo Figueroa. All rights reserved.
//

#include "data.h"
#include <stdlib.h>
#include "simple_list.h"
#include <unistd.h>
#include <string.h>


int counter = 0;

simple_list* list;
time_t t;

connection* conn_arr;
int size_arr;

void initialize_data(){
    list = init_simple_list();
    t = time(NULL);
}

void add_connection(char* ip){
    connection* conn = malloc(sizeof(connection));
    conn -> ip = ip;
    conn -> date = malloc(40);
    memcpy(conn -> date, asctime(localtime(&t)), 40);
    printf("Added: %s", connection_str(*conn));
    
    add_element(list, conn);
}

void prepare_to_send(int amount){
    conn_arr = last_n_elements(list, amount, &size_arr);
}

connection* last_connections(int* size){
    *size = size_arr;
    return conn_arr;
}

void increment_counter(){
    counter++;
}

int get_counter(){
    return counter;
}

