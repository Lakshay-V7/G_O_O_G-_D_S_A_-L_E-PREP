#include<bits/stdc++.h>
using namespace std;
int binary_search_iterative(vector<int>& arr, int x){
    int n= arr.size();
    long long high = n-1; long long low =0;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == x) return mid;
        else if(x < arr[mid]){
            high = mid -1;
        }
        else {
            low = mid+1;
        }
    }
    return -1;
    
}

int recursion_bs(vector<int>& arr, int x , int low  , int high)
{
    if(low>high) return -1;
    
    int mid= (low+high)/2;
    if(arr[mid]== x) return mid;

    else if(x<arr[mid]) 
    {
        return recursion_bs( arr,  x ,low  ,mid-1 );
    }
    else{
        return recursion_bs(arr, x ,mid+1 , high);
    }
    
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n; i++){
        cin >> arr[i];
    }
    int low =0; int high= n-1;

    int res =  recursion_bs(arr, 12, low, high);
    cout <<res<<endl;
}
// timecomplexity : O(log n)