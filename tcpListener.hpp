#ifndef TCPLISTENER_HPP
# define TCPLISTENER_HPP

#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
// #include <cstdio>
// #include <sstream>

class tcplistener {
    public:
        tcplistener(int port) : m_port(port) {}
        
        // initialise the listener
        int init()
        {
            // m_socket was before server_fd
            //m_port is PORT
            // struct sockaddr_in address;
    
            // Creating socket file descriptor
            if ((m_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
            {
                perror("In socket");
                // exit(EXIT_FAILURE);
                return (-1);
            }
            m_address.sin_family = AF_INET;
            m_address.sin_addr.s_addr = INADDR_ANY;
            m_address.sin_port = htons( m_port );
    
            memset(m_address.sin_zero, '\0', sizeof m_address.sin_zero);
    
    
            if (bind(m_socket, (struct sockaddr *)&m_address, sizeof(m_address))<0)
            {
                perror("In bind");
                // exit(EXIT_FAILURE);
                return (-1);
            }

            if (listen(m_socket, 10) < 0)
            {
                perror("In listen");
                // exit(EXIT_FAILURE);
                return (-1);
            }
            return (0);

        }
        
        // run the listener
        int run()
        {
            int new_socket; long valread;
            int addrlen = sizeof(m_address);
            char hello[20] = "Hello from server";

            while(1)
            {
                printf("\n+++++++ Waiting for new connection ++++++++\n\n");
                if ((new_socket = accept(m_socket, (struct sockaddr *)&m_address, (socklen_t*)&addrlen))<0)
                {
                    perror("In accept");
                    exit(EXIT_FAILURE);
                }
        
                char buffer[30000] = {0};
                valread = read( new_socket , buffer, 30000);
                printf("%s\n",buffer );
                write(new_socket , hello , strlen(hello));
                printf("------------------Hello message sent-------------------\n");
                close(new_socket);
            }
        }

    protected:

private:

	// const char*		m_ipAddress;	// IP Address server will run on
	int				m_port;			// Port # for the web service
	int				m_socket;		// Internal FD for the listening socket
    struct sockaddr_in m_address;
	// fd_set			m_master;		// Master file descriptor set
};


#endif
