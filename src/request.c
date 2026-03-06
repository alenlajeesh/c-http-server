#include <stdio.h>
#include <string.h>
#include "../include/request.h"

void parse_http_request(char *buffer, HttpRequest *req){
	sscanf(buffer,"%s %s %s",req->method,req->path,req->version);
}
