#include<bits/stdc++.h>
// its optimal approach will use moore algorithm
using namespace std;
vector<int> majority_element_brute(vector<int> arr){ // it is noticed that there will be maximam of two majele

    int n = arr.size();
    int floor_val = n/3;
    vector<int> ls;
    for(int i=0; i<n ; i++){
        if(ls.size() == 2) break;
        int counter =0;
        for(int j=0; j<n;j++){
            if(arr[i]==arr[j]){                                       //  overall timecomplexity =O(n*n)
                counter++;
            }
            
            }
            if(counter >= floor_val){
                if(ls.empty() || ls[0] != arr[i]){
                    ls.push_back(arr[i]);
                }    
        }
        
    }

    return ls;

}

vector<int> bettersol(vector<int> arr){ // timecomplexity: O(n) space complexity increases O(n)// recruiter nakhare
    int n = arr.size();
    unordered_map<int, int> mpp;
    vector<int> ls;
    int mini =int(n/3)+1;
    for(int i=0; i< n; i++){
        mpp[arr[i]]++;

        if(mpp[arr[i]]==mini){
            ls.push_back(arr[i]);
        }
         if (ls.size() == 2) {
                break;}
    }
    return ls;
}

vector<int> optimal_solution_moore(vector<int> arr){
    int n = arr.size();
    int ele1=0, ele2=0;
    int counter1=0 , counter2=0;
    
    for(int i=0; i< n; i++){
        if(counter1==0 && arr[i]!= ele2) {
            counter1+=1;
            ele1= arr[i];
            
        }
        else if(counter2==0 && arr[i]!= ele1){
            counter2+=1;
            ele2= arr[i]; 
        }
        else if(arr[i]==ele1){
            counter1++;
        }
        else if(arr[i]==ele2){
            counter2++;
        }
        else{
            counter1--;
            counter2--;
        }
    }

    // now we will check
    vector<int> ls;
    int mini = (n/3)+1;
    counter1=0; counter2=0;
    for(int i=0; i<n; i++){
        if(arr[i]==ele1){
            counter1++;
        }
        else if(arr[i]==ele2){
            counter2++;
        }
    }
    
    if(counter1 >=mini){
        ls.push_back(ele1);
    }
    if(counter2 >=mini){
        ls.push_back(ele2);
    }

    return ls;
}

int main(){
    int n;
    cin >>n; 
    vector<int> arr(n);
    for(int i=0; i< n; i++){
        cin >> arr[i];
    }

    vector<int> ans = optimal_solution_moore(arr);
    
    for(auto it : ans){
        cout  << it << endl;
    }


}