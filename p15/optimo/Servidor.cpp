#include "SocketDatagrama.h"
#include "Mensaje.h"
#include "Respuesta.hpp"
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char*argv[]) {
    Respuesta respuesta(7200);

    while(true) {
        printf("%s\n", "ESPERANDO...");
        struct mensaje *msg = respuesta.getRequest();

        vector <char *> tokens;
        vector <char *> tokensReverse;
        char * pch;
        string cadenaInvertida;

        pch = strtok (msg->arguments," ");
        while (pch != NULL){
            tokens.push_back(pch);
            pch = strtok (NULL, " ");
        }
        std::vector<char *>::reverse_iterator rit = tokens.rbegin();
        for (; rit!= tokens.rend(); ++rit) {
            cadenaInvertida+=*rit;
            cadenaInvertida += " ";
        }
        respuesta.sendReply((char *)cadenaInvertida.c_str(), msg->IP, msg->puerto);
    }
}