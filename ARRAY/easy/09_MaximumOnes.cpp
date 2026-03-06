#include<bits/stdc++.h>
using namespace std;

int maximum_ones(vector<int>& arr){
    int maxi = 0;
    int counter= 0;
    for (int i=0; i<arr.size(); i++){
        if(arr[i]==1){
            counter++;
            maxi= max(maxi , counter);
        }
        else{
            counter =0;
        }
    }
    return maxi;
}
int main(){
    int n;
    cin >>n;
    vector<int> arr(n);
    for(int i=0;i<n; i++){
        cin >> arr[i];
    }
cout << maximum_ones(arr)<<endl;
}