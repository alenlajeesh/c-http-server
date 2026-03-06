#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "../include/router.h"
#include "../include/response.h"
#include "../include/logger.h"

void send_text(int client_fd, const char *text)
{
    char response[512];

    snprintf(response, sizeof(response),
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/plain\r\n"
        "Connection: close\r\n"
        "\r\n"
        "%s",
        text);

    write(client_fd, response, strlen(response));
}

void handle_route(int client_fd, const char *method, const char *path)
{
    if (strcmp(path, "/api/hello") == 0)
    {
        send_text(client_fd, "Hello from C server!\n");
        log_request(method, path, 200);
        return;
    }

    if (strcmp(path, "/api/time") == 0)
    {
        time_t now = time(NULL);
        char *time_str = ctime(&now);

        send_text(client_fd, time_str);
        log_request(method, path, 200);
        return;
    }

    /* Not an API route → serve static file */
    send_file_response(client_fd, path);
}
