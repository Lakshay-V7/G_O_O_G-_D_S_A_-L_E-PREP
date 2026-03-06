#include<bits/stdc++.h>
using namespace std;
// for the spiral matrix we have only one optimal approach to understand the logic to print the element
// in spiral order we will track each and every element
void spiral_matrix(vector<vector<int>>& matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    int top = 0, left =0; 
    int right = m-1;
    int bottom = n-1;
    vector<int> ans;

    while(left<=right && top <= bottom){
        for(int i=left; i<= right; i++){
            ans.push_back(matrix[top][i]);
        }
        top++;
        for(int i=top; i<= bottom; i++){
            ans.push_back(matrix[i][right]);
        }
        right--;

        if(top<=bottom){ 
            for(int i=right ; i>= left ; i--){
            ans.push_back(matrix[bottom][i]);
        }
    }
        bottom--;
        if(left <= right){
        for(int i=bottom; i>= top ; i--){
            ans.push_back(matrix[i][left]);
        }
        left++;
    }
    }


    for(int i=0; i<ans.size(); i++){
        cout<< ans[i]<<" ";
    }

}

int main(){
    int n , m;
    cin >>n>>m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>> matrix[i][j];
        }
    }

    spiral_matrix(matrix);
}