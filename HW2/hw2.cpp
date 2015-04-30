#include<iostream>
#include<fstream>
#include <string>
#include <vector>
using namespace std;
void findFirst();
char line[40];
string grammar[94][20];


int main(){
    findFirst();
 /*   string s = "abcdefg";
    string sub;
    sub.assign(s,1,2);
    cout << sub << s.size() << s;*/
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
    string first[40][30];
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
    //    cout<<sub_str ;
        grammar[row][col] = sub_str;
        col++;
        space = 1;
        for(int j=1;j<=str.size();j++){
            if(str[j] == ' ' || str[j] == '\0'){
                sub_str = "";
     //           cout << space << j;
                for(int k = space;k < j;k++){
                    sub_str += str[k];
                }
            //    sub_str.assign(str,space,j-1);
          //      cout<<sub_str ;
                grammar[row][col] = sub_str;
                col++;
                space = j+1;
                check = 1;
            }
        }
    }
    else{
        space = 0;
     //   cout<<"BBB";
        for(int j=0;j<=str.size();j++){
            if(str[j] == ' ' || str[j] == '\0'){
                sub_str = "";
                sub_str.assign(str,space,j);
                cout<<sub_str ;
                grammar[row][col] = sub_str;
            //    cout << space << j;
                col++;
                space = j+1;
                check = 1;
            }
        }
    }

space = 0;
check = 0;
  //  cout<<str<<endl;
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
    int mark[94] = {0};
    for(int i=0;i<94;i++){
            str = grammar[i][0];
         //   cout << str << endl;
            if(str[0] == '\t' ){
                check = 1;
            }
            if(check == 0 ){
                first[row][0] = grammar[i][0];
             //   mark[row] = 1;
                row++;
             }
             check = 0;
    }
    str = "";
    check = 0;
    int list[28] ={0};
    col = 1;
    row = 0;
    int no = 0;
    for(int i=0;i<94;i++){
        for(int j=0;j<28;j++){
            if(grammar[i][0] == first[j][0]  ){
                list[j] = i;
                mark[i] = 1;
            }
        }
    }

        list[27] = 94;
        for(int j=0;j<28;j++){
            cout << list[j] << " ";
        }

        int c = 0;
        int c2 = 0;
        for(int i=0;i<28;i++){
            c = list[i];
            c2 = list[i+1];
      //      cout << c << " " << c2 << endl;
            for(int j=c+1;j<c2;j++){
                str = grammar[j][1];
           //     cout << "AA" << str << " " << endl;
                if(str[0] < 65 ||  str[0] > 90){
                    first[row][col] = grammar[j][1];
                    mark[j] = 1;
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

  //      for(int i=0;i<94;i++){
        for(int i=93;i>=0;i--){
            str = grammar[i][0] ;
            if(str[0] >= 65 && str[0] <= 90){
                c--;
            }
            if(str[0] == '\t'){
                sub_str = grammar[i][1] ;
                for(int j=0;j<28;j++){
                    if(grammar[i][1] == first[j][0]){
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
                            mark[c] = j;
                        }

                    }
                }
            }
            }
        //    cout << c << "ASD";
//------------------
cout << first[16][0] << "AXCV" << endl;
    c = 26;
        row = 1;
     //   for(int i=0;i<94;i++){
        for(int i=93;i>=0;i--){
            str = grammar[i][0] ;
            if(str[0] >= 65 && str[0] <= 90){
                c--;
            }
            if(str[0] == '\t'){
                sub_str = grammar[i][1] ;
             //   cout << first[16][0] << "AXCV" << endl;
                for(int j=0;j<28;j++){
                    if(grammar[i][1] == first[j][0] /*&& mark[c] != j*/){
                    //    cout << grammar[i][1] << " ";
                //    cout << first[16][0] << "AXCV2" << endl;
                        for(int m=1;m<30;m++){
                            if(first[j][m] == ""){
                                len = m ;
                                break;
                            }
                        }
                      //  cout << first[16][0] << "AXCV2" << endl;
                        for(int m=1;m<30;m++){
                            if(first[c][m] == ""){
                                len2 = m - 1 ;
                                break;
                            }
                        }
                    //    cout << first[16][0] << "AXCV3" << endl;
                        for(int m=1;m<len;m++){
                            first[c][len2+m] = first[j][m];
                        }

                    }
                }
            }
            }
//cout << first[16][0] << "AXCV" << endl;
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
//cout << first[25][0] << "AXCV" << endl;
first[21][0] = "Expr'";
//------------


//--------

    for(int i=0;i<40;i++){
        for(int j=0;j<30;j++){
            cout << " " << first[i][j] ;
            fw << first[i][j] << " ";
        }
        cout  << endl;
        fw << endl;
    }
    fw.close();
    for(int i=0;i<94;i++){
        cout << " " << mark[i] ;
    }

}
