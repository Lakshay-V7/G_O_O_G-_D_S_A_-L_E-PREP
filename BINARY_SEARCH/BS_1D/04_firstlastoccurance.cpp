
#include<bits/stdc++.h>
using namespace std;
int first_occurance(vector<int>& arr, int target){
    int low =0; int high = arr.size()-1;
    int first_O = arr.size();
    while(low <= high){
        int mid = (low +high)/2;
        if(arr[mid]>= target){
            first_O = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }

    }
    return first_O;

}
int last_occurance(vector<int>& arr, int target){
    int low =0; int high = arr.size()-1;
    int last_O = arr.size();
    while(low <= high){
        int mid = (low +high)/2;
        if(arr[mid] > target){
            last_O = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }

    }
    return last_O;

}
pair<int , int> full_implement_up_low_Bound(vector<int>& arr, int target){ // this function using lower and upperbound raw implementation
    
   int first_O = first_occurance( arr, target);
   int last_O =  last_occurance( arr,  target);

   if(arr[first_O]!= target || first_O == arr.size()){
        return {-1,-1};
   }
   else{
    return {first_O, last_O-1};
   }

}

int occurance_f(vector<int>& arr, int target){
 int low =0; int high = arr.size()-1;
 int ans =-1;
 while(low <= high){
    int mid = (low+high)/2;
    if(arr[mid]== target){
        ans = mid;
        high = mid -1;
    }
    else if(arr[mid] < target){
        low = mid +1;
    }
    else{
        high = mid -1;
    }
 }
 return ans;
}
int occurance_l(vector<int>& arr, int target){
 int low =0; int high = arr.size()-1;
 int ans =-1;
 while(low <= high){
    int mid = (low+high)/2;
    if(arr[mid]== target){
        ans = mid;
        low = mid +1;
    }
    else if(arr[mid] < target){
         low = mid +1;
    }
    else{
        high = mid -1;
    }
 }
 return ans;
}
pair<int , int> classical_method(vector<int>& arr , int target){ // timecomplexity O(log n) when target is not there else 2*O(log n);
    int first = occurance_f(arr, target);
    if(first == -1 || arr[first] != target ){
        return{-1,-1};
    }
    int second = occurance_l(arr,target);


    return {first , second};

}


pair<int,int> first_lastoccurance(vector<int>& arr, int target){ // this is using classical function avilable in C++ time complexity 2* O(log n)
    // we have three solution to solve this problem 
    /*1. solution to do linear search time complexity O(n)
      2. solution to use concept of lower and upperbound
      3. if recruiter want binarysearch basics then solution to implement basics*/
    
    // we will be solving with lower bound and upper bound first
    int n = arr.size();

    int first = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    int last = upper_bound(arr.begin(), arr.end(), target) - arr.begin() - 1;

    if(first == n || arr[first] != target){
        return {-1,-1};
    }

    return {first,last};
}

int main(){

    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int target;
    cin >> target;

    pair<int,int> ans = classical_method(arr,target);

    cout << ans.first << " " << ans.second;

    return 0;
}