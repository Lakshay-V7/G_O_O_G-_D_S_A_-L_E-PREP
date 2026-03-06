#include<bits/stdc++.h>
using namespace std;

void optimal_leader(vector<int>& arr){
    int n= arr.size();
    vector<int> ans;
    int maxi= INT_MIN;
    for(int i=n-1; i>=0; i--){
        if(arr[i]>maxi){
            maxi = arr[i];
            ans.push_back(arr[i]);
        }
    }

    for(auto it : ans){
        cout<< it <<" ";
    }
    cout << endl;
}

int main(){
    int n;
    cin>> n;
    vector<int>arr(n);
    for(int i=0;i<n; i++){
        cin >> arr[i];
    }
    optimal_leader(arr);
}