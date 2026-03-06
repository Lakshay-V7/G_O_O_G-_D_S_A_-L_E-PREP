#include<bits/stdc++.h>
using namespace std;
int subarray_sum(vector<int>& arr){  // complexity = O(n^3)
    int sum=0;
    int final_sum= INT_MIN;
    int n= arr.size();
    for(int i=0;i<n ;i++){
        for(int j=i; j<n ;j++){
                int sum =0;
            for(int k=i ; k<=j; k++){
                sum += arr[k];
            }
            final_sum = max(final_sum,sum); //every sub array generation
        }
    }
    return final_sum;
}
int better_solution(vector<int>& arr){ // complexity O(n^2)
    int sum=0; 
    int final_sum =INT_MIN;
    int n = arr.size();
    for(int i=0; i<n; i++){
        sum =0;
        for(int j=i ; j<n; j++){
            sum+=arr[j];
            final_sum = max(final_sum , sum);
        }
    }
    return final_sum;

}
int kandane_algo(vector<int>& arr){
    int n=arr.size();
    int maxi=0;
    int sum =0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
        if(sum > maxi){
            maxi = sum;
        }
        if(sum < 0){
            sum=0;
        }
    }
    return  maxi;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n ; i++){
        cin >> arr[i];
    }

    cout << kandane_algo(arr)<<endl;

    return 0;
}