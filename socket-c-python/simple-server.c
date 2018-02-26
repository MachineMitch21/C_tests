/* simple-server.c
 *
 * Copyright (c) 2000 Sean Walton and Macmillan Publishers.  Use may be in
 * whole or in part in accordance to the General Public License (GPL).
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
*/

/*****************************************************************************/
/*** simple-server.c                                                       ***/
/***                                                                       ***/
/*****************************************************************************/

/**************************************************************************
*	This is a simple echo server.  This demonstrates the steps to set up
*	a streaming server.
**************************************************************************/
#include <stdio.h>
#include <errno.h>
#include <memory.h>

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#pragma comment (lib, "ws2_32.lib")
#endif // _WIN32

#ifdef __unix__
#include <sys/socket.h>
#include <resolv.h>
#include <arpa/inet.h>
#endif // __unix__


#define DEFAULT_BUFLEN 	1024
#define DEFAULT_PORT 	"27015"
#define DEFAULT_IP 		"127.0.0.1"

int main(int argc, char** argv)
{
	printf("BMS Server\n\n");
	#ifdef __unix__

		int sockfd;
		struct sockaddr_in self;
		char buffer[MAXBUF];

		/*---Create streaming socket---*/
	    if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
		{
			perror("Socket");
			exit(errno);
		}

		/*---Initialize address/port structure---*/
		bzero(&self, sizeof(self));
		self.sin_family = AF_INET;
		self.sin_port = htons(MY_PORT);
		self.sin_addr.s_addr = INADDR_ANY;

		/*---Assign a port number to the socket---*/
	    if ( bind(sockfd, (struct sockaddr*)&self, sizeof(self)) != 0 )
		{
			perror("socket--bind");
			exit(errno);
		}

		/*---Make it a "listening socket"---*/
		if ( listen(sockfd, 20) != 0 )
		{
			perror("socket--listen");
			exit(errno);
		}

		/*---Forever... ---*/
		while (1)
		{	int clientfd;
			struct sockaddr_in client_addr;
			int addrlen=sizeof(client_addr);

			/*---accept a connection (creating a data pipe)---*/
			clientfd = accept(sockfd, (struct sockaddr*)&client_addr, &addrlen);
			printf("%s:%d connected\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

			/*---Echo back anything sent---*/
			send(clientfd, buffer, recv(clientfd, buffer, MAXBUF, 0), 0);

			/*---Close data connection---*/
			close(clientfd);
		}

		/*---Clean up (should never get here!)---*/
		close(sockfd);

	#endif // __unix__

	#ifdef _WIN32

		WSADATA wsaData;
	    int iResult;

	    SOCKET ListenSocket = INVALID_SOCKET;
	    SOCKET ClientSocket = INVALID_SOCKET;

	    struct addrinfo *result = NULL;
	    struct addrinfo hints;

	    int iSendResult;
	    char recvbuf[DEFAULT_BUFLEN];
	    int recvbuflen = DEFAULT_BUFLEN;

	    // Initialize Winsock
	    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
	    if (iResult != 0) {
	        printf("WSAStartup failed with error: %d\n", iResult);
	        return 1;
	    }

	    memset(&hints, 0, sizeof(hints));
	    hints.ai_family = AF_INET;
	    hints.ai_socktype = SOCK_STREAM;
	    hints.ai_protocol = IPPROTO_TCP;
	    hints.ai_flags = AI_PASSIVE;

	    // Resolve the server address and port
	    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
	    if ( iResult != 0 ) {
	        printf("getaddrinfo failed with error: %d\n", iResult);
	        WSACleanup();
	        return 1;
	    }

	    // Create a SOCKET for connecting to server
	    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	    if (ListenSocket == INVALID_SOCKET) {
	        printf("socket failed with error: %ld\n", WSAGetLastError());
	        freeaddrinfo(result);
	        WSACleanup();
	        return 1;
	    }

	    // Setup the TCP listening socket
	    iResult = bind( ListenSocket, result->ai_addr, (int)result->ai_addrlen);
	    if (iResult == SOCKET_ERROR) {
	        printf("bind failed with error: %d\n", WSAGetLastError());
	        freeaddrinfo(result);
	        closesocket(ListenSocket);
	        WSACleanup();
	        return 1;
	    }

	    freeaddrinfo(result);

	    iResult = listen(ListenSocket, SOMAXCONN);
	    if (iResult == SOCKET_ERROR) {
	        printf("listen failed with error: %d\n", WSAGetLastError());
	        closesocket(ListenSocket);
	        WSACleanup();
	        return 1;
	    }

	    // Receive until the peer shuts down the connection
	    while(1) {

			printf("Waiting for client connection...\n");

			// Accept a client socket
			ClientSocket = accept(ListenSocket, NULL, NULL);
			if (ClientSocket == INVALID_SOCKET) {
				printf("accept failed with error: %d\n", WSAGetLastError());
				closesocket(ListenSocket);
				WSACleanup();
				return 1;
			}

	        iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
	        if (iResult > 0) {
	            printf("Bytes received: %d\n", iResult);

				printf("%s\n", recvbuf);

	        // Echo the buffer back to the sender
				char* sendBuf = "Stop bothering me";
	            iSendResult = send( ClientSocket, sendBuf, strlen(sendBuf), 0 );
	            if (iSendResult == SOCKET_ERROR) {
	                printf("send failed with error: %d\n", WSAGetLastError());
	                closesocket(ClientSocket);
	                WSACleanup();
	                return 1;
	            }
	            printf("Bytes sent: %d\n", iSendResult);
	        }
	        else if (iResult == 0)
	            printf("Connection closing...\n");
	        else  {
	            printf("recv failed with error: %d\n", WSAGetLastError());
	            closesocket(ClientSocket);
	            WSACleanup();
	            return 1;
	        }

			closesocket(ClientSocket);
	    }

	    // shutdown the connection since we're done
	    iResult = shutdown(ClientSocket, SD_SEND);
	    if (iResult == SOCKET_ERROR) {
	        printf("shutdown failed with error: %d\n", WSAGetLastError());
	        closesocket(ClientSocket);
	        WSACleanup();
	        return 1;
	    }

	    // cleanup
	    closesocket(ClientSocket);
		closesocket(ListenSocket);
	    WSACleanup();

	#endif // _WIN32

	return 0;
}
