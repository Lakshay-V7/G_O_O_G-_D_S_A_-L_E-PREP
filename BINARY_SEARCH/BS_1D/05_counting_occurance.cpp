#include<bits/stdc++.h>
using namespace std;
vector<int> getting_first_last(vector<int>& arr , int target)
{
 int first = lower_bound(arr.begin(), arr.end(), target)- arr.begin();
 if(first == arr.size() || arr[first] != target){
    return{-1, -1};
 }

 int last = upper_bound(arr.begin(), arr.end(),target)-arr.begin()-1; // we already did -1 to get one index back to get last occurance of target

 return {first, last};
}
int main(){
    int n ;
    cin  >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>> arr[i];
    }
    int target ;
    cin >> target;


    vector<int> ans = getting_first_last(arr, target);

    if(ans[0] == -1){
        cout << "0"<<endl;
    }
    else{
        cout << ans[1]-ans[0]+1;
    }
  

    return 0;

}