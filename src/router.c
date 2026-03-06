#include <stdio.h>
#include <string.h>
#include <time.h>

#include "../include/router.h"
#include "../include/response.h"
#include "../include/logger.h"

void handle_route(int client_fd, const char *method, const char *path)
{
    if (strcmp(path, "/api/hello") == 0)
    {
        send_text(client_fd, "Hello from C HTTP Server!\n");
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

    send_file_response(client_fd, path);
}
