#include<bits/stdc++.h>
using namespace std;

bool linearsearch(vector<int>&arr, int num){
    for(int i=0; i<arr.size(); i++){
        if(arr[i]==num){
            return true;
        }
    }
    return false;
}
int bruteforce(vector<int>& arr){ // brute force takes order of  O(n^2); space is O(1);
    // in brute force we used linear search for seeing that next element is present and moving to that element
    // if that element is not present just i pointer will move to next element as in order that its is moving;
    int n = arr.size();
    int longest =1;
    for(int i=0; i< n; i++){
        int x = arr[i];
        int cnt =1;
        while(linearsearch(arr, x+1)== true){
            x= x+1;
            cnt++;
        }

    longest = max(longest , cnt);
        
    }
return longest;
}

int bettersolution(vector<int>& arr ){// timecomplexity O(nlog n) as one operation of sorting is there
    // space complexity is O(1) 
  // in the  better approach we will be using sorting as advantage
  sort(arr.begin(), arr.end());
  int longest =1; int last_smaller = INT_MIN; int counter =1;
  for(int i=0; i<arr.size();i++){ // when element are sorted we  can esily see sequeces
    // and taking middle one we can check for back element and front element
    if(arr[i]-1 == last_smaller){
        counter++;
        last_smaller = arr[i];
    }
    else if(arr[i]-1!=last_smaller){
        counter =1;
        last_smaller = arr[i];
    }
    longest = max(longest , counter);
  }

  return longest;
}

int optimal_solution(vector<int>& arr){
    // here we will use unordered set this insertion will help to recover from redundancy of element 
    unordered_set<int> st;
    for(int i=0; i<arr.size(); i++){
        st.insert(arr[i]);
    }
    int longest =1;
   
    for(auto it : st){
        if(st.find(it-1)== st.end()){
            int cnt =1;
            int x = it;
            while(st.find(x+1)!= st.end()){
                x= x+1;
                cnt= cnt +1;
            }
            longest = max(longest,  cnt);
        
        }
      
    }

    return longest;
}
int main(){
    int n ; 
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout<<"longest consecutive element are:"<<optimal_solution(arr)<<endl;

return 0;
}