#include<bits/stdc++.h>
using namespace std;
bool check_fuction(vector<int>& arr , int cows , int md){ // this function check given cown to be filled at that index
    int count=1;
    int last_pos = arr[0];
    int n = arr.size();int minimum_dis = 1;
    for(int i=1; i<n ;i++){
        if(arr[i]-last_pos >= md){
            count++;
            last_pos=arr[i];
            
           
        }
        if(count >= cows){
                 return true;
            }
      
    }
    return false;
}
int aggressive_cow(vector<int>& arr, int k)
{   int n= arr.size();
    sort(arr.begin(), arr.end());
    int mini = 1;
    int maxi= arr[n-1]-arr[0];
    int minimum_dis =1;
    for(int i=mini ; i < maxi ; i++){
        if(check_fuction(arr, k ,i)){
            minimum_dis =i;
        }
    }
    return minimum_dis;


}
int optimal_aggressive_cow(vector<int>& arr, int k){
      int n= arr.size();
    sort(arr.begin(), arr.end());
    int mini = 1;
    int maxi= arr[n-1]-arr[0];
    int minimum_dis =1;

    while(mini <= maxi){
        int mid = (mini+maxi)/2;
        if(check_fuction(arr, k ,mid)){
            minimum_dis =mid;
            maxi = mid-1;
        }
        else{
            mini= mid+1;
        }

    }
  
    return minimum_dis;

}
int main(){
    int n;
    cin >> n;
    vector<int> array(n);
    for(int i=0;i<n; i++){
        cin >> array[i];
    }
    int k;
    cin >> k;

    int ans = aggressive_cow(array , 4);
    cout << ans;

    return 0;
}