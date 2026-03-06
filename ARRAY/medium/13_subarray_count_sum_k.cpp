#include<bits/stdc++.h>
using namespace std;
int better_sol(vector<int>& arr, int k){ // timecomplexity O(n*n);
    int n=arr.size();
    int counter=0;
  
    for(int i=0; i<n; i++){
        int sum =0;
        for(int j=i ; j<n; j++){
            sum += arr[j];
            if(sum==k){
                counter++;
            }
        }
    }
    return counter;
}

int optimal_solution(vector<int>& arr, int k){
    int n = arr.size();
    unordered_map<int , int> mpp;
    int prefix_sum=0;
    int cnt =0;
    mpp[0]=1;

    for(int i=0; i<n; i++){
        prefix_sum+=arr[i];
        int remove = prefix_sum-k;
        if(mpp.find(remove) != mpp.end()){
            cnt += mpp[remove];
        }
         mpp[prefix_sum]++; ;
    }

    return cnt;
}


int main(){
    int n;
    cin >>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << optimal_solution(arr, 2);
    

    return 0;
}