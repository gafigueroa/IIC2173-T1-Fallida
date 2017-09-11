//
//  connection.h
//  webserver-C
//
//  Created by Guillermo Figueroa on 9/10/17.
//  Copyright © 2017 Guillermo Figueroa. All rights reserved.
//

#ifndef connection_h
#define connection_h

#include <stdio.h>
#include <time.h>


struct connection{
    char* ip;
    char* date;
};
typedef struct connection connection;

char* connection_str(connection conn);


#endif /* connection_h */
