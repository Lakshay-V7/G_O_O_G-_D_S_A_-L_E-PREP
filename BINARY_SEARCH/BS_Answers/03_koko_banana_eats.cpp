#include<bits/stdc++.h>
using namespace std;
long long cal_th(vector<int>& arr , int hourly){
    long long t_hourly=0;
    for(auto it: arr){
        t_hourly += ceil(double(it)/hourly);
    }
    return t_hourly;
}

int minimum_eating_speed(vector<int>& arr , int h){ // this is  a bruteforce solution take tc(O(max_element * arr.size()))
    int maxi = *max_element(arr.begin(), arr.end()); // may lead to TLE 


    for(int i=1; i<maxi ;i++){
        int  time_taken = cal_th(arr, i);

      if (time_taken <= h)
            return i;
    }
    return maxi;
}

int minimum_eating_speed_optimal(vector<int>& arr, int h){//time complexity is O(n * log(maxi))
    int maxi= *max_element(arr.begin(), arr.end());
    int low =1;
    int high = maxi;
    int answer = maxi;
    while( low  <=high){
        int mid = (low+high)/2;

        long long time_taken = cal_th(arr, mid);
        if(time_taken  <= h){
            answer =min(answer , mid);
            high = mid-1;

        }
        else{
      
            low = mid+1;
        }
    
    } 
    return answer;
  
}

int main(){
    int n , h;
    cin  >> n >> h;
    vector<int> arr(n);
    for(int i=0;i<n; i++){
        cin >> arr[i];
    }

    int ans=minimum_eating_speed_optimal(arr, h);
    cout << ans;
}

