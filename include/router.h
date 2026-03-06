#ifndef ROUTER_H
#define ROUTER_H

void handle_route(int client_fd, const char *method, const char *path);
void send_text(int client_fd, const char *text);

#endif
