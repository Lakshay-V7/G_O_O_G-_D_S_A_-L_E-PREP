#include<bits/stdc++.h>
using namespace std;
  
bool duplicate_element_search(vector<int> arr, int target){  
   int low= 0; int high = arr.size()-1;
    while(low<=high){
        int mid = (high+low)/2;
        
        if(arr[mid]==target){return mid;}
        // here are just one edge case to see that is if arr[mid]== arr[low]== arr[high]}  then we will just move high aand low
        if(arr[mid]== arr[low]== arr[high]){
            low++;
            high--;
        }
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

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n; i++){
        cin>> arr[i];
    }
    int target;
    cin >> target;

    bool answer= duplicate_element_search(arr, target);
    cout << answer <<endl;

    return 0;
}