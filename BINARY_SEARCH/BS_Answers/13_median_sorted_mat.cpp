#include<bits/stdc++.h>
using namespace std;

float naivesol_brute(vector<int>& arr1 , vector<int>& arr2){
    int n = arr1.size();
    int m = arr2.size();
    vector<int> final_answer;
    int i = 0 , j = 0;
    while(i < n && j < m){
        if(arr1[i]<=arr2[j]){
            final_answer.push_back(arr1[i]);
            i++;
        }
        else{
            final_answer.push_back(arr2[j]);
            j++;
        }
    }
   
    while (i < n) {
        final_answer.push_back(arr1[i]);
        i++;
    }

    while (j < m) {
        final_answer.push_back(arr2[j]);
        j++;
    }
    int size = n + m;

    if (size % 2 == 1)
        return final_answer[size / 2];
    else
        return (final_answer[size/2] + final_answer[size/2 - 1]) / 2.0;


   return -1;
}
double optimal_solution(vector<int>& arr1 , vector<int>&arr2){
    if(arr1.size()>arr2.size())
        return optimal_solution(arr2, arr1);

    int a1 = arr1.size(); 
    int a2 = arr2.size();
    int low=0; int high= a1;

    while(low <= high){
        int cut1= low+(high-low)/2;
        int cut2= ((a1+a2+1)/2) - cut1;

        int left1= (cut1==0) ? INT_MIN : arr1[cut1-1];
        int left2= (cut2==0) ? INT_MIN : arr2[cut2-1];

        int right1= (cut1==a1) ? INT_MAX : arr1[cut1];
        int right2= (cut2==a2) ? INT_MAX : arr2[cut2];

        if(right2 >= left1 && right1 >= left2){
            if((a1+a2)%2 == 0){
                return (max(left1 , left2)+ min(right1,right2))/2.0;
            }
            else{
                return max(left1,left2);
            }
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

    float answer= optimal_solution(arr1 , arr2);
    cout << answer <<endl;
}

