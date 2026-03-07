#include<bits/stdc++.h>
using namespace std;
int day_needed(vector<int>& weights, int capacity){
    int current_load = 0;
    int day=1;
    for(auto it : weights){
        if(current_load+it > capacity){
            day++;
            current_load = it;
        }
        else{
            current_load+=it;
        }
    }
    return day;
}
int shipWithinDays(vector<int>& weights, int days) {
    int mini = *max_element(weights.begin(), weights.end());
    int maxi = accumulate(weights.begin(), weights.end(),0);

    for(int capacity   = mini ;capacity < maxi; capacity++){
        if(day_needed(weights , capacity)<= days){
            return capacity;
        }
    }
    return maxi;      
}
int shipWithinDays_optimal(vector<int>& weights, int days) {
    int mini = *max_element(weights.begin(), weights.end());
    int maxi = accumulate(weights.begin(), weights.end(),0);
    int answer = maxi;
    while(mini <= maxi){
        int mid = (mini+maxi)/2;
        if(day_needed(weights, mid)<=days){
            answer = min(answer , mid);
            maxi = mid-1 ;
        }
        else{
            mini = mid+1;
        }

    }

    return answer;
        
}
int main(){
    int n;
    cin >>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int days;
    cin >> days;

    int answer = shipWithinDays_optimal(arr,days);
    cout << answer;
}