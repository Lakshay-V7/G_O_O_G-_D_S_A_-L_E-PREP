#include<bits/stdc++.h>
using namespace std;

void optimal_Solution(vector<int>& arr, int n){
    int left=0, mid=0 , right=n-1;
  while(mid<=right){
    if (arr[mid]==0){
        swap(arr[mid], arr[left]);
        mid++;
        left++;
    }
    else if(arr[mid]==1){
        mid++;
    }
    else{
        swap(arr[right], arr[mid]);
        right--;
    }
}

    for(int i=0; i< n; i++){
        cout<<arr[i];
    }
}

int main(){
    int n; 
    cin >>n ;
    vector<int> arr(n);
    for(int i=0;i<n; i++){
        cin >> arr[i];
    }

    optimal_Solution(arr, n);
}