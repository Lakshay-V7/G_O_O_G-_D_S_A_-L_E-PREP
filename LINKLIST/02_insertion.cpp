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
    Node* first;

public:
    Linkedlist(){
        first = NULL;
    }
void convertArr2LL(vector<int>& arr, int n){
    Node* last;
    first = new Node(arr[0]);
    last = first;

    for(int i=1; i<n; i++){
        Node* temp = new Node(arr[i]);
        last->next =  temp;
        last = temp;
    }
}

void showman() {
    Node* p = first;
    while(p!=NULL){
        cout << p->data <<" ";
        p = p->next;
    }
}


void insertat1(int x){
    
    Node* temp = new Node(x);
    
    temp->next = first;

    first = temp;
}

void insertatend(int x){
    Node* last = first;
    Node* temp = new Node(x);

    if(first == NULL){
        first = temp;
    }
    else{
    while(last->next != NULL)
    {
        last=last->next;
    }
    last->next = temp;

    }
   
}

void insertat_index(int x, int index){
    if(index < 0) return;

    Node *p;
    Node *t;

    t= new Node(x);
    if(index == 0){
        t->next=first;
        first =t;
    }

    else{
        p = first;
        for(int i=0; i<index-1 && p!= NULL; i++){
            p=p->next;
        }
        if(p==NULL){
            cout <<"invalid index"<<endl;
        }

        else{
            t->next = p->next;
            p->next = t;
        }
    }
}
};

int main(){
    int n;
    cin >>n; 
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    Linkedlist list;
  // list.convertArr2LL(arr, n);
   

    list.insertat1(100);
    list.insertatend(200);
    list.insertat_index(5,2);
    list.showman();

    return 0;
}