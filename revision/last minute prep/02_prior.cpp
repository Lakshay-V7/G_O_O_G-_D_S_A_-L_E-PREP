// given n sized array to find the element  that element is grater than prior
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n;i++){
        cin >> arr[i];
    }

    if(arr.size()==0){
        return 0;
    }
    int maxi = arr[0]; int count =1;
    for(int i=1;i< n; i++){
        if(arr[i] > maxi){
            maxi = arr[i];
            count++;
        }
    }
    cout << count <<endl;


    return 0;
}