#include<bits/stdc++.h>
using namespace std;
// sqrt using inbuilt libraries
int square_root(int n){
    int ans= sqrt(n);
    
    return ans;
}
// sqrt using linear searching method
int linear_square(int n){ // timecomplexity O(n/2) as we know we are finding squareroot
    int ans=1;
    for(int i=1; i<=n;i++){
        if(i*i <= n){
            ans = i;
        }
    }
    return ans;
}
int binary_method(int n){
    int low =1; int high =n;
    int ans=1;
    while(low <= high){
        int mid = (low+high)/2;
        if(mid*mid <= n){
            ans = mid;
            low=mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}

int  main(){
   
    int n ;
    cin >> n;

    int ans = binary_method(n);
    cout << ans;
}