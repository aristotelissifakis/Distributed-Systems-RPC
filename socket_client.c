#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <ctype.h>

// Συνάρτηση ελέγχου συμβολοσειράς εάν είναι αριθμός
// opt 1 = Ακέραιος, opt 2 = Πραγματικός
int isNumber(char* str,int opt){
    int start = 0;
    int d_flag = 1;
    if(strlen(str) == 1)
        return 0;
    
    // Σε περίπτωση που είναι αρνητικός θα έχει το - απο μπροστά
    // έτσι το for θα ξεκινάει απο το δεύτερο χαρακτήρα να ελέγχει
    if (str[0] == '-')
        start = 1;
    
    for(int i=start;i<strlen(str)-1;i++){
        if(opt == 2){
            if((str[i] == '.') && d_flag && (i > 0) && (i<strlen(str))){ // Έλεγχος για τελεία δεξαδικού, αρκεί να μην έχει επαναληφθεί (d_flag) 
                d_flag = 0;                                              //και να μην είναι πρώτος ή τελευταίος χαρακτήρας (i>0 && i<strlen(str))
                continue;
            }
        }
        if(!isdigit(str[i]))
            return 0;
    }
    return 1;
}

int main(int argc,char** argv){

    srand(time(NULL));
            int result;
            int ch;
            int inner;
            double avg[2];
            double vec[5];
    int sockfd, portno, n, t, done;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char str[100];

    int x[5] = {5, 4, 3, 2, 1};
    int y[5] = {15, 2, 0, 1, 6};
    double r = 5.6;

    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        perror("ERROR opening socket");

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);

    printf("Trying to connect...\n");



    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
        perror("ERROR connecting");

        printf("Connected.\n");

       

        ch = 1;
            send(sockfd, x, 5*sizeof(int), 0);
            send(sockfd, y, 5*sizeof(int), 0);
            send(sockfd, &r, 1*sizeof(double), 0);
            send(sockfd, &ch, 1*sizeof(int), 0);
            switch (ch) {
                case 1:
                    result=recv(sockfd, &inner, 1*sizeof(int),0);
                    printf("Received the results from socket server\n");
                    printf("inner prod = %d\n", inner);
                    break;
                case 2:
                    recv(sockfd, avg, 2*sizeof(double), 0);
                    printf("avg[0] = %lf\navg[1] = %lf\n", avg[0], avg[1]);
                    break;
                case 3:
                    recv(sockfd, vec, 5*sizeof(double), 0);
                    for (int i = 0; i < 5; i++) {
                        printf("vec[%d] = %lf\n", i, vec[i]);
                    }
                    break;
            }

             close(sockfd);

    return 0;
}