#include<bits/stdc++.h>
using namespace std;
int ncr_fuction(int n , int m){// timecomplexity O(m);
    if(m > n){
        return 0;
    }
   // n  = n-1;
   // m = m-1;
    int ans=1;
    for(int i=0; i<m ;i++){
        ans = ans *(n-i);
        ans = ans/(i+1);
    }

    return ans;
}

vector<int>  fuction_toprecit_whole_row(int n){
    vector<int> ansrow;
    for(int c = 0; c < n ; c++){
        ansrow.push_back(ncr_fuction(n-1 , c));
    }

    return ansrow;
}

int main(){
    int n ;
    cin >> n;
    vector<int> answer;
    answer  = fuction_toprecit_whole_row(n);
    for(auto it : answer){
        cout<< it <<endl;
    }

    return 0;
    
}