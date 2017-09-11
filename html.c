//
//  html.c
//  webserver-C
//
//  Created by Guillermo Figueroa on 9/9/17.
//  Copyright © 2017 Guillermo Figueroa. All rights reserved.
//

#include "html.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

#include "data.h"

/*
 * @brief Send text using a socket
 *
 * @param fd The socket that's going to send the information
 * @param text The text to be sent
 *
 */
ssize_t sendt(int fd, char* text) {
    return send(fd, text, strlen(text), 0);
}

void send_html_header(int socket_fd){
    sendt(socket_fd, "HTTP/1.1 200 OK\n");
    sendt(socket_fd, "Content-length: 46\n");
    sendt(socket_fd, "Content-Type: text/html\n\n");
}

char* text;
int i = 0;

void prepare(int amount){
    prepare_to_send(amount);
    int size;
    connection* conn_arr = last_connections(&size);
    
    text = calloc(600,1);
    int j;
    for (j = 0; j < size; j++){
        i+= snprintf(&text[i], 100, "<li>%s</li>", connection_str(conn_arr[j]));
    }
}

void* send_webpage(void* sock){
    int new_socket = *(int*)sock;
    send_html_header(new_socket);
    printf("%d\n", new_socket);
    sendt(new_socket, "<html><body><H1>Hello world</H1><ul><li>194</li><li>195</li><li>196</li></ul></body></html>");
//
//    sendt(new_socket, "<li>193</li>");
//    sendt(new_socket, "<li>193</li>");
//    sendt(new_socket, "<li>193</li>");
//    i = 0;
//    printf("%s\n", text);
//    sendt(new_socket, "</ul></body></html>");
    close(new_socket);
    exit(0);
}
