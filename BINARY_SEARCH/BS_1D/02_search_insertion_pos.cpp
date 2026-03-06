#include<bits/stdc++.h>
using namespace std;
int searchInsert(vector<int>& nums, int target){
    int n = nums.size();
    int low =0; int high = n-1;
    int ans=n;
    while(low<= high){
        int mid = (low+high)/2;
        if(nums[mid]>= target){
            ans = mid;
            high = mid-1;
        }
        else{
            low= mid+1;
        }
    }
    return ans;
}

int main(){
    int n , target;
    cin >> n ;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cin >> target;

    int index = searchInsert(arr, target);
    cout<< index<<endl;
}