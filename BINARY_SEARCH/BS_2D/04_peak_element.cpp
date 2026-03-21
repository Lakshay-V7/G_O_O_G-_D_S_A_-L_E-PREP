#include<bits/stdc++.h>
using namespace std;
int func_maxi(vector<vector<int>>& mat , int n , int m, int mid){
    int maxval = -1;
    int index =-1;
    for(int i=0; i< n; i++){
        if(mat[i][mid] > maxval){
            maxval= mat[i][mid];
            index =i;
        }
    }
    return index;
}
vector<int> peak_element(vector<vector<int>>& mat)
{
    int n= mat.size();
    int m= mat[0].size();

    int low=0; int high = m-1;
    while(low <= high){
        int mid = low+(high-low)/2;
        int max_row= func_maxi(mat , n ,m ,mid);
        int left = mid - 1 >= 0 ? mat[max_row][mid - 1] : INT_MIN;
        int right = mid + 1 < m ? mat[max_row][mid + 1] : INT_MIN;
        if (mat[max_row][mid] > left && mat[max_row][mid] > right) {
                  return {max_row, mid};
              } 
              else if (left > mat[max_row][mid]) {
                  high = mid - 1;
              } 
              else {
                  low = mid + 1;
              }
    }
    return {-1,-1};
}
int main(){
    int n , m; 
    cin >>n >> m;
    vector<vector<int>> matrix(n  , vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> matrix[i][j];
        }
    }

    vector<int> peak = peak_element(matrix);
    for(auto it: peak){
        cout << it <<" ";
    }
}