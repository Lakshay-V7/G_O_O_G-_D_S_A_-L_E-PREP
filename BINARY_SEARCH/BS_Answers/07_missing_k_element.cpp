#include<bits/stdc++.h>
using namespace std;
int bruteforce_approach(vector<int>& arr , int k){

    for(int i=0;i<arr.size(); i++){
        if(arr[i]<=k){
            k++;
        }
        else{
            break;
        }}
    
return k;
}
int optima_approach(vector<int>& arr, int k){
    int low = 0;
    int high = arr.size()-1;
    while(low <= high){
        int mid = (low+high)/2;
        int missing_count = arr[mid] - (mid+1);
        if(missing_count < k){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low+k;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n;i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    int ans = optima_approach(arr,k);
    cout << ans;
    return 0;
}