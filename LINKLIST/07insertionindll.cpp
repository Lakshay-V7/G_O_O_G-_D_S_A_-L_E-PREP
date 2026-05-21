#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* prev;
    int data;
    Node* next;

    Node(int value){
        data = value;
        prev= NULL;
        next = NULL;

    }
};
class linkedlist{
    private:
    Node* first;
    public:
    linkedlist(){
        first = NULL;
    }

    void convertarr2dll(vector<int>& arr,int n){
        first = new Node(arr[0]);
        Node* last = first;

        for(int i=1;i<n; i++){
            Node* t = new Node(arr[i]);
            t->prev = last;
            last->next = t;
            last = t;
        }
        
    }
    void showman(){
        Node* q = first;
        while(q!= NULL){
            cout << q->data <<" ";
            q=q->next;
        }
    }

    void insertion(int x, int node){
        if(first == NULL || node < 0) return;
        if(node == 0){
            Node *t = new Node(x);
            t->next= first;
            first->prev= t;
            first = t;
        }
        else{
            Node *p , *t;
            p= first;
            for(int i=0;i<node; i++){
                p= p->next;
            }
            t= new Node(x);
            
            
            t->next = p;
            t->prev = p->prev;
            p->prev->next = t;
            p->prev = t;

        }
    }

};

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n; i++){
        cin>> arr[i];
    }

    linkedlist ls;
    ls.convertarr2dll(arr, n);
    ls.insertion(3, 1);
    ls.showman();
    



    return 0;
}