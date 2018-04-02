#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>

int puerto = 7200;

int main(int argc, char const *argv[]) {
    int num[2];
    int s, res, clilen;
    struct sockaddr_in server_addr, msg_to_client_addr;
    
    s = socket(AF_INET, SOCK_DGRAM, 0);
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(puerto);

    bind(s, (struct sockaddr *)&server_addr, sizeof(server_addr));
    clilen = sizeof(msg_to_client_addr);

    while (1) {
        recvfrom(s, (char *) num, 2*sizeof(int), 0, (struct sockaddr *) &msg_to_client_addr, &clilen);
        res = num[0] + num[1];

        /* Envia la peticion al cliente. La estructura msg_to_client_addr contiene la direccion
        *  socket del cliente
        */
        sendto(s, (char *)&res, sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, clilen);
    }
    return 0;
}