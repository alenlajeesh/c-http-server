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
    struct tm *tm_info = localtime(&now);

    char time_str[32];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", tm_info);

    fprintf(log, "[%s] %s %s %d\n", time_str, method, path, status);

    fclose(log);
    printf("[%s] %s %s %d\n", time_str, method, path, status);
}
