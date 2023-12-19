#include <sys/socket.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/sendfile.h>

void checkBind(int result, int socket_file_descriptor) {
    if(result==-1) {
	perror("Error Binding Socket");
	close(socket_file_descriptor);
	exit(EXIT_FAILURE);
    }

void checkListen(int result, int socket_file_descriptor) {
    if(result==-1) {
	perror("Error Listening");
	close(socket_file_descriptor);
	exit(EXIT_FAILURE);
    }
    
int main(int argc, char *argv[]) {
    int sfd, cfd;
    
    //sockaddr struct to memset and set address family structure, port, ip address.
    struct sockaddr_in server_address, peer_address;
    socklen_t peer_address_size;

    //make an sfd and establish protocols and etc
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    
    memset(&server_address,0,sizeof(server_address));
    
    struct sockaddr_in server_address{
	.sin_family = AF_INET;
	.sin_port = htons(8080);
	.sin_addr.s_addr = INADDR_ANY,
    }
    //bind the socket to addr
    checkBind(bind(sfd, const (struct sockaddr *) &server_address, sizeof(server_address)),sfd);
    
    //listen for connections.
    checkListen(listen(sfd, 10), sfd); 

    //accept all incoming connections one at a time
    peer_address_size = sizeof(struct sockaddr_in);
    cfd = accept(sfd,0,0);

    char buffer[256] = {0};
    recv(client_fd, buffer, 256, 0);
    
    //HTTP handling requests and etc code here. GET /file.html.... 

    //establish a char pointer for buffer reading files
    char* file_ptr = buffer + 5;
    *strchr(file_ptr, ' ') = 0;
    
    //
    opened_fd = open(file_ptr, O_RDONLY);
    sendfile(client_fd, opened_fd, 0, 256);
    
    //close all file descriptors
    close(opened_fd);
    close(client_fd);
    close(sfd);
    
    

}   
