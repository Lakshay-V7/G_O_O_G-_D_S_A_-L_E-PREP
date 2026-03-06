#include<bits/stdc++.h>
using namespace std;
long long optimal_secondlargest(vector<long long>& arr){
     if(arr.size() < 2) return -1;

    long long n = arr.size();
    long long largest = arr[0];
    long long slargest = LLONG_MIN;
    for(long long i=1; i<n; i++){
        if(arr[i] > largest){
            slargest = largest;
            largest = arr[i];
        }
        else if(arr[i]<largest && arr[i]>slargest){
            slargest = arr[i];
        }
    }
   
    if(slargest == LLONG_MIN) return -1;
    return slargest;
}

int main(){
    int n;
    cin  >> n;

    vector<long long> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << optimal_secondlargest(arr) << endl;

}