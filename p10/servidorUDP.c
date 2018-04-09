#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>

int puerto = 7200;

int main(int argc, char const *argv[]) {
    int num[511];
    int s, res, clilen;
    struct sockaddr_in server_addr, msg_to_client_addr;
    
    s = socket(AF_INET, SOCK_DGRAM, 0);
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    printf("%d -> %x\n", puerto, puerto);
    server_addr.sin_port = htons(puerto);
    printf("%d -> %x\n", server_addr.sin_port, server_addr.sin_port);
    bind(s, (struct sockaddr *)&server_addr, sizeof(server_addr));
    clilen = sizeof(msg_to_client_addr);
    char aux[4];
    while (1) {
        recvfrom(s, (char *) num, 511*sizeof(int), 0, (struct sockaddr *) &msg_to_client_addr, &clilen);
        memcpy(aux, &msg_to_client_addr.sin_addr.s_addr, 4);
        printf("IP: %d.%d.%d.%d\n", aux[0], aux[1], aux[2], aux[3]);
        printf("Puerto: %d\n", ntohs(msg_to_client_addr.sin_port));
        res = num[0] + num[1];

        /* Envia la peticion al cliente. La estructura msg_to_client_addr contiene la direccion
        *  socket del cliente
        */
        sendto(s, (char *)&res, sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, clilen);
    }
    return 0;
}