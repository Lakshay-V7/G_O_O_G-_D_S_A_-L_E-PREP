#include<bits/stdc++.h>
using namespace std;
int lower_bound(vector<int>& arr, int target){
    int low=0; int high = arr.size()-1;
    int answer = arr.size();
    
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid]>= target){
            answer = mid;
            high = mid -1;
        } 
        else{
            low= mid+1;
        }
    }

    return answer;
}
int upper_bound(vector<int>& arr, int target){
    int low=0; int high = arr.size()-1;
    int answer = arr.size();
    
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid]> target){
            answer = mid;
            high = mid -1;
        } 
        else{
            low= mid+1;
        }
    }

    return answer;
}



int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n; i++){
        cin >> arr[i];
    }

    int x= upper_bound(arr,12);
    cout << x <<endl;
    return 0;
}