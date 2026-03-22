#include<bits/stdc++.h>
using namespace std;

string freq_sort(string s){
    unordered_map<char , int>  mpp_freq;
    for(auto ch : s){
        mpp_freq[ch]++;
    }

    vector<pair<char , int>> vec;
    for (auto it : mpp_freq){
        vec.push_back(it);
    }
    sort(vec.begin(), vec.end(),[](auto &a ,auto &b){
        return a.second > b.second;}); // comparator sorting technique(lambda function)[capture](parameter){return point logic};


    string result="";
    for(auto it : vec){
        result += string(it.second ,it.first);
    }  // string constructor
    

    return result;
       
}

int main(){
    string s;
    cin >> s;

    cout << freq_sort(s);

}