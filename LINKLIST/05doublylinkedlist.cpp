#include<bits/stdc++.h>
using namespace std;
class Node{
public:
int data ;
Node* next;
Node* prev;

Node(int value){
    data = value;
    next = NULL;
    prev = NULL;
}
};
class linkedlist{
    private:
    Node* first;
    public:
    linkedlist(){
        first = NULL;
    }


    void  createArrtodll(vector<int>& arr, int n){
        first = new Node(arr[0]);
        Node * last = first;

        for(int i=1; i< n; i++){
            Node* temp = new Node(arr[i]);
            temp->prev = last;
            last->next= temp;
            last = temp;
        }
    }

    void showman(){
        Node* p = first;

        while(p!= NULL){
            cout<< p->data <<" ";
            p=p->next;
        }
    }
};

int main(){
int n;
cin >>n ;
vector<int> arr(n);
for(int i=0; i< n; i++){
    cin >> arr[i];
}
linkedlist ls;
ls.createArrtodll(arr,n);
ls.showman();
}