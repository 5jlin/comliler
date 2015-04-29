#include <stdio.h>
#include<stdlib.h>
#include<string.h>
void findFirst();
int main(){
    findFirst();

    return 0;

}

void findFirst(){
    FILE *fptr;
    fptr = fopen("grammar.txt","r");
    char data[35];
    char grammer[100][35] ;
    int i=0,j=0;
    int c=1;
    int a;
    int stop = 0;
    int test[100] = {0};
    int firstlist[94] = {0};

    for(i=0;i<100;i++){
        for(j=0;j<35;j++){
            grammer[i][j] = 32;
        }
    }

    if(!fptr){
        printf("something wrong...");
        exit(1);
    }
    i=0;

    while (fgets(data, 35, fptr) != NULL  ) {
        for(j=0;j<strlen(data);j++){
            grammer[i][j] = data[j];
        }
        i++;
        }

    for(i=0;i<100;i++){
        if(grammer[i][0] == '\t')
            test[i] = -1;
    }


    for(i=0;i<94;i++){
        if(test[i] != -1 ){
            firstlist[i] = c;
            c++;
        }
    }
    c--;
    for(i=0;i<94;i++){
            if(test[i] == -1 ){
                if(test[i-1] != '\t'){
                    firstlist[i] = firstlist[i-1];
                }
                else if (test[i-2] != '\t'){
                    firstlist[i] = firstlist[i-2];
                }
            }
    }

    for(j=0;j<35;j++){
        printf("%d ",grammer[0][j]);
    }
printf("\n");
    for(i=94;i>=0;i--){
        if(test[i] != -1 && firstlist[i] == c){
            for(j=0;j<35;j++){
                if(grammer[i][j] != 10)
                    printf("%c",grammer[i][j]);
                else
                    break;
            }
            printf(":");
            for(a=i+1;a<i+15;a++){
                if(grammer[a][0] != '\t')
                    a = a+15;
                else{
                for(j=0;j<35;j++){
                    if(grammer[a][j] != 10 && grammer[a][j] != 32)
                        printf("%c",grammer[a][j]);
                    else
                    break;

                }
            }
            }
printf("\n");
        c--;
        }
    }
printf("\n");
    for(i=0;i<94;i++){
        printf("%d ",firstlist[i]);
    }

 /*   for(i=0;i<100;i++){
        for(j=0;j<35;j++){
            printf("%c",grammer[i][j]);
        }
        printf("\n");
    }*/


}
