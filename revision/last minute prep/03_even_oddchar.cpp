#include<bits/stdc++.h>
using namespace std;

char fuction_to_findodd(vector<char> arr){

    int n = arr.size();
    unordered_map<char, int> freq_mpp;

    for(int i = 0; i < n; i++){
        freq_mpp[arr[i]]++;
    }

    char ans = '\0';   // correct null char

    for(int i = 0; i < n; i++){
        if(freq_mpp[arr[i]] % 2 == 1){
            ans = arr[i];
            break;
        }
    }

    return ans;
}

int main(){

    int n;
    cin >> n;

    vector<char> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    char res = fuction_to_findodd(arr);

    if(res == '\0'){
        cout << "all even" << endl;
    }
    else{
        cout << res;
    }
}