#include<bits/stdc++.h>
using namespace std;
int max_one_optimalsol(vector<vector<int>>& arr){

    int n = arr.size();
    int m = arr[0].size();

    int bestRow = -1;
    int bestIndex = m;   // smallest index of 1 so far

    for(int i = 0; i < n; i++){

        int low = 0, high = m - 1;
        int pos = -1;

        while(low <= high){

            int mid = low + (high - low) / 2;

            if(arr[i][mid] == 1){
                pos = mid;
                high = mid - 1;     // search left
            }
            else{
                low = mid + 1;
            }
        }

        // ignore rows with no 1
        if(pos != -1 && pos < bestIndex){
            bestIndex = pos;
            bestRow = i;
        }
    }

    return bestRow;
}
int max_one_bruteforce(vector<vector<int>>& arr){
    int n = arr.size();
    int m= arr[0].size();
    vector<int> ans;
    for(int i=0; i<n; i++){
            int ansval=0;
        for(int j=0; j<m; j++){
            if(arr[i][j]==1){
                ansval+=1;
            }
        }
        ans.push_back(ansval);
        ansval =0;
    }
    int maxil= *max_element(ans.begin(), ans.end());
    if(maxil == 0){
        return  -1;
    }
    for(int i=0; i<ans.size(); i++){
        if(ans[i] == maxil){
            return i;
        }
    }
    return -1;
}
int main(){
    int n , m;
    cin >> n >>m;
    vector<vector<int>> arr(n,vector<int> (m));

    for(int i=0; i< n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    int fal_as=max_one_optimalsol(arr);
    cout << fal_as<<endl;

    return 0;
}