#include <stdio.h>
#include "../include/request.h"

void parse_http_request(const char *buffer, HttpRequest *request)
{
    if (!buffer || !request)
        return;
    sscanf(buffer, "%7s %255s", request->method, request->path);
}
