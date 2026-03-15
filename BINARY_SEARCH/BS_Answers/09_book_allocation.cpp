#include<bits/stdc++.h>
using namespace std;
int check_distribution(vector<int>& arr , int pages){
    int student=1;
    int pages_sum =0;
    for(int i=0; i< arr.size(); i++){
        if(arr[i] > pages){return -1;}
        if(arr[i]+pages_sum <= pages){

            pages_sum += arr[i];
        }
        else{
            student +=1;
            pages_sum = arr[i];
        }
    }
    return student;
}
int book_allocation(vector<int>& arr , int m ){
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans =-1;

    while(low <= high){
        int mid = low+(high-low)/2;
        
        if(check_distribution(arr , mid) <= m){
            ans = mid;
            high= mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int m;
    cin >> m;

    cout<< book_allocation(arr, m);

    return 0;
}