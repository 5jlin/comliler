#include<iostream>
#include<fstream>
#include <string>
#include <vector>
using namespace std;
void findFirst();
void findFollow();
char line[40];
string grammar[94][20];
string first[40][30];
string follow[40][30]={};
int list[28] ={0};

int main(){
    findFirst();
    findFollow();
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
                cout<<sub_str ;
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
    string str3 = "";
    int c1,c2,c3;
    int len,len2;

    follow[0][1] = "$";

  /*  for(int i=0;i<93;i++){
        str = grammar[i][0];
        if(str[0] != '\t'){

        }


    }*/

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
                        for(int m=1;m<=len2;m++){
                            follow[c1][len+m] = first[c2][m];

                        }
               //         cout << "yes" << str << " " << str2 <<endl;
                    for(int m=1;m<30;m++){
                        if(first[c2][m] == "epsilon"){
                         //   cout << "yes" ;
                      //   str3 = ??; //c3
                         for(int j=0;j<93;j++){
                            for(int n=1;n<30;n++){
                            if(grammar[j][n] == ""){
                                len = n - 1 ;
                                break;
                                }
                            }
                            if(grammar[j][len] == str2){
                                str3 = grammar[j-1][0];
                                cout << "yes" << str3 <<endl;
                            }

                        }

                         }


                         for(int j=0;j<28;j++){
                            if(str3 == follow[j][0]){
                                c3 = j;
                                break;
                            }
                        for(int n=1;n<30;n++){
                            if(follow[c1][n] == ""){
                                len = n - 1 ;
                                break;
                            }
                        }
                        for(int n=1;n<30;n++){
                            if(follow[c3][n] == ""){
                                len2 = n - 1 ;
                                break;
                            }
                        }
                        for(int n=1;n<=len2;n++){
                            follow[c3][len+n] = follow[c1][n];
                       //   follow[c1][n] = follow[c3][len+n]  ;
                        }
                        break;
                    /*    for(int k=1;k<93;k++){
                            if(grammar[k][0] == str2){


                            }

                        }*/
                                //follow A

                            }
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





        for(int j=0;j<28;j++){

        }


    }

 /*   for(int i=1;i<=40;i++){
        for(int j=1;j<=30;j++){
            if(follow[i][[j] == "epsilon"){
                for(int m=1;m<=40;m++){

                }
                }
            }
        }*/




 /*   for(int i=0;i<30;i++){
            for(int j=1;j<30;j++){
                str = follow[i][j];
                for(int k=j+1;k<30;k++){
                    if(follow[i][k] == str){
                        follow[i][k] = "";
                    }
                }
            }
        }*/

    for(int i=0;i<40;i++){
        for(int j=0;j<30;j++){
            cout << " " << follow[i][j] ;
       //     fw << first[i][j] << " ";
        }
        cout  << endl;
       // fw << endl;
    }

}
