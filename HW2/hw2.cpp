#include<iostream>
#include<fstream>
#include <string>
#include <vector>
using namespace std;
void findFirst();
void findFollow();
void LLtable();
void convert();
char line[40];
string grammar[94][20];
string first[40][30];
string follow[40][30]={};
int list[28] ={0};
string lltable[300][4] = {""};

struct Tree
{
   int index;
   string value;
};

class Stack
{
      private:
              int top;
              int size;
              Tree *array;
      public:
             Stack(int s)
             {
                 size=s;
                 array=new Tree[s];
                 top=0;
             }

             void push(Tree item)
             {
                  if(top==size)
                      cout<<"Stack is full!"<<endl;
                  else
                      *(array+top)=item;
                      top++;
             }
             Tree pop()
             {
                 if(top==0)
                     cout<<"Stack is empty!"<<endl;
                 else
                 {
                     Tree item;
                     top--;
                     item=*(array+top);
                     return item;
                 }
             }
};

int main(){
    findFirst();
    findFollow();
    LLtable();
    convert();
 /*   string s = "abcde";
    string sub_str;
    sub_str.assign(s,1,3);
    cout << sub_str;*/
    return 0;
}

void findFirst(){
    fstream fin;
    fin.open("grammar.txt",ios::in);
    fstream fw;
    fw.open("set2.txt",ios::out);
    int row = 0;
    int col = 0;
    int check = 0;
    int space=0;
    string str ="";
    string sub_str;
    vector<string> aStr;
    for(int i=0;i<94;i++){
        for(int j=0;j<20;j++){
            grammar[i][j] = "";
        }
    }

    while (getline(fin, str,'\n')){
  //  aStr.push_back(str);//str :a line
    if(str[0] == '\t'){
        sub_str = '\t';
        grammar[row][col] = sub_str;
        col++;
        space = 1;
        for(int j=1;j<=str.size();j++){
            if(str[j] == ' ' || str[j] == '\0'){
                sub_str = "";
                for(int k = space;k < j;k++){
                    sub_str += str[k];
                }
            //    sub_str.assign(str,space,j-1);
                grammar[row][col] = sub_str;
                col++;
                space = j+1;
                check = 1;
            }
        }
    }
    else{
        space = 0;
        for(int j=0;j<=str.size();j++){
            if(str[j] == ' ' || str[j] == '\0'){
                sub_str = "";
                sub_str.assign(str,space,j);
           //     cout<<sub_str ;
                grammar[row][col] = sub_str;
                col++;
                space = j+1;
                check = 1;
            }
        }
    }

space = 0;
check = 0;
    row++;
    col = 0;
    }

    fin.close();
    cout  << endl;
   /* for(int i=0;i<94;i++){
        for(int j=0;j<20;j++){
            cout << " "<</*i << " " << j << " " << *//*grammar[i][j] ;
        }
        cout  << endl;
    }*/
    row = 0;
    check = 0;
    str = "";
    for(int i=0;i<94;i++){
            str = grammar[i][0];
         //   cout << str << endl;
            if(str[0] == '\t' ){
                check = 1;
            }
            if(check == 0 ){
                first[row][0] = grammar[i][0];
                follow[row][0] = grammar[i][0];
                row++;
             }
             check = 0;
    }
    str = "";
    check = 0;
 //   int list[28] ={0};
    col = 1;
    row = 0;
    int no = 0;
    for(int i=0;i<94;i++){
        for(int j=0;j<28;j++){
            if(grammar[i][0] == first[j][0]  ){
                list[j] = i;
            }
        }
    }

        list[27] = 94;
    /*    for(int j=0;j<28;j++){
            cout << list[j] << " ";
        }*/

        int c = 0;
        int c2 = 0;
        for(int i=0;i<28;i++){
            c = list[i];
            c2 = list[i+1];
      //      cout << c << " " << c2 << endl;
            for(int j=c+1;j<c2;j++){
                str = grammar[j][1];
                if(str[0] < 65 ||  str[0] > 90){
                    first[row][col] = grammar[j][1];
                    col++;
                }

            }
            col = 1;
            row++;
            check = 0;
        }

        int len = 0;
        int len2 = 0;
        c = 26;
        row = 1;

        for(int i=93;i>=0;i--){
            str = grammar[i][0] ;
            if(str[0] >= 65 && str[0] <= 90){
                c--;
            }
            if(str[0] == '\t'){
                sub_str = grammar[i][1] ;
                for(int j=0;j<28;j++){
                    if(grammar[i][1] == first[j][0]){
                        for(int m=1;m<30;m++){
                            if(first[j][m] == ""){
                                len = m ;
                                break;
                            }
                        }
                        for(int m=1;m<30;m++){
                            if(first[c][m] == ""){
                                len2 = m - 1 ;
                                break;
                            }
                        }
                        for(int m=1;m<len;m++){
                            first[c][len2+m] = first[j][m];
                        }

                    }
                }
            }
            }
//------------------
    c = 26;
        row = 1;
        for(int i=93;i>=0;i--){
            str = grammar[i][0] ;
            if(str[0] >= 65 && str[0] <= 90){
                c--;
            }
            if(str[0] == '\t'){
                sub_str = grammar[i][1] ;
                for(int j=0;j<28;j++){
                    if(grammar[i][1] == first[j][0] ){
                    //    cout << grammar[i][1] << " ";
                        for(int m=1;m<30;m++){
                            if(first[j][m] == ""){
                                len = m ;
                                break;
                            }
                        }
                        for(int m=1;m<30;m++){
                            if(first[c][m] == ""){
                                len2 = m - 1 ;
                                break;
                            }
                        }
                        for(int m=1;m<len;m++){
                            first[c][len2+m] = first[j][m];
                        }

                    }
                }
            }
            }
        for(int i=0;i<30;i++){
            for(int j=1;j<30;j++){
                str = first[i][j];
                for(int k=j+1;k<30;k++){
                    if(first[i][k] == str){
                        first[i][k] = "";
                    }
                }
            }
        }
first[16][0] = "StmtList'" ;
first[21][0] = "Expr'";
//------------

    for(int i=0;i<40;i++){
        for(int j=0;j<30;j++){
     //       cout << " " << first[i][j] ;
            fw << first[i][j] << " ";
        }
   //     cout  << endl;
        fw << endl;
    }
    fw.close();
}

void findFollow(){
    int row = 0;
    int col = 1;
    int check = 0;
    string str = "";
    string str2 = "";
    string str3,str4 = "";
    int c1,c2,c3;
    int len,len2,len3;

    follow[0][1] = "$";


    for(int i=0;i<93;i++){
        str = grammar[i][0];
        if(str[0] == '\t'){
            col = 1;
            while(col <= 30){
            str = grammar[i][col] ;      //str follow = str2 first
            str2 = grammar[i][col+1] ;
            if(str[0] >= 65 && str[0] <= 90 && str2[0] >= 65 && str2[0] <= 90){ //str's follow = str2' first
                cout << str<<" "<<str2<<endl;
                for(int j=0;j<28;j++){
                    if(str == follow[j][0]){
                        c1 = j;
                        break;
                    }
                }
                for(int j=0;j<28;j++){
                    if(str2 == follow[j][0]){
                        c2 = j;
                        break;
                    }
                }
                for(int j=1;j<5;j++){
                    str3 = grammar[i-j][0];
                    if(str3[0] != '\t'){
                        break;
                    }

                }


                for(int j=0;j<28;j++){
                    if(str3 == follow[j][0]){
                        c3 = j;
                        break;
                    }
                }
                for(int m=1;m<30;m++){
                            if(follow[c1][m] == ""){
                                len = m - 1 ;
                                break;
                            }
                        }
                        for(int m=1;m<30;m++){
                            if(first[c2][m] == ""){
                                len2 = m - 1 ;
                                break;
                            }
                        }
                        for(int m=1;m<30;m++){
                            if(follow[c3][m] == ""){
                                len3 = m -1;
                                break;
                            }
                        }

                        for(int m=1;m<=len2;m++){

                            if(first[c2][m] == "epsilon"){
//cout << len3<<endl;
                                for(int n=1;n<=len3;n++){
                                    //follow[c1][len+m] = follow[c1][len+m]+follow[c3][m] + " ";
                                    follow[c1][len+m] = follow[c1][len+m]+follow[c3][n] ;
//cout<< "asdfghj"<<endl;
                                }
                            }
                         else follow[c1][len+m] = first[c2][m];


                        }


                col ++;
            }
             if(str[0] >= 65 && str[0] <= 90 && (str2[0] < 65 || str2[0] > 90) && str2 != ""){
                for(int j=0;j<28;j++){
                    if(str == follow[j][0]){
                        c1 = j;
                        break;
                    }
                }
                for(int m=1;m<30;m++){
                            if(follow[c1][m] == ""){
                                len = m ;
                                break;
                            }
                        }
                follow[c1][len] = str2;

            col ++;
            }


            else col ++;
            }
        }



    }
    for(int i=0;i<83;i++){//avoid over
            str = grammar[i][0];
                if(str[0] != '\t'){

                    for(int j = 1 ; j < 7 ; j++){
                        str2 = grammar[i+j][0];
                        len = 0;
                        if(str2[0] == '\t'){

                            for(int k = 1 ; k < 10 ; k++){
                            str3 = grammar[i+j][k];
//cout << str3 << str3[0]<< endl;
//printf("%d \n",str3[0]);
                            if(str3[0] == 0){

                                len = k-1;
                                break;
                            }
                        }
                        str3 = grammar[i+j][len] ;
                  //      cout << i << " " << j << " " <<len<<" "<< str3 <<endl;
                        if(str3[0] >= 65 && str3[0] <= 90){
                            for(int k=0;k<28;k++){
                                if(str3 == follow[k][0]){
                                    c1 = k;
                                    break;
                                }
                            }
                            for(int k=0;k<28;k++){
                                if(str == follow[k][0]){
                                    c2 = k;
                                    break;
                                }
                            }
                        }
                        for(int m=1;m<30;m++){
                            if(follow[c1][m] == ""){
                                len3 = m ;
                                break;
                            }
                        }
                        for(int m=1;m<30;m++){
                            if(follow[c2][m] == ""){
                                len2 = m - 1;
                                break;
                            }
                        }
                     //   cout << c1 <<" " << c2<<" "<<len2<<" "<<len3<<endl;


                        for(int m=1;m<=len2;m++){
                            follow[c1][len3+m] = follow[c2][m];
                        }

                        if(str == str3 && grammar[i+2][1] == "epsilon" ){
                      //
                            str4 = grammar[i+j][len-1];
                        //    cout<<"     ywq          "<< str4 <<endl;
                            for(int k=0;k<28;k++){
                                if(str4 == follow[k][0]){
                                    c3 = k;
                                    break;
                                }
                            }
                            for(int m=1;m<30;m++){
                            if(follow[c3][m] == ""){
                                len3 = m - 1;
                                break;
                            }
                        }
                            for(int m=1;m<30;m++){
                            if(follow[c2][m] == ""){
                                len2 = m - 1;
                                break;
                            }
                        }

                            for(int m=1;m<=len2;m++){
                                follow[c3][len3+m] = follow[c2][m];

                            }

                        }


                        }

                        else break;

                    }

                }

        }


    for(int i=0;i<30;i++){
            for(int j=1;j<30;j++){
                str = follow[i][j];
                for(int k=j+1;k<30;k++){
                    if(follow[i][k] == str){
                        follow[i][k] = "";
                    }
                }
            }
        }

  /*  for(int i=0;i<40;i++){
        for(int j=0;j<30;j++){
            cout << " " << follow[i][j] ;
       //     fw << first[i][j] << " ";
        }
        cout  << endl;
       // fw << endl;
    }*/

}


void LLtable(){
    int row = 0;
    int check = 0;
    int c1,c2;
    string str,str2,str3;
    string str4 = "";



    for(int j=0;j<40;j++){
        for(int k=1;k<30;k++){
            if(first[j][k] != ""){
            lltable[row][0] = first[j][0];
            lltable[row][1] = first[j][k];
            row++;

            }
        }
    }
    for(int j=0;j<180;j++){
        for(int i=0;i<85;i++){
                str = grammar[i+2][0];
                if(grammar[i][0] == lltable[j][0] && str[0] != '\t'){
                    if(j == 147){cout << "AAA "<< i;}
                    if(lltable[j][3] != "1"){
                        for(int m=1;m<10;m++){
                    lltable[j][2] += (grammar[i+1][m]+" ");
                    }
                    lltable[j][3] = "1";
                    }

                }


                 else if(grammar[i][0] == lltable[j][0] && str[0] == '\t'){
                     check = 0;
                    for(int k=1;k<16;k++){

                        str2 = grammar[i+k][0];
                        if(str2[0] != '\t'){
                            break;
                        }

                        else if(  grammar[i+k][1] == lltable[j][1]){
                            if(j == 147){cout << "DEW "<< i<<" "<<k;}
                            str4 = "";
                            for(int n=1;n<10;n++){
                                str4 += (grammar[i+k][n]+" ");
                            }
                            if(lltable[j][3] != "1"){
                                lltable[j][2] = str4;
                            lltable[j][3] = "1";
                            }

                        }


                        else if(str2[0] == '\t' && grammar[i+k][1] != lltable[j][1]){
                            str2 = grammar[i+k][1]; //VarDecl' FunDecl
                            str3 = lltable[j][1]; //;
                            if(j == 147){cout << "BBB "<< i<<" "<<k;}
                            for(int n=0;n<40;n++){
                                 if(str2 == first[n][0]){
                                    c1 = n;
                                    break;
                                 }
                            }
                            for(int n=0;n<20;n++){
                                 if(str3 == first[c1][n]){
                                    check = 1;
                                    break;
                                 }
                            }
                        //    if(j == 49){cout << "AA "<< c1<<" "<<str2;}
                         //       if(j == 50){cout << "AA "<< c1<<" "<<str2;}

                            if(check == 1 /*&& str2 != "epsilon"*/){
                                str2 = "";
                                for(int m=1;m<10;m++){
                                    str2 += (grammar[i+k][m] + " ");
                                }
                          //      if(j == 146){cout << "BB "<< i<<" "<<k;}
                          //      if(j == 147){cout << "BB "<< i<<" "<<k;}
                                 // type is here
                                 if(lltable[j][3] != "1"){
                                    lltable[j][2] = str2;
                                    lltable[j][3] = "1";
                                 }
                                 str2 = "";
                                 check = 0;
                                break;
                            }
                        }

                    }
                }
                else{}

            }
    }

    for(int j=0;j<180;j++){
        if(lltable[j][1] == "epsilon"){
            for(int n=0;n<40;n++){
                if(follow[n][0] == lltable[j][0]){
                    c2 = n;
                    break;
                }
            }

                    for(int n=0;n<25;n++){
                        if(follow[c2][1+n] != ""){

                        lltable[row][0] = follow[c2][0];
                        lltable[row][1] = follow[c2][1+n];
                        lltable[row][2] = "epsilon";
                        row++;
                        }
                    }

            lltable[j][0] = "";
            lltable[j][1] = "";
            lltable[j][2] = "";

        }
    }




     /*   for(int i=0;i<190;i++){
            cout << i << " ";
        for(int j=0;j<3;j++){
            cout << " " << lltable[i][j] ;
        }
        cout  << endl;
    }*/
}


void convert(){
    fstream fin2;
    fin2.open("main.c",ios::in);
    string str ="";
    string sub_str;
    string main[200] = {""};
    string stack[200] = {""};
    int count = 0;
    int c = 0;
    int s = 0;
    int space = 0;
    int space2 = 0;
    int len = 0;
    string newlltable[300][20];

 /*   str = lltable[6][2];
    cout << str << endl;
for(int j = 0;j < 30;j++)
printf("%d ",str[j]);*/


    for(int i = 0;i < 250;i++){
        space = 0;
        space2 = 0;
        newlltable[i][0] = lltable[i][0];
        newlltable[i][1] = lltable[i][1];
        str = lltable[i][2];
        for(int j = 0;j < 50;j++){
                if(str[j] == 32 && str[j+1] == 32 ){
                    len = j;
                    break;
                }
            }
            for(int j = 0;j <= len;j++){
                if(str[j] == 32){
                    space2 = j;
                    for(int k = space;k <= space2-1;k++){
                        sub_str += str[k];
                    }
                newlltable[i][2+s]=sub_str;
             //   cout << sub_str<<" ";
                s++;
                space = space2+1;
                sub_str = "";
                }
            }
        s = 0;
        space = 0;
        space2 = 0;
    }



/*
    for(int m = 0;m < 200;m++){
        for(int j = 0;j < 15;j++){
            cout << " " << newlltable[m][j] ;
        }
        cout << endl;
    }
*/

    while (getline(fin2, str,'\n')){
        for(int i = 0;i < 40;i++){
            if(str[i] == 0 ){
                len = i;
                break;
            }
        }

        for(int i = 0;i <= len;i++){
            if(str[i] == 32){
                space2 = i;

                for(int j = space;j <= space2-1;j++){
                    if(str[j] != '\t')
                        sub_str += str[j];
                }
             //   cout << sub_str << " " ;
                space = space2+1;
                main[count] = sub_str;
                sub_str = "";
                count ++;
            }
        }
        space = 0;
    }
cout <<endl;
    for(int i = 0;i < 200;i++){
        str = main[i];
     //   if(str != "") cout<< str ;
        if(str != "int" && str != "return" && str!="" &&((str[0] >= 65 && str[0] <= 90) || (str[0] >= 97 && str[0] <= 122))){
            main[i] = "id";
          //  cout << "fuck";
        }
        else if(str[0] >= 48 && str[0] <= 57){
            main[i] = "num";
        }
    }

    Stack trace(128);
    int mainCnt = 0;
    int llcnt = 2;
    int refR, index;
    int lastIndex;
    int flag;
    string lastvalue;
    Tree tmpTree;
    Tree newNode;
    tmpTree.index=1;
    tmpTree.value="$";
    trace.push(tmpTree);
    tmpTree.index=1;
    tmpTree.value="Program";
    trace.push(tmpTree);

  /*  fstream fw;
    fw.open("tree.txt",ios::out);
    if(!fw){
        cout << "Fail to open file" << endl;
        exit(1);
    }*/

    tmpTree=trace.pop();
    while(tmpTree.value != "$"){
        index=tmpTree.index+1;
        if(tmpTree.value == main[mainCnt]){
            for(int i=1; i<tmpTree.index; i++){
                cout << "  ";
            }
            cout << tmpTree.index << " " << tmpTree.value << endl;
            mainCnt++;
        }
        else{
            for(int i=1; i<tmpTree.index; i++){
                cout << "  ";
            }
            cout << tmpTree.index << " " << tmpTree.value << endl;
            for(refR=0; refR<250; refR++){
                if(newlltable[refR][0]==tmpTree.value && newlltable[refR][1]==main[mainCnt]){
                    break;
                }
            }

            while(newlltable[refR][llcnt] != "\0"){     //backward push
                llcnt++;
            }

            for(int i=llcnt-1; i>=2; i--){
                newNode.index = index;
                newNode.value = newlltable[refR][i];
                trace.push(newNode);
            }
            llcnt = 2;
        }
        lastIndex = index;
        lastvalue = tmpTree.value;
        tmpTree=trace.pop();
    }

    for(int i=1; i<lastIndex; i++){
        cout << "  ";
    }
    cout << lastIndex << " " << lastvalue << endl;


}

