#include<bits/stdc++.h>
using namespace std;

int linear_search(vector<int> & arr, int target){
    int size = arr.size();
    for(int i=0; i<size; i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
    
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n ;i++){
        cin >> arr[i];
    }

    cout << "INDEX ELEMENT FOUND IS :"<< linear_search(arr,5);


    return 0;
}