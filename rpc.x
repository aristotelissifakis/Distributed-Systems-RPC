struct data {
    double a;
    int y<>;
    int x<>;
};

struct d_ret {
    double a[2];
};

struct var_array {
    double j<>;
};


program Service {
    version Srv_1 {
        int product(struct data) = 1;
        struct d_ret average(struct data) = 2;
        struct var_array prod2(struct data) = 3;
       
    } = 1;
} = 0x24291294;