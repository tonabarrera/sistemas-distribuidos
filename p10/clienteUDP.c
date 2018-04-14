#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

int puerto = 7200;

int main(int argc, char const *argv[]){
    struct sockaddr_in msg_to_server_addr, client_addr;
    int s, num[2], res;

    s = socket(AF_INET, SOCK_DGRAM, 0);
    /* rellena la direccion del servidor */
    bzero((char *)&msg_to_server_addr, sizeof(msg_to_server_addr));
    msg_to_server_addr.sin_family = AF_INET;
    msg_to_server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    char aux[4];
    msg_to_server_addr.sin_port = htons(puerto);

    /* rellena la direccion del cliente*/
    bzero((char *)&client_addr, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = INADDR_ANY;

    /* cuando se utiliza por numero de puerto el 0, el sistema se encarga de asignarle uno */
    client_addr.sin_port = htons(6665);

    bind(s, (struct sockaddr *)&client_addr, sizeof(client_addr));

    num[0] = 254;
    num[1] = 90; /* rellena el mensaje */
    printf("Mi puerto %d\n", ntohs(client_addr.sin_port));
    sendto(s, (char *)num, 2*sizeof(int), 0, (struct sockaddr *)&msg_to_server_addr, sizeof(msg_to_server_addr));

    /* se bloquea esperando respuesta */
    
    recvfrom(s, (char *)&res, sizeof(int), 0, NULL, NULL);
    memcpy(aux, &msg_to_server_addr.sin_addr.s_addr, 4);
    printf("IP: %d.%d.%d.%d\n", aux[0], aux[1], aux[2], aux[3]);
    printf("Puerto: %d\n", ntohs(msg_to_server_addr.sin_port));
    printf("%d + %d = %d\n",num[0], num[1], res);
    //for(int i = 0; i < 4; i++)
    //    printf("%d\n", aux[i]);

    close(s);

    return 0;
}
