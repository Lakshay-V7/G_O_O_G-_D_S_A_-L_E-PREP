#include<bits/stdc++.h>
using namespace std;
bool brute_search(vector<vector<int>>& arr, int key){
    int n= arr.size();
    int m= arr[0].size();


    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]==key)
            {
                return true;
            }
        }
    }
    return false;
}
bool betterapproach(vector<vector<int>>& arr, int key){

    
}

int main(){
    int n , m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }\

    int key;
    cin >> key;

    cout << brute_search(arr, key);


    return 0;
}