#include<bits/stdc++.h>
using namespace std;
string longest_common_prefix(vector<string>& s){
    sort(s.begin(), s.end());
    int n= s.size();
    string s1= s[0];
    string s2 = s[n-1];

    string lcs ;
    int a= s2.size();
     int minLength = min(s1.size(), s2.size());

        // Compare characters of first and last string
        for (int i = 0; i < minLength; i++) {
            // Stop if characters differ
            if (s1[i] != s2[i]) break;

            // Add matching character to answer
            lcs += s1[i];
        }

 return lcs;
}
int main(){
    int n;
    cin >>n;
    vector<string> strr(n);
    for(int i=0; i<n ; i++){
        cin >> strr[i];
    }

    cout<<longest_common_prefix(strr);




}