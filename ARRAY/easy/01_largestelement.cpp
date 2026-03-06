#include<bits/stdc++.h>
using namespace std;
int largest_brute(vector<long long>& arr){
    int n = arr.size();
    int largest=0;
    sort(arr.begin(), arr.end());
    largest = arr[n-1];

    return largest;
}

int optimal_largest(vector<long long>& arr){
    int n = arr.size();
    int largest = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    return largest;
}


int main(){
    int n;
    cin >> n;
    vector<long long> arr(n);
    for(int i=0; i<n ; i++){
        cin >> arr[i];
    }
    int largest = optimal_largest(arr);cout << largest <<endl;

}