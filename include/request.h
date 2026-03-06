#ifndef REQUEST_H
#define REQUEST_H

typedef struct{
	char method[8];
	char path[256];
	char version[16];
}HttpRequest;

void parse_http_request(char *buffer,HttpRequest *req);

#endif


