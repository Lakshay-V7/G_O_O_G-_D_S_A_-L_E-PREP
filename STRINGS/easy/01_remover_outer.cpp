#include<bits/stdc++.h>
using namespace std;
string  removeouterParanthesis(string s){
    string output = "";
    int level =0;
    for(auto ch : s){

        if(ch=='('){
            if(level > 0){
                output+=ch;
              
            }
              level++;
            
        }

        else if(ch==')'){
        level--;
        
        if(level>0){output+= ch;}
        }
    }
    return output;
}
int main(){
    string s;
    cin >> s;

    string r=  removeouterParanthesis(s);
    cout << r << endl;
}