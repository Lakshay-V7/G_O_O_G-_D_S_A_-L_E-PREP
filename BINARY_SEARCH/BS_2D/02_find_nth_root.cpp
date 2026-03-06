#include<bits/stdc++.h>
using namespace std;
double multi(double number , int n){
    double ans=1;
    for(int i=0;i<n; i++){
        ans = ans*number;
    }

    return ans;
}

double nth_root(int n , int m){
    double low = 1;
    double high = m;;
    double esp = 1e-6;
    
    while((high-low) > esp){
        double mid = (low+high)/2.0;
        if(multi(mid, n) <= m){
            
            low = mid;
        }
        else{
            high = mid;
        }
    }

    return low;
}

int  main(){
    int n , m;
    cin >> n >> m; 

    cout << nth_root(n,m);

}