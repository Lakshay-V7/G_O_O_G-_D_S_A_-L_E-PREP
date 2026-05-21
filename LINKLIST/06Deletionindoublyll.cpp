#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node* prev;
    int data;
    Node* next;
Node(int value){
    data = value;
    next = NULL;
    prev = NULL;
}

};
class Linkedlist{
    private:
    Node* first;

    public:
    Linkedlist(){
        first= NULL;
    }


    void convertarr2ll(vector<int>& arr, int n ){
        first = new Node(arr[0]);
        Node* last = first;
        for(int i=1; i<n; i++){
            Node* t= new Node(arr[i]);
            t->prev = last;
            last->next =  t;
            last = t;
        }
    }
    void showman(){
        Node* p = first;
        while(p!=NULL){
            cout << p->data;
            p=p->next;
        }
    }
    void deletion(int node){
        Node* p = first;

        if(first == NULL || node < 0){return ;}
        

        if(node == 0){
            
            first = first ->next;
            
          if(first != NULL){
            first->prev = NULL;
        }
           
            delete p;
            }

        else{
            Node* p = first;
            for(int i=0; i<node && p!=NULL; i++){
                p=p->next;

            }
            if(p == NULL)
            return;
            Node* t = p->prev;  

            t->next = p->next;

        if(p->next != NULL){
            p->next->prev = t;
        }

            delete p;


        }
    }

};
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    Linkedlist ld;
    ld.convertarr2ll(arr,n);
    
    ld.deletion(2);
    ld.showman();

    return 0;
}