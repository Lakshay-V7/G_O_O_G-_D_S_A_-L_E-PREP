#include<bits/stdc++.h>
using namespace std;

int way_station_pos(vector<int>& arr, long double dis){
    int counter = 0;

    for(int i = 1; i < arr.size(); i++){
        long double gap = arr[i] - arr[i-1];

        int stations = gap / dis;

        if(gap == stations * dis)
            stations--;

        counter += stations;
    }
    return counter;
}

long double minmaxDistance(vector<int>& arr, int k){
    int n = arr.size();

    long double low = 0;
    long double high = 0;

    for(int i = 0; i < n-1; i++){
        high = max(high , (long double)(arr[i+1] - arr[i]));
    }

    long double diff = 1e-6;

    while(high - low > diff){
        long double mid = low + (high - low)/2.0;

        if(way_station_pos(arr, mid) > k)
            low = mid;
        else
            high = mid;
    }

    return high;
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int k;
    cin >> k;

    cout << fixed << setprecision(6) << minmaxDistance(arr, k);
}