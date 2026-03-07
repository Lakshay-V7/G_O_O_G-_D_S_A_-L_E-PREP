#include<bits/stdc++.h>
using namespace std;
bool eachday_bouque_made(vector<int>& bloomDay ,int day,int m , int k){
    int counter=0;
    int boque_made =0;
 for(auto it : bloomDay){
    if(it <= day ){
        counter++;
        if(counter == k){
            boque_made++;
            counter =0;
        }
    }
    else{
        counter =0;
    }
 }
 return boque_made >=m ;
}

int minDays(vector<int>& bloomDay, int m, int k) { // O(n* range ) worst case is O(n^2) that will lead to TLE

        long long totalFlowers = 1LL * m * k;
        if (totalFlowers > bloomDay.size()) return -1; // Not enough flowers

        int mini = *min_element(bloomDay.begin(), bloomDay.end());
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());

        for(int i=mini; i<maxi ; i++){
            if(eachday_bouque_made(bloomDay,i,m,k)){
                return i;
            }
        }
        return -1;
    }
int minDays_optimal(vector<int>& bloomDay, int m, int k) { // tc-> O(n*log(min-max(range)))

        long long totalFlowers = 1LL * m * k;
        if (totalFlowers > bloomDay.size()) return -1; // Not enough flowers

        int mini = *min_element(bloomDay.begin(), bloomDay.end());
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());
        int answer= maxi;
        while(mini <= maxi){
            int mid = (mini+maxi)/2;
            if(eachday_bouque_made(bloomDay,mid,m,k)){
                answer = min(answer, mid);
                maxi=  mid-1;
            }
            else{
                mini = mid+1;
            }
        }
       return answer;
    }

int main(){
    int n, m , k ;
    cin >> n >>m>>k;
    vector<int> bloomday(n);
    for(int i=0;i<n; i++){
        cin >> bloomday[i];
    }

    int ans = minDays_optimal(bloomday, m, k);
    cout << ans;
}