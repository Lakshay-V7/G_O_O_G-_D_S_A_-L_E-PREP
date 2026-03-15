#include<bits/stdc++.h>
using namespace std;
// patter is the matrix is sorted row and column wise (whole matrix is not sorted )
/*1  3   5  7
  10 11 16 20
  23 30 34 60
  
1st approach is basic linear search O(n*m)tc;
2nd approach better is to search every row one by one using binary search
 tc= O(nlog m) 
  
  */

bool optimal_search_code(vector<vector<int>>& arr, int key){
    // we will use right adjesenct travesal technique we can observe that if we are at one column and 
    // element is less than that then all other element in column of that particular element will also be greateer
    int n= arr.size(); 
    int m= arr[0].size();

    int i =0; // pointing to the first index
    int j = m-1;// pointing to the last index at that row

    while(i < n && j >=0){
        if(arr[i][j] == key){
            return true;
        }
        else if(arr[i][j]> key){
            j--;  // move left
        }
        else{
            i++; // move down
        }
    }
    return false; // if not found return false
    
}
int main(){
    int n , m;
    cin >> n >>m;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i=0; i< n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    int key;
    cin >> key;

    int ans = optimal_search_code(arr, key);
    if(ans ==1 ){
        cout <<"true"<<endl;
    }
    else{
        cout << "false"<<endl;
    }
    return 0;
}