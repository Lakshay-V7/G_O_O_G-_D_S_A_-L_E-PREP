// this question is exact replica of book allocation so just  did with optimal solution 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int check_split(vector<int>& nums , int largest_sum){
        int n = nums.size();
        int split=1;
        int sum =0;
        for(int i=0; i<n; i++){
            if(nums[i] > largest_sum) return INT_MAX;// the case that is justified 
            if(sum+nums[i] <= largest_sum){
                sum += nums[i];
            }
            else{
                split+=1;
                sum = nums[i];
            }
        }
        return split;

    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(),0);
        int ans=-1;
        while(low <= high){
            int mid = low+(high-low)/2;
            if(check_split(nums, mid)<= k){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return ans;
    }
};

int main(){
    solution ss;
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n ; i++){
        cin >> arr[i];
    }
    int m ;
    cin >> m;

    int ans = ss.splitArray(arr, m);
    cout << ans;
}