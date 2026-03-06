#include<bits/stdc++.h>
using namespace std;
void bruteforce(vector<int>& a , vector<int>& b){
    int n= a.size();
    int r= b.size();

    set<int> st;
    for(int i=0; i<n; i++){
        st.insert(a[i]);
    }
    for(int i=0; i<r; i++){
        st.insert(b[i]);
    }

    vector<int> uniion;
    for(auto it : st){
        uniion.push_back(it);
    }

    for (auto it : uniion){
        cout << it << " ";
    }

}

void optimal_approach(vector<int>& a , vector<int>& b){
    int i=0, j=0;
    int n= a.size();
    int r= b.size();
    vector<int> uniion ; 

    while (i <n  && j<r){
        if(a[i]<=b[j]){
            if(uniion.size()==0 ||uniion.back()!=a[i] ){
                uniion.push_back(a[i]);
            }
            i++;
        }
        else{
          
            if(uniion.size()==0 ||uniion.back()!=b[j] ){
                uniion.push_back(b[j]);
            }
            j++;
        
        }
    }

while(j<r){
      if(uniion.size()==0 ||uniion.back()!=b[j] ){
                uniion.push_back(b[j]);
            }
            j++;
}
while(i<n){
    if(uniion.size()==0 ||uniion.back()!=a[i] ){
                uniion.push_back(a[i]);
            }
            i++;
}
for(auto it: uniion){
    cout<< it <<" ";
}
}

int main(){
    int n , r;
    cin >> n >> r; 
    vector<int>arr1(n);
    vector<int>arr2(r);
    for(int i=0; i<n; i++){
        cin >> arr1[i];
    }
    for(int i=0; i<r; i++){
        cin >> arr2[i];
    }

    optimal_approach(arr1, arr2);

}