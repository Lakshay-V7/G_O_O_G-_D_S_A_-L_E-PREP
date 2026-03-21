#include<bits/stdc++.h>
using namespace std;
// brute force solution is we will break and created new string using substring 
bool brute_force(string s , string result){
    int a1= s.size();
    int a2 =result.size();
    if(a1 !=a2) return false;
    for(int i=0;i<a1; i++){
        string rotation= s.substr(i)+s.substr(i);
        if(rotation == result ){
            return true;
        }
        
    }
    return false;
}
bool optimal_approach(string s , string result){
    int a1= s.size();
    int a2 =result.size();
    if(a1 !=a2) return false;

    string doubledS = s + s;
    return doubledS.find(result) != string::npos;
}
int main(){
    string s , result;
    cin  >> s ;
    cin >> result;

    if(optimal_approach){
        cout <<"True"<<endl;
    }
    else{
        cout <<"false"<<endl;
    }

    return 0;
}
