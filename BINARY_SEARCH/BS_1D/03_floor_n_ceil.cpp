#include<bits/stdc++.h>
using namespace std;
int floor_Value(vector<int>& nums, int target){
    int n= nums.size();
    int low =0; int high = n-1;
    int answer =-1;
    while(low<= high){
        int mid= (low+high)/2;
        if(nums[mid] <= target){
            answer = mid;
            low = mid+1;
        }
        else{
            high = mid -1;
        }
    }
    return answer;
}
int ceil_value(vector<int>& nums, int target){
    int n= nums.size();
    int low =0; int high = n-1;
    int answer =-1;
    while(low<= high){
        int mid= (low+high)/2;
        if(nums[mid] >= target){
            answer = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return answer; 
}

int main(){
    int n, target;
    cin >>n;
    vector<int> arr(n);
    for(int i=0;i<n; i++){
        cin >> arr[i];
    }
    cin >> target;

    int ans = floor_Value(arr, target);
    cout<< ans;
    int an = ceil_value(arr, target);
    cout<< an;
}