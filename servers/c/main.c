#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#define PORT 8080 

void listenSocket();

int main(){
    listenSocket();
    return 0;
}

void listenSocket(){
    int server;
    int clientSocket;
    int data; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[1024] = {0};
       
    if ((server = socket(AF_INET, SOCK_STREAM, 0)) == 0){ 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 
       
    // Forcefully attaching socket to the port 8080 
    if (setsockopt(server, SOL_SOCKET, SO_KEEPALIVE | SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){ 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    }

    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons(PORT); 
       
    // Attach socket to port
    if (bind(server, (struct sockaddr *)&address, sizeof(address)) < 0){ 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    }

    // Listen on port
    if (listen(server, 3) < 0){ 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    }

    int keepRunning = 0;
    while(keepRunning == 0){

        // Accept connections
        if ((clientSocket = accept(server, (struct sockaddr *)&address,  (socklen_t*)&addrlen))<0){ 
            perror("accept"); 
            exit(EXIT_FAILURE); 
        }

        if(data = read(clientSocket, buffer, 1024) < 0){
            printf("Error reading socket data."); 
        }
        else{
            // Send data
            printf("%s", buffer); 
        }
    }
}
