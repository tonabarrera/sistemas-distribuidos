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
    int s, num[511], res;

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
    client_addr.sin_port = htons(6666);

    bind(s, (struct sockaddr *)&client_addr, sizeof(client_addr));

    num[0] = 2;
    num[1] = 5; /* rellena el mensaje */

    sendto(s, (char *)num, 511*sizeof(int), 0, (struct sockaddr *)&msg_to_server_addr, sizeof(msg_to_server_addr));

    /* se bloquea esperando respuesta */
    recvfrom(s, (char *)&res, sizeof(int), 0, NULL, NULL);
    memcpy(aux, &msg_to_server_addr.sin_addr.s_addr, 4);
    printf("IP: %d.%d.%d.%d\n", aux[0], aux[1], aux[2], aux[3]);
    printf("Puerto: %d\n", ntohs(msg_to_server_addr.sin_port));

    printf("2 + 5 = %d\n", res);
    for(int i = 0; i < 4; i++)
        printf("%d\n", aux[i]);

    close(s);

    return 0;
}
