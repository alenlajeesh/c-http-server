#include <stdio.h>
#include <time.h>
#include <string.h>

#include "../include/logger.h"

void log_request(const char *method, const char *path, int status)
{
    FILE *log = fopen("logs/server.log", "a");

    if (!log)
        return;

    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    char time_str[64];

    strftime(time_str, sizeof(time_str),
             "%Y-%m-%d %H:%M:%S", t);

    fprintf(log, "[%s] %s %s %d\n",
            time_str, method, path, status);

    fclose(log);
}
