#include<bits/stdc++.h>
using namespace std;
int max_depth(string s){
    int p=0;
    int maxi=0;
    for(auto ch : s){
        if(ch =='(') p++;
        if(ch==')')p--;
        maxi= max(maxi, p);

    }
    return maxi;
}

int main(){
    string s;
    cin >> s;

    cout << max_depth(s) <<endl;

}