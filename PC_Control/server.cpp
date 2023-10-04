#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>


int main(){
    // Create a server socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cout << "Error creating the server socket" << std::endl;
        return EXIT_FAILURE;
    }
    struct sockaddr_in serverAddress;

    // Set up the server's address information
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr= INADDR_ANY;

    // Bind the server socket to the specified address and port
    if(bind(serverSocket, (struct sockaddr*) &serverAddress, sizeof(serverAddress)) < 0){
        perror("bind");
        return EXIT_FAILURE;
    }

    // Start listening for incoming connections
    listen(serverSocket, 3);
    std::cout << "Server is listening on port: "<< ntohs(serverAddress.sin_port) << std::endl;

    // Create a buffer 
    char buffer[1024];

    while (true) {
        // Accept an incoming connection from client
        int client = accept(serverSocket, nullptr, nullptr);
        
        // Clear the buffer
        memset(buffer, 0, sizeof(buffer));
        
        // Read data from the client into the buffer
        int bytes = read(client, buffer, sizeof(buffer));      // error handling here
        
        // Print the received data
        std::cout << "Received: "<< buffer << std::endl;
        
        // Open terminal
        if(strcmp(buffer, "terminal") == 0){
            
            int result = execlp("gnome-terminal", "gnome-terminal",nullptr);

            // Check if execlp failed
            if(result == -1){
                perror("execlp");
                exit(EXIT_FAILURE);
            }

            // Send msg to the client
            const char* resultMsg = "Command executed successfully!\n";
            send(client, resultMsg, strlen(resultMsg), 0);
        }

        // Open calculator
        else if(strcmp(buffer, "calc") == 0){
            
            int result = execlp("gnome-calculator", "gnome-calculator",nullptr);

            // Check if execlp failed
            if(result == -1){
                perror("execlp");
                exit(EXIT_FAILURE);
            }

            // Send msg to the client
            const char* resultMsg = "Command executed successfully!\n";
            send(client, resultMsg, strlen(resultMsg), 0);
        }
        else
        {
            std::cout << "wrong command" << std::endl;
            close(client);
            exit(EXIT_FAILURE);
        }

        // Close the client socket
        close(client);
    }
    
    // Close the server socket
    close (serverSocket);


    return 0;
}