#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = NULL;
    }

};

class Linkedlist{
    private:
    Node* first ;

    public:
    Linkedlist(){
        first  = NULL;
    }

    void convertArr2ll(vector<int>& arr,int n){
        Node *last;
        first  = new Node(arr[0]);
        last = first;


        for(int i=1; i<n; i++){
            Node* temp= new Node(arr[i]);
            last->next = temp;
            last = temp;
        }
    }

    void showman(){
        Node* p = first;
        while(p!=NULL){
            cout<< p->data <<" ";
            p= p->next;
        }
    }

    Node* search(int x){
        Node *p = first;
        while(p){
            if(p->data == x){
                return p;
            }
           
                p=p->next;
            
        }
        return NULL;
    }

};

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i< n;i++){
        cin >> arr[i];
    }
    Linkedlist list;
    list.convertArr2ll(arr,n);
    list.showman();
    Node* ans = list.search(2);
    if(ans){
        cout << ans->data;
    }
    else{
        cout <<"invalid VAl"<<endl;
    }

return 0;

}