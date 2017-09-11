//
//  html.h
//  webserver-C
//
//  Created by Guillermo Figueroa on 9/9/17.
//  Copyright © 2017 Guillermo Figueroa. All rights reserved.
//

#ifndef html_h
#define html_h

#include <stdio.h>

void send_html_header(int socket_fd);

void* send_webpage(void* sock);

int get_counter();

void prepare(int amount);

void increment_counter();

#endif /* html_h */
