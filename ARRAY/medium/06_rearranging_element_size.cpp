#include<bits/stdc++.h>
using namespace std;
void  brute_sol(vector<int>& arr){
    int n = arr.size();
    vector<int> arr_pos;
    vector<int> arr_neg;
    for(int i=0; i<n ; i++){
        if(arr[i]<0){
            arr_neg.push_back(arr[i]);
        }
        else{
            arr_pos.push_back(arr[i]);
        }
    }
    for(int i=0; i<n/2;i++){
        arr[2*i]= arr_pos[i];
        arr[2*i+1]= arr_neg[i];
    }

    for(auto it : arr){
        cout << it <<" ";
    }
    cout << endl;
}

void optimal_sol(vector<int>& arr){
    int pos_index = 0 , neg_index=1;
    int n = arr.size();
    vector<int> ans(n);
    for(int i=0; i< n; i++){
        if(arr[i]<0){
            ans[neg_index]=arr[i];
            neg_index+=2;
        }
        else{
            ans[pos_index]=arr[i];
            pos_index+=2;
        }
    }
    for(auto it : ans){
        cout << it << " ";
    }
    cout  << endl;
}

int main(){
     int n;
     cin >>n;
     vector<int> arr(n);
     for(int i=0;  i<n; i++){
        cin>> arr[i];
     }

    optimal_sol(arr);
}