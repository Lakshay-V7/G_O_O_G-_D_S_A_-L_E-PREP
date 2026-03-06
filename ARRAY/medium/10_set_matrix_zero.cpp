#include<bits/stdc++.h>
using namespace std;
void mark_row(vector<vector<int>>& arr ,int i){
    for(int j=0; j<arr[0].size(); j++){
        if(arr[i][j] != 0){
            arr[i][j] =-1;
        }
    }
}
void mark_col(vector<vector<int>>& arr ,int j){
    for(int i=0; i<arr.size(); i++){
        if(arr[i][j] != 0){
            arr[i][j] =-1;
        }
    }
}
void brute_sol(vector<vector<int>>& arr){// O (n^3)
int n= arr.size();
int m= arr[0].size();
for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        if(arr[i][j]==0){
            mark_row(arr,i);
            mark_col(arr,j);
        }
    }   

}
for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        if(arr[i][j]==-1){
            arr[i][j]=0;
        }
    }

}
}

void better_sol(vector<vector<int>>& arr){ // O(n^2) and space O(n+M)
    int n= arr.size();
    int m = arr[0].size();
    int row_mark[n] ={0};
    int col_mark[m] ={0};

    for(int i=0;i<n;i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]==0){
                row_mark[i]=1;
                col_mark[j]=1;

            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(row_mark[i] || col_mark[j]){
                arr[i][j]=0;
            }
        }
    }

}





void display(vector<vector<int>>& arr){
    int n= arr.size();
    int m= arr[0].size();
    for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
       
        cout <<arr[i][j]<<" ";
    }
 cout << endl;
}
}

void optimal_sol(vector<vector<int>>& arr){
    int n= arr.size();
    int m= arr[0].size();

    int col_0=1;
    for(int i=0; i< n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]==0){

                arr[i][0]=0;
                if(j!=0){
                    arr[0][j]=0;
                }
                else{
                    col_0 = 0;
                }
            }
        }
    }

    for(int i=1; i< n; i++){
        for(int j=1; j<m; j++){
            if(arr[i][j]!=0){
                if(arr[i][0]==0 || arr[0][j]==0){
                    arr[i][j]=0;
                }
            }
        }
    }

    if(arr[0][0]==0){
        for(int j=0; j<m; j++){
            arr[0][j]=0;
        }
    }
    if(col_0==0){
        for(int i=0;i<n; i++){
            arr[i][0]=0;
        }
    }

}


int main()
{
    int n , m;
    cin >> n >>m;
    vector<vector<int>> arr(n, vector<int>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m;j++){
            cin >> arr[i][j];
        }
    }
    optimal_sol(arr);

    display(arr);
}