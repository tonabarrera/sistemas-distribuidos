struct Operandos{
    int i;
    int j;
};

program OPERACIONES_PROG {
    version OPERACIONES_VERS {
        double SUMA(struct Operandos) = 1;
        double PRODUCTO(struct Operandos) = 2;
        double COCIENTE(struct Operandos) = 3;
    } = 1;
} = 0x31111111;