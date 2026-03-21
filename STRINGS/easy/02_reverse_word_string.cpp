#include<bits/stdc++.h>
using namespace std;
string reverse_string_word_brutesol(string s){
    string store;

    vector<string> str_vec;

    for(auto ch : s){
        if(ch==' '){
            str_vec.push_back(store);
            store = "";
        }
        else{
            store+= ch;
        }
    }
    if(store!=""){
        str_vec.push_back(store);
    }

   reverse(str_vec.begin(),str_vec.end()); // to reverse the vectorbased string

   string ans;
   for(int i=0; i<str_vec.size(); i++){
    ans += str_vec[i];
    if(i != str_vec.size()-1){
        ans+= " ";
    }

   }

   return ans;

}

string reverse_word_optimal(string s){
     reverse(s.begin(), s.end());

    int n = s.size();
    int i = 0;
    int l = 0;
    int r = 0;

    while(i < n){

        while(i < n && s[i] == ' ') i++;   // skip spaces

        if(i >= n) break;

        while(i < n && s[i] != ' '){
            s[r++] = s[i++];
        }

        reverse(s.begin() + l, s.begin() + r);

        s[r++] = ' ';
        l = r;
        i++;
    }

    s.resize(r - 1);   // remove last extra space
    return s;
}

int main(){
    string s;
  
    getline(cin, s);

    cout <<  reverse_string_word(s);

}