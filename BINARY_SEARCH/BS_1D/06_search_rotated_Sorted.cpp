#include<bits/stdc++.h>
using namespace std;
int searching_rotated_array(vector<int>& arr, int target){
    int low= 0; int high = arr.size()-1;
    while(low<=high){
        int mid = (high+low)/2;
        
        if(arr[mid]==target){return mid;}
        // check for left side sorted
        if(arr[mid]>= arr[low]){
            if(target >= arr[low] && target <= arr[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        else{
            if(target <= arr[high] && target >arr[mid]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
    return  -1;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int target ;
    cin >> target;

    int ans= searching_rotated_array(arr, target);
    cout << ans;

    return 0;
}