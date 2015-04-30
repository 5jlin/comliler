#include<iostream>
#include<fstream>
#include <string>
#include <vector>
using namespace std;
void findFirst();
char line[40];
string grammar[100][20];
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
    int row = 0;
    int col = 0;
    int check = 0;
    int space=0;
    string str ="";
    string sub_str;
    string first[40][30];
    vector<string> aStr;

    while (getline(fin, str,'\n')){
  //  aStr.push_back(str);//str :a line
    if(str[0] == '\t'){
        sub_str = '\t';
        cout<<sub_str ;
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
                cout<<sub_str ;
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
    for(int i=0;i<100;i++){
        for(int j=0;j<20;j++){
            cout << " "<</*i << " " << j << " " << */grammar[i][j] ;
        }
        cout  << endl;
    }

    for(int i=0;i<100;i++){
        for(int j=0;j<20;j++){
          //  if(grammar)
        }

    }

}
