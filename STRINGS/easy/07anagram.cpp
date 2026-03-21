#include<bits/stdc++.h>
using namespace std;
bool bruteforce(string s , string t){
    if(s.size()!= s.size()) return false;
    sort(s.begin(),s.end());
    sort(t.begin(), t.end());

    for(int i=0;i< s.size(); i++){
        if(s[i]!=t[i]){
            return false;
        }
    }
    return true;
}

bool optimal(string s, string t){
    if(s.size()!=t.size())return false;

    int freq[26]={0};
    
    for(int i=0; i<s.size(); i++){
        freq[tolower(s[i])-'a']++;  
        freq[tolower(t[i]-'a')]--; 
    }
  
    for(int i=0; i<26; i++){
        if(freq[i]!= 0)
        {
            return false;
        }
    }
    return true;
}

int main(){
    string s;
    cin >> s;
    string res;
    cin >> res;

    if(optimal(s,res)){
        cout <<"true"<<endl;
    }
    else{
        cout << "false"<<endl;
    }

    return 0;
}
