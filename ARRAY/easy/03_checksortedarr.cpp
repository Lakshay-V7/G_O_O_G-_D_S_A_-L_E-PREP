#include<bits/stdc++.h>
using namespace std;
bool check_arrsorted(vector<long long>& arr ){
    long long n = arr.size();
    for(int i=1; i<n; i++){
        if(arr[i]>=arr[i-1]){

        }
        else{ return false;}
    }
    return true;
}
int main(){
    int n;
    cin >>n;
    vector<long long> arr(n);

    for(long long i=0; i<n; i++){
        cin  >> arr[i];
    }

    cout << check_arrsorted(arr) << endl;
  

}