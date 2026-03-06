#include<bits/stdc++.h>
using namespace std;
int getting_minimum_rotated_array(vector<int>&  arr){
    int low =0; int high = arr.size()-1;
    int ans= INT_MAX; int index =-1;
   
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid]>= arr[low]){
            if(arr[low]<= ans){
                ans = arr[low];
                index = low;
            }
            low= mid+1;
        }
        else{
            if(arr[mid] < ans){
                ans= arr[mid];
                index = mid;
            }
            high = mid-1;
        }

    }
return index;
}
      


int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int ans = getting_minimum_rotated_array(arr);
    cout << ans;
    
}