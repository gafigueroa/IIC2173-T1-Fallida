//
//  connection.c
//  webserver-C
//
//  Created by Guillermo Figueroa on 9/10/17.
//  Copyright © 2017 Guillermo Figueroa. All rights reserved.
//

#include "connection.h"
#include <stdlib.h>


char* connection_str(connection conn){
    char* str = calloc(60,1);
    snprintf(str, 60, "%s, %s", conn.ip, conn.date);
    return str;
}
