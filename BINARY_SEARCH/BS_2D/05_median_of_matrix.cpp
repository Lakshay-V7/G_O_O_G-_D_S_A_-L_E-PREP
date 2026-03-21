#include<bits/stdc++.h>
using namespace std;

int countSmallEqual(vector<vector<int>>& mat , int mid){
    
    int n = mat.size();
    int m = mat[0].size();
    
    int count = 0;

    for(int i = 0; i < n; i++){
        count += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
    }

    return count;
}

int medianMatrix(vector<vector<int>>& mat){

    int n = mat.size();
    int m = mat[0].size();

    int low = INT_MAX;
    int high = INT_MIN;

    // finding global min and max
    for(int i = 0; i < n; i++){
        low = min(low , mat[i][0]);
        high = max(high , mat[i][m-1]);
    }

    int required = (n * m) / 2;

    while(low <= high){

        int mid = low + (high - low) / 2;

        int smallEqual = countSmallEqual(mat , mid);

        if(smallEqual <= required)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

int main(){

    int n , m;
    cin >> n >> m;

    vector<vector<int>> mat(n , vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    cout << medianMatrix(mat);

}