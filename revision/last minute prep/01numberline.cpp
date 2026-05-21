//first question input in string are *and #, if(*=#) cout 0 , if *<***# negative *># then positive
#include<bits/stdc++.h>
using namespace std;
void logic(string s){
    int star_count = 0;
    int hash_count =0;
    for(int i=0;i<s.size(); i++){
        if(s[i] == '*') star_count++;
        else if(s[i]=='#') hash_count++;
    }
    if(star_count == hash_count){
        cout << 0<<endl;
    }
    else if(star_count < hash_count){
        cout << "negative" <<endl;
    }
    else{
        cout << "positive" <<endl;
    }

}
int main(){
    string s;
    getline(cin , s);

    logic(s);

}