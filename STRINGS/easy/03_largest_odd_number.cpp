#include<bits/stdc++.h>
using namespace std;
string largestOddNumber(string num) { // we need the largest odd substring
    int n = num.size();
    for(int i=n; i>=0; i--){
        if((num[i]-'0')%2==1)
        {
            return num.substr(0,i+1);
        }
    }

    return "";

    }

int main(){
    string s;
    cin >> s;

    cout << largestOddNumber(s);

}