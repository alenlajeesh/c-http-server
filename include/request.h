#ifndef REQUEST_H
#define REQUEST_H

#define MAX_METHOD 8
#define MAX_PATH 256

typedef struct
{
    char method[MAX_METHOD];
    char path[MAX_PATH];
} HttpRequest;

void parse_http_request(const char *buffer, HttpRequest *request);

#endif
