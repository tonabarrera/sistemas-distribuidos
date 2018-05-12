struct Operandos{
    int i;
    int j;
    double res;
};

program OPERACIONES_PROG {
    version OPERACIONES_VERS {
        struct Operandos SUMA(struct Operandos) = 1;
        struct Operandos PRODUCTO(struct Operandos) = 2;
        struct Operandos COCIENTE(struct Operandos) = 3;
    } = 1;
} = 0x31111111;