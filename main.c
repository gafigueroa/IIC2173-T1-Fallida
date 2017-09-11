//
//  main.c
//  webserver-C
//
//  Created by Guillermo Figueroa on 9/9/17.
//  Copyright © 2017 Guillermo Figueroa. All rights reserved.
//

#include <stdio.h>
#include "server.h"

#define PORT "8082"

int main(int argc, const char * argv[]) {
    
    init_server(PORT);
    
    return 0;
}


