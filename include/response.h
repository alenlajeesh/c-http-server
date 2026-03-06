#ifndef RESPONSE_H
#define RESPONSE_H

void send_file_response(int client_fd, const char *path);
void send_404(int client_fd);

#endif
