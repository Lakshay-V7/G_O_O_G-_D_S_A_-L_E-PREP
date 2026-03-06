#include<bits/stdc++.h>
using namespace std;
int bruteforce(vector<int>& arr){ //O(N^2) this will lead to time lead exceed so to not get tle 
    int n = arr.size();
    int profit = INT_MIN;
    int max_profit =0;
    for(int i=0; i<n; i++){
    
        for(int j=i+1; j<n; j++){
            profit = arr[j]-arr[i];
            max_profit = max(max_profit , profit);
        }   
    }
    return max_profit;
}

int best_sol(vector<int>& arr){
    int n= arr.size();
    int mini =  arr[0];
    int profit =0; int cost;
    for(int i=0; i<n;i++){
        cost = arr[i]-mini;
        profit = max(profit , cost);
        mini = min(mini , arr[i]);
    }
    return profit;
}

int main(){
    int n;
    cin >>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout <<best_sol(arr)<<endl;
}