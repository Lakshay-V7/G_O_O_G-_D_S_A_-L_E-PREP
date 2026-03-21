#include<bits/stdc++.h>
using namespace std;

bool isomorphic_string(string s , string t){
    int s1[256]={0};
    int s2[256]={0};

    int n= s.size();
    for(int i=0; i<n; i++){
        if(s1[s[i]]!= s2[t[i]]) return false;

        s1[s[i]] = i+1;
        s2[t[i]] = i+1;
    }
    return true;
}

int main(){
    string s , t;
    cin >> s >> t;

    if(isomorphic_string(s , t)){
        cout << "True"<<endl;
    }
    else{
        cout<< "False"<<endl;
    }
}