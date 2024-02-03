/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _RPC_H_RPCGEN
#define _RPC_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct data {
	double a;
	struct {
		u_int y_len;
		int *y_val;
	} y;
	struct {
		u_int x_len;
		int *x_val;
	} x;
};
typedef struct data data;

struct d_ret {
	double a[2];
};
typedef struct d_ret d_ret;

struct var_array {
	struct {
		u_int j_len;
		double *j_val;
	} j;
};
typedef struct var_array var_array;

#define Service 0x24291294
#define Srv_1 1

#if defined(__STDC__) || defined(__cplusplus)
#define product 1
extern  int * product_1(struct data *, CLIENT *);
extern  int * product_1_svc(struct data *, struct svc_req *);
#define average 2
extern  struct d_ret * average_1(struct data *, CLIENT *);
extern  struct d_ret * average_1_svc(struct data *, struct svc_req *);
#define prod2 3
extern  struct var_array * prod2_1(struct data *, CLIENT *);
extern  struct var_array * prod2_1_svc(struct data *, struct svc_req *);
extern int service_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define product 1
extern  int * product_1();
extern  int * product_1_svc();
#define average 2
extern  struct d_ret * average_1();
extern  struct d_ret * average_1_svc();
#define prod2 3
extern  struct var_array * prod2_1();
extern  struct var_array * prod2_1_svc();
extern int service_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_data (XDR *, data*);
extern  bool_t xdr_d_ret (XDR *, d_ret*);
extern  bool_t xdr_var_array (XDR *, var_array*);

#else /* K&R C */
extern bool_t xdr_data ();
extern bool_t xdr_d_ret ();
extern bool_t xdr_var_array ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_RPC_H_RPCGEN */
