#include "tcpListener.hpp"

        // initialise the listener
        // int tcplistener::init()
        // {
        //     // m_socket was before server_fd
        //     //m_port is PORT
        //     // struct sockaddr_in address;
    
        //     // Creating socket file descriptor
        //     if ((m_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
        //     {
        //         perror("In socket");
        //         // exit(EXIT_FAILURE);
        //         return (-1);
        //     }
        //     m_address.sin_family = AF_INET;
        //     m_address.sin_addr.s_addr = INADDR_ANY;
        //     m_address.sin_port = htons( m_port );
    
        //     memset(m_address.sin_zero, '\0', sizeof m_address.sin_zero);
    
    
        //     if (bind(m_socket, (struct sockaddr *)&m_address, sizeof(m_address))<0)
        //     {
        //         perror("In bind");
        //         // exit(EXIT_FAILURE);
        //         return (-1);
        //     }

        //     if (listen(m_socket, 10) < 0)
        //     {
        //         perror("In listen");
        //         // exit(EXIT_FAILURE);
        //         return (-1);
        //     }
        //     return (0);

        // }
        
        // run the listener
        // int tcplistener::run()
        // {
        //     int new_socket; long valread;
        //     int addrlen = sizeof(m_address);
        //     char hello[20] = "Hello from server";

        //     while(1)
        //     {
        //         printf("\n+++++++ Waiting for new connection ++++++++\n\n");
        //         if ((new_socket = accept(m_socket, (struct sockaddr *)&m_address, (socklen_t*)&addrlen))<0)
        //         {
        //             perror("In accept");
        //             exit(EXIT_FAILURE);
        //         }
        
        //         char buffer[30000] = {0};
        //         valread = read( new_socket , buffer, 30000);
        //         printf("%s\n",buffer );
        //         write(new_socket , hello , strlen(hello));
        //         printf("------------------Hello message sent-------------------\n");
        //         close(new_socket);
        //     }
        // }

