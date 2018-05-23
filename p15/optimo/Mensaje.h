#ifndef __MENSAJE__
#define __MENSAJE__

#define TAM_MAX_DATA 4000

struct mensaje {
    int messageType;
    unsigned int requestId;
    char IP[16];
    int puerto;
    int operationId;
    char arguments[TAM_MAX_DATA];
};
#endif