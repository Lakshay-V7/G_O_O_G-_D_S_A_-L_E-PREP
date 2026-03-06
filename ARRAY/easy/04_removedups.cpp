#include<bits/stdc++.h>
using namespace std;
void brute_solremovedups(const vector<int>& arr){
    set<int> st;
    for(int i=0; i<arr.size(); i++){
        st.insert(arr[i]);
    }
    for(auto it : st){
        cout << it << "";
    }
}

void optimal_removedups(vector<int>& arr){
 sort(arr.begin(), arr.end());

    int i=0;
 
    for(int j=1 ;j<arr.size(); j++){
        if(arr[j]!=arr[i]){
           i++;
           arr[i]=arr[j];
        }
        }
        arr.resize(i + 1);
    for(auto it : arr){
        cout  << it  << " ";
    }
}

int main(){
    int n ;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n ; i++){
        cin >> arr[i];
    }
 //   brute_solremovedups(arr);
        optimal_removedups(arr);

    return 0;
    }