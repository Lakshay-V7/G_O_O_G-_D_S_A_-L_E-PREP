#include<bits/stdc++.h>
using namespace std;
int romantoInt(string s){
    unordered_map<char , int> roman ={
        {'I',1},{'V',5},{'X',10},{'L',50},{'C',100}, {'D',500}, {'M',1000}
    }; // ye hai humara unordered map of roman character one by one

    int result =0;
    for(int i=0; i< s.size()-1; i++){
        if(roman[s[i]]< roman[s[i+1]]){
            result -= roman[s[i]];
        }
        else{
            result+= roman[s[i]];
        }
    } // hum abhi last tak phocch gaye abhi hum last ch ko point kar re to usbhi final mai add karna hai

    return result+roman[s.back()]; // s mai jo last element hai usee add karna kyu ki check pichle se hua ahi


}
int main(){
    string s;
    cin  >> s;

    cout << romantoInt(s)<<endl;

    return 0;
}