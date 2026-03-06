#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#include "../include/response.h"
#include "../include/logger.h"

#define BUFFER_SIZE 4096

void send_file_response(int client_fd, const char *path){

	if (strcmp(path, "/") == 0)
	{
		path = "/index.html";
	}

	char full_path[512];
	snprintf(full_path,sizeof(full_path),"public%s",path);

	int file_fd= open(full_path,O_RDONLY);

	if(file_fd<0){
		send_404(client_fd,path);
		return;
	}

	const char *content_type = get_content_type(path);

    char header[512];
    snprintf(header, sizeof(header),
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: %s\r\n"
        "\r\n",
        content_type);
	
    write(client_fd, header, strlen(header));
	
	char buffer[BUFFER_SIZE];
	int bytes;

	while((bytes=read(file_fd,buffer,BUFFER_SIZE))>0){
		write(client_fd,buffer,bytes);
	}
	close(file_fd);
	log_request("GET", path, 200);
	
}

void send_404(int client_fd,const char *path){
	char response[] =
        "HTTP/1.1 404 Not Found\r\n"
        "Content-Type: text/html\r\n"
        "\r\n"
        "<h1>404 Not Found</h1>";
	
	write(client_fd,response,strlen(response));
	log_request("GET", path, 404);
	
}

const char* get_content_type(const char *path){
    const char *ext = strrchr(path, '.');

    if (!ext) return "text/plain";

    if (strcmp(ext, ".html") == 0) return "text/html";
    if (strcmp(ext, ".css") == 0) return "text/css";
    if (strcmp(ext, ".js") == 0) return "application/javascript";
    if (strcmp(ext, ".png") == 0) return "image/png";
    if (strcmp(ext, ".jpg") == 0) return "image/jpeg";

    return "text/plain";
}
