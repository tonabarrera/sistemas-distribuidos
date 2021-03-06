/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "operaciones.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

struct Operandos *
suma_1(struct Operandos *argp, CLIENT *clnt)
{
	static struct Operandos clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, SUMA,
		(xdrproc_t) xdr_Operandos, (caddr_t) argp,
		(xdrproc_t) xdr_Operandos, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

struct Operandos *
producto_1(struct Operandos *argp, CLIENT *clnt)
{
	static struct Operandos clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, PRODUCTO,
		(xdrproc_t) xdr_Operandos, (caddr_t) argp,
		(xdrproc_t) xdr_Operandos, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

struct Operandos *
cociente_1(struct Operandos *argp, CLIENT *clnt)
{
	static struct Operandos clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, COCIENTE,
		(xdrproc_t) xdr_Operandos, (caddr_t) argp,
		(xdrproc_t) xdr_Operandos, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}
