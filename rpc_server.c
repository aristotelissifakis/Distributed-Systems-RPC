/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "rpc.h"

int *
product_1_svc(struct data *argp, struct svc_req *rqstp)
{
    static int  result=0;

    
    for (int i = 0; i < argp->x.x_len; i++) {
        result += argp->x.x_val[i] * argp->y.y_val[i];
    }
    printf("Product1 rpc routine is called\n");
    

    return &result;
}

struct d_ret *
average_1_svc(struct data *argp, struct svc_req *rqstp)
{
    static struct d_ret  result;

    double sum_x = 0.0;
    double sum_y = 0.0;
    for (int i = 0; i < argp->x.x_len; i++) {
        sum_x += argp->x.x_val[i];
    }
    result.a[0] = sum_x / argp->x.x_len;

    for (int i = 0; i < argp->y.y_len; i++) {
        sum_y += argp->y.y_val[i];
    }
    result.a[1] = sum_y / argp->y.y_len;

    return &result;
}

struct var_array *
prod2_1_svc(struct data *argp, struct svc_req *rqstp)
{
    static struct var_array  result;
    result.j.j_val=(double*) malloc(result.j.j_len*sizeof(double));
    for (int i = 0; i < argp->x.x_len; i++) {
        result.j.j_val[i] = argp->a * (argp->x.x_val[i] + argp->y.y_val[i]);
    }

    return &result;
}