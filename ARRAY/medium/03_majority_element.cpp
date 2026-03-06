#include<bits/stdc++.h>
using namespace std;
int maj_bruteforce(vector<int>& arr){
    int n = arr.size();
    int counter=0;
    for(int i=0; i<n;i++){
        for(int j=0; j<n; j++){
            if(arr[i]== arr[j]){
                counter++;
            }

            if(counter > n/2){return arr[i];}
        }
    }
    return 0;
}

int better_solution(vector<int>& nums){
    map<int , int>mpp;
    for(int i=0; i<nums.size(); i++){
        mpp[nums[i]]++;
    }
    for(auto it:mpp){
        if(it.second > nums.size()/2)
        {
            return it.first;
        }
    }
    return 0;
}

int optimal_solution(vector<int>& nums){
    int ele,counter=0;
    for(int i=0; i<nums.size(); i++){
        if(counter==0){
            counter=1;
            ele=nums[i];
        }
        else if(nums[i]=ele)
        {
            counter++;
        }
        else{
            counter--;
        }
    }
    return ele;
}
int main(){
    int n;
    cin>> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
   cout << optimal_solution(arr) <<endl;

}