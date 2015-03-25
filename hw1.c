#include<stdio.h>
#include<stdlib.h>
//FILE *fp;
//fp = fopen("token.txt","w");

int identifier(int a,char data[],FILE *fp){
	int b,i;
	int key = 0;
	int out = 0;
	int length2 = 1;
//	int spec[33] ={0};
//    int spec[33] ={32,33,34,39,40,41,42,43,44,45,46,47,58,59,60,61,62,63,91,92,93,94,123,125};
	int spec[33];
	out = a;

	for(i = 0 ; i <= 15 ; i++){//32-47
        spec[i] = i + 32;
	}
	for(i = 16 ; i <= 22 ; i++){//58-64
        spec[i] = i + 42;
	}
	for(i = 23 ; i <= 28 ; i++){//91-96
        spec[i] = i + 68;
	}
	for(i = 29 ; i <= 32 ; i++){//123-126
        spec[i] = i + 94;
	}
	spec[27] = 32;//delete _

	for(b = out ; b < out+16 ; b++){
	    if(key != 1){
            for(i = 0 ; i < 33 ; i++){
                if(data[b] == spec[i]) {
                    length2 = b - out ;
                    key = 1;
                    break;
                }
            }
        }
	}

  /*      if(data[b] == ' ' || data[b] == '(' || data[b] == ';' || data[b] == '{' || data[b] == '=' || data[b] == '+' || data[b] == '<' || data[b] == '[' || data[b] == '!'){
            length2 = b - out ;
            break;
            }*/

        key = 0;
        fprintf(fp,"    <Identifier> : ");
        for(b = out ; b < length2 + out ; b++){
            fprintf(fp,"%c",data[b]);
        }
        fprintf(fp,"\n");
        out = out + length2;
        return out;
}

int main(){
    char data[100];
    char id[53] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','_'};
    char num[11] ={'0','1','2','3','4','5','6','7','8','9','0'};
    int a,i,b;
    int length=0,length2=0;
    int key = 0;
    int line = 0;
    FILE *fptr;
    fptr = fopen("main.c","r");//input file
    FILE *fp;
    fp = fopen("token.txt","w");//output file

    if(!fptr){
        printf("something wrong...");
        exit(1);
    }

	while (fgets(data, 100, fptr) != NULL) {
//	    printf("\n");
    for(a = 0 ; a < 100 ; a++){
        if(data[a] == '\0'){
            length = a;
            break;
        }
    }
    a = 0;


    while(a < length){

        for(i = 0 ; i < 53 ; i++){
            if(data[a] == id[i]){
                key = 1;
                break;
            }
        }

        for(i = 0 ; i < 11 ; i++){
            if(data[a] == num[i]){
                key = 2;
                break;
            }
        }

        if(key == 1 && data[a] =='i'){
            if(data[a+1] == 'n' && data[a+2] == 't' && data[a+3] == ' '){
                fprintf(fp,"    <Keyword> : %c%c%c\n",data[a],data[a+1],data[a+2]);
                a = a + 3;
            }
            else if(data[a+1] == 'f' && (data[a+2] == ' ' || data[a+2] == '(')){
                fprintf(fp,"    <Keyword> : %c%c\n",data[a],data[a+1]);
                a = a + 2;
            }
            else{
                a = identifier(a,data,fp);
            }
            }

        else if(key == 1 && data[a] == 'c'){
            if(data[a+1] == 'h' && data[a+2] == 'a' && data[a+3] == 'r' && data[a+4] == ' '){
                fprintf(fp,"    <Keyword> : %c%c%c%c\n",data[a],data[a+1],data[a+2],data[a+3]);
                a = a + 4;
            }

            else{
                a = identifier(a,data,fp);
            }
        }

        else if(key == 1 && data[a] == 'f'){
            if(data[a+1] == 'l' && data[a+2] == 'o' && data[a+3] == 'a' && data[a+4] == 't' && (data[a+5] == ' ' || data[a+5] == ')')){
                fprintf(fp,"    <Keyword> : %c%c%c%c%c\n",data[a],data[a+1],data[a+2],data[a+3],data[a+4]);
                a = a + 5;
            }
            else if(data[a+1] == 'o' && data[a+2] == 'r' && (data[a+3] == ' ' || data[a+3] == '(')){
                 fprintf(fp,"    <Keyword> : %c%c%c\n",data[a],data[a+1],data[a+2]);
                 a = a + 3;
                    }

            else{
                a = identifier(a,data,fp);
            }
        }

        else if(key == 1 && data[a] == 'd'){
            if(data[a+1] == 'o' && data[a+2] == 'u' && data[a+3] == 'b' && data[a+4] == 'l' && data[a+5] == 'e' && data[a+6] == ' '){
                fprintf(fp,"    <Keyword> : %c%c%c%c%c%c\n",data[a],data[a+1],data[a+2],data[a+3],data[a+4],data[a+5]);
                a = a + 6;
            }

            else{
                a = identifier(a,data,fp);
            }
        }

        else if(key == 1 && data[a] == 'r'){
            if(data[a+1] == 'e' && data[a+2] == 't' && data[a+3] == 'u' && data[a+4] == 'r' && data[a+5] == 'n' && data[a+6] == ' ' ){
                fprintf(fp,"    <Keyword> : %c%c%c%c%c%c\n",data[a],data[a+1],data[a+2],data[a+3],data[a+4],data[a+5]);
                a = a + 6;
            }
            else{
                a = identifier(a,data,fp);
            }
        }

        else if(key == 1 && data[a] == 'e'){
            if(data[a+1] == 'l' && data[a+2] == 's' && data[a+3] == 'e' && (data[a+4] == ' ' || data[a+4] == '{')){
                fprintf(fp,"    <Keyword> : %c%c%c%c\n",data[a],data[a+1],data[a+2],data[a+3]);
                a = a + 4;
            }
            else{
                a = identifier(a,data,fp);
            }
        }

        else if(key == 1 && data[a] == 'w'){
            if(data[a+1] == 'h' && data[a+2] == 'i' && data[a+3] == 'l' && data[a+4] == 'e' && (data[a+5] == ' ' || data[a+5] == '(')){
                fprintf(fp,"    <Keyword> : %c%c%c%c%c\n",data[a],data[a+1],data[a+2],data[a+3],data[a+4]);
                a = a + 5;
            }
            else{
                a = identifier(a,data,fp);
            }
        }

        else if(key == 1 && data[a] == 'b'){
            if(data[a+1] == 'r' && data[a+2] == 'e' && data[a+3] == 'a' && data[a+4] == 'k' && (data[a+5] == ' ' || data[a+5] == ';')){
                fprintf(fp,"    <Keyword> : %c%c%c%c%c\n",data[a],data[a+1],data[a+2],data[a+3],data[a+4]);
                a = a + 5;
            }
            else{
                a = identifier(a,data,fp);
            }
        }

        else if(key == 1 && data[a] == 'p'){
            if(data[a+1] == 'r' && data[a+2] == 'i' && data[a+3] == 'n' && data[a+4] == 't' && (data[a+5] == ' ') || (data[a+5] == '(')){
                fprintf(fp,"    <Keyword> : %c%c%c%c%c\n",data[a],data[a+1],data[a+2],data[a+3],data[a+4]);
                a = a + 5;
            }
            else{
                a = identifier(a,data,fp);
            }
        }

        else if(key == 1 && data[a] == 'f'){
            if(data[a+1] == 'o' && data[a+2] == 'r' && (data[a+3] == ' ' ) || data[a+3] == '('){
                fprintf(fp,"    <Keyword> : %c%c%c\n",data[a],data[a+1],data[a+2]);
                a = a + 3;
            }
            else{
                a = identifier(a,data,fp);
            }
        }

/*
        else if(key == 1){
                for(b = a ; b < a+16 ; b++){
                    if(data[b] == ' ' || data[b] == '(' || data[b] == ';' || data[b] == '{'){
                        length2 = b - a ;
                        break;
                    }
                }
                printf("<Identifier> : ");
                for(b = a ; b < length2 + a ; b++){
                    printf("%c",data[b]);
                }
                printf("\n");

            a = a + length2;
            }*/
        else if(key == 1){
            a = identifier(a,data,fp);

        }

        else if(data[a] == '/' && data[a+1] == '/'){
            a = length;
        }

        else if(data[a] == '(' || data[a] == ')' || data[a] == '[' || data[a] == ']'){
            fprintf(fp,"    <special> : %c\n",data[a]);
            a++;
        }

        else if(data[a] == ';' || data[a] == ',' || data[a] == '{' || data[a] == '}'){
            fprintf(fp,"    <special> : %c\n",data[a]);
            a++;
        }

        else if(data[a] == '+' || data[a] == '-' || data[a] == '*' || data[a] == '/'){
            fprintf(fp,"    <Operator> : %c\n",data[a]);
            a++;
        }

        else if((data[a] == '=' && data[a+1] != '=') || (data[a] == '!' && data[a+1] != '=') ){
            fprintf(fp,"    <Operator> : %c\n",data[a]);
            a++;
        }

        else if((data[a] == '=' && data[a+1] == '=') || (data[a] == '!' && data[a+1] == '=') ){
            fprintf(fp,"    <Operator> : %c%c\n",data[a],data[a+1]);
            a = a + 2;
        }

        else if((data[a] == '|' && data[a+1] == '|') || (data[a] == '&' && data[a+1] == '&') ){
            fprintf(fp,"    <Operator> : %c%c\n",data[a],data[a+1]);
            a = a + 2;
        }

        else if((data[a] == '>' && data[a+1] != '=') || (data[a] == '<' && data[a+1] != '=') ){
            fprintf(fp,"    <Operator> : %c\n",data[a]);
            a++;
        }

        else if((data[a] == '>' && data[a+1] == '=') || (data[a] == '<' && data[a+1] == '=') ){
            fprintf(fp,"    <Operator> : %c%c\n",data[a],data[a+1]);
            a = a + 2;
        }

        else if(key == 2){ //number , modify it later
            num[10] = '.';
            int ok = 0;//0:no error
            int last = 0;
            int c2 = 0;//counter
            int c[10] = {0};//counter
            for(b = 0 ; b < 11 ; b++){
                if(data[a+1] != num[b]){
                    c[0]++;
                }
                if(data[a+2] != num[b]){
                    c[1]++;
                }
                if(data[a+3] != num[b]){
                    c[2]++;
                }
                if(data[a+4] != num[b]){
                    c[3]++;
                }
                if(data[a+5] != num[b]){
                    c[4]++;
                }
                if(data[a+6] != num[b]){
                    c[5]++;
                }
                if(data[a+7] != num[b]){
                    c[6]++;
                }
                if(data[a+8] != num[b]){
                    c[7]++;
                }
                if(data[a+9] != num[b]){
                    c[8]++;
                }
                if(data[a+10] != num[b]){
                    c[9]++;
                }

            }
            if(c[0] == 11) length2 = 2;
            else if(c[1] == 11) length2 = 3;
            else if(c[2] == 11) length2 = 4;
            else if(c[3] == 11) length2 = 5;
            else if(c[4] == 11) length2 = 6;
            else if(c[5] == 11) length2 = 7;
            else if(c[6] == 11) length2 = 8;
            else if(c[7] == 11) length2 = 9;
            else if(c[8] == 11) length2 = 10;
            else if(c[9] == 11) length2 = 11;
            else length2 = 12;


            if(length2 >= 2 ){
                for(i = 0 ; i < 53 ; i++){
                    if(data[a+length2-1] == id[i]){
                    ok = 1;
                    break;
                    }
                }

            }
            for(i = a ; i < a + length2 -1; i++){
                if(data[i] == num[10]) c2++;
            }

            if(ok == 0 && c2 < 2){

                for(i = a ; i < a + length2 -1; i++){
                if(data[i] == num[10]) c2++;
            }


            fprintf(fp,"    <Number> : ");
            for(i = a ; i < a + length2 -1; i++){
                fprintf(fp,"%c",data[i]);
            }
            fprintf(fp,"\n");
            a = a + length2-1;
            }
            else {
                for(b = a ; i <= b + 16 ; b++){
                    if(data[b] == ' ' || data[b] == '(' || data[b] == ';' || data[b] == '{' || data[b] == '=' ){
                        last = b - a;
                        break;
                    }
                }
            fprintf(fp,"    <Error> : ");
            for(b = a ; b < last + a ; b++){
                    fprintf(fp,"%c",data[b]);
                }
                fprintf(fp,"\n");
            a = a + last;

            }
        ok = 0;
        last = 0;
        }

        else if(data[a] == ' '){
       //     printf("space\n");
            a++;
        }

        else if(data[a] == 39 && data[a+2] == 39){
            fprintf(fp,"    <Char> : %c",data[a+1]);
            a = a + 3;
            fprintf(fp,"\n");
        }

        else if(data[a] == 39 && data[a+3] == 39 && data[a+1] == 92 && (data[a+2] == 't' || data[a+2] == 'n')){
            fprintf(fp,"    <Char> : %c%c",data[a+1],data[a+2]);
            a = a + 4;
            fprintf(fp,"\n");
        }

        else if(data[a] == '\t'){
            a = a + 1;
        }

        else{
            a  = length;
        }

        key = 0;
        length2 = 0;

    }
        line++ ;
        fprintf(fp,"Line %d\n",line);

	}
	fclose(fptr);
	fclose(fp);
    return 0;
}

