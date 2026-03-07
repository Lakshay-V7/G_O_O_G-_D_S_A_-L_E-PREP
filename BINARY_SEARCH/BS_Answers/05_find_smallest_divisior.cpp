#include<bits/stdc++.h>
using namespace std;
int calculative_function(vector<int>& nums, int divisor){
    int sum =0;
    for(auto it:nums){
        sum += ceil(double(it)/divisor);
    }
    return sum;
}


int smallestDivisor(vector<int>& nums, int threshold) { // timecomplexity : O(n*(range(min-max))) -> worst case O(n^2)
     int maxi= *max_element(nums.begin(), nums.end());
     int mini= 1;
        
     for(int i=mini ; i<maxi ; i++){
        if(calculative_function(nums, i)<= threshold)
        {
            return i;
        }
     }
     return -1;
    
    }


int smallestDivisor_optimalapproach(vector<int>& nums, int threshold) { 
     int maxi= *max_element(nums.begin(), nums.end());
     int mini= *min_element(nums.begin(), nums.end());
     int answer = maxi;
        while(mini <= maxi){
            int mid = (mini+maxi)/2;

            if(calculative_function(nums,mid)<=threshold){
                answer = min(answer , mid);
                maxi =mid-1;
            }
            else{
                mini = mid+1;
            }
        }
    return answer;
    
    }
int main(){
    int n , threshold;
    cin >>n; 
    vector<int> nums(n);
    for(int i=0; i<n;i++){
        cin>>nums[i];
    }
    cin >> threshold;   

    int final_answer= smallestDivisor_optimalapproach(nums, threshold);
    cout << final_answer;

    return 0;
}
