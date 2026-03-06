#include<bits/stdc++.h>
using namespace std;
void brute_force(vector<long long>& a , long long target){
    long long n = a.size();
    for(long long i=0; i<n;i++){
        for(long long j=i+1; j<n;j++){
            if(a[i]+a[j]==target){
                cout << i <<" "<<j<<endl;

            }
        }
    }
}
void better_solution(vector<long long>& a, long long target){
    int n = a.size();
    unordered_map<long long , long long> mp;
    for(long long i=0; i<n; i++){
        long long complement = target - a[i];
        if(mp.find(complement)!= mp.end()){
            cout << mp[complement] <<" "<<i<<endl;
        }
        mp[a[i]]=i;
    }
}

void optimal(vector<long long>& a, long long target){
    vector<pair<long long ,long long>> pa;
    long long n = a.size();
    for(int i=0; i<n; i++){
        pa.push_back({a[i],i});
    }
    sort(pa.begin(), pa.end());
    long long left= 0, right = n-1;
    while(left<right){
        long long sum = pa[left].first + pa[right].first;
        if(sum == target){
            cout << pa[left].second <<  " "<<pa[right].second<<endl;
        }
        else if(sum < target){
            left++;
        }
        else{
            right--;
        }
    }
}
int main(){
    long long n;
    cin >>n;
    long long target;
    cin >> target;

    vector<long long >arr(n);
    for(long long i=0; i<n;i++){
        cin >> arr[i];
    }

    optimal(arr, target);

    return 0;
}