#include<bits/stdc++.h>
using namespace std;

long double minimiseMaxDistance(vector<int> &arr, int k){

    int n = arr.size();

    vector<int> howMany(n-1 , 0);

    priority_queue<pair<long double,int>> pq;

    for(int i = 0 ; i < n-1 ; i++){
        pq.push({arr[i+1] - arr[i] , i});
    }

    for(int gas = 1 ; gas <= k ; gas++){

        auto top = pq.top();
        pq.pop();

        int index = top.second;

        howMany[index]++;

        long double newSectionLength =
        (long double)(arr[index+1] - arr[index]) /
        (howMany[index] + 1);

        pq.push({newSectionLength , index});
    }

    return pq.top().first;
}

int main(){

    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];

    int k;
    cin >> k;

    cout << fixed << setprecision(6)
         << minimiseMaxDistance(arr , k);
}