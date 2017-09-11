//
//  data.h
//  webserver-C
//
//  Created by Guillermo Figueroa on 9/10/17.
//  Copyright © 2017 Guillermo Figueroa. All rights reserved.
//

#ifndef data_h
#define data_h

#include <stdio.h>
#include "connection.h"


void initialize_data();

void add_connection(char* ip);

void prepare_to_send(int amount);

connection* last_connections(int* size);

void increment_counter();

int get_counter();

#endif /* data_h */
