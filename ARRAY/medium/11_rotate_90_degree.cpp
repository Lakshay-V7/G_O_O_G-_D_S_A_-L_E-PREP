#include<bits/stdc++.h>
using namespace std;
// so we need to rotate the array so what operation we can do first just do take element and copy to the index needed
// the bruteforce solution :
void bruteforce(vector<vector<int>>& matrix){ // time complexity O(n*n) 
    int n= matrix.size();
    int m= matrix[0].size();

    vector<vector<int>> ans(n, vector<int>(m)); // space complexit O(n*n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans[j][n-i-1]= matrix[i][j];
        }
    }


   for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        cout << ans[i][j]<<" ";
    }
    cout<<endl;
   }
}

void optimal_approach(vector<vector<int>>& matrix){// we will reduce the space complexity to be O(1)
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i=0; i<n; i++){ // the complexiy is O(n) and  spacecomplxit O(1)
        for(int j=i+1; j<n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for(int i=0; i<n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << matrix[i][j]<<" ";
         }
    cout<<endl;
   }

}
int main(){
    int n, m;
    cin>> n>>m;
    vector<vector<int>> matrix(n, vector<int>(m));

    for(int i=0;i<n; i++){
        for(int j=0;j<m;j++){
            cin >> matrix[i][j];
        }
    }
    optimal_approach(matrix);
}