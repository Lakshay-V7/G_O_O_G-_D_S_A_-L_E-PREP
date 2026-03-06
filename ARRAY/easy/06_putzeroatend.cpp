#include<bits/stdc++.h>
using namespace std;
void  brute_zero_end(vector<int>& arr){
    int n= arr.size();
    vector<int> temp;
    for(int i=0; i<n;i++){
        if(arr[i]!=0){
            temp.push_back(arr[i]);
        }
    }
    for(int i=0; i<temp.size() ;i++){
        arr[i] = temp[i];
    }
    int temp_size= temp.size();
    for(int i= temp_size ; i<n; i++){
        arr[i]=0;
    }

    for(auto it: arr){
        cout  << it <<" ";
    }
}
void optimal_zero_end(vector<int>& arr)
{
    int n= arr.size();
    int j=-1;
    for(int i=0; i<n;i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    
    if(j == -1) return;

    for(int i=j+1; i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
    for(auto it: arr){
        cout << it <<" ";
    }
}

int main(){
    int n;
    cin  >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    optimal_zero_end(arr);
    return 0;
}