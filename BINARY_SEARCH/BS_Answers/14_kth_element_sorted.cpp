#include<bits/stdc++.h>
using namespace std;
double optimal_solution(vector<int>& arr1 , vector<int>&arr2 , int k){
    if(arr1.size()>arr2.size())
        return optimal_solution(arr2, arr1 ,k);

    int a1 = arr1.size(); 
    int a2 = arr2.size();
    int low= max(k-a2 ,0); int high= min(k,a1);  // changes to be done here

    while(low <= high){
        int cut1= low+(high-low)/2;
        int cut2= k - cut1; // instead a1+a2+1/2

        int left1= (cut1==0) ? INT_MIN : arr1[cut1-1];
        int left2= (cut2==0) ? INT_MIN : arr2[cut2-1];

        int right1= (cut1==a1) ? INT_MAX : arr1[cut1];
        int right2= (cut2==a2) ? INT_MAX : arr2[cut2];

        if(right2 >= left1 && right1 >= left2){
           
            return max(left1,left2);
            
        } 
        else if(right2 < left1 ){
            high = cut1-1;
        }
        else{
            low= cut1+1;

        }
    }
    return 0.0;
}
int main(){
    int n;
    cin  >>n ;
    vector<int>arr1(n);
    for(int i=0; i< n; i++){
        cin >> arr1[i];
    }
    int m;
    cin >> m;
    vector<int> arr2(m);
    for(int i=0; i<m; i++){
        cin >> arr2[i];
    }

    int answer = optimal_solution(arr1 , arr2, 3);

    cout<< answer <<endl;
}