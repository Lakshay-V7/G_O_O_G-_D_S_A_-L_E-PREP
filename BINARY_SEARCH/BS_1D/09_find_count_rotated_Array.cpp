#include<bits/stdc++.h>
using namespace std;

int rotated_count(vector<int>& arr){
    int low =0; int high = arr.size()-1;
    int ans= INT_MAX, index =-1;
   
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid]>= arr[low]){
            if(ans[low]<ans){

            }
            
            low= mid+1;
        }
        else{
            ans= min(ans, arr[mid]);
            index = ans;
            high = mid-1;
        }

    }
return index;
}
      



int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i< n;i++){
        cin >> arr[i];
    }
    int answer= rotated_count(arr);
    cout << answer <<endl;

    return 0;
}