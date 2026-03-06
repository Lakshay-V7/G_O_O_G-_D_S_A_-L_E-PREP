#include<bits/stdc++.h>
using namespace std;
vector<int> optimal_element_cal(int n){
    vector<int> ansrow;
    long long anss=1;
    ansrow.push_back(1); // first elemnt is one always we willstart from second;
    for(int c=1; c<n; c++){
        anss = anss *(n - c);
        anss = anss/ c;
        
        // pushing into then list
        ansrow.push_back(anss);
    }
    


    return ansrow;
}
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> final_ans;
        for(int i=1 ;i<=numRows; i++ ){
            final_ans.push_back(optimal_element_cal(i));
        }
    return final_ans;
 }

int main(){
    int n;
    cin >> n;

    vector<vector<int>> result = generate(n);

    for(auto row : result){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }

return 0;

}