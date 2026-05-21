#include<bits/stdc++.h>
using namespace std;

class Node{
    public :
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
        first = new Node(arr[0]);
        Node* last = first;

        for(int i=1; i< n; i++){
            Node* t = new Node(arr[i]);
            last->next = t;
            last =t;
        }
    }

void showman(){

    Node* p = first;
    while(p!=NULL){
        cout << p->data <<" ";
        p=p->next;
    }
}
void deletion(int pos){
    Node *p ,*t;
    int value_container;
    p= first;
    if(pos < 0) return;

    if(pos==0){
        first=  first->next;
        value_container = p->data;

        delete [] p ;
    }
    else{
        for(int i=0; i<pos; i++){
            t=p;
            p=p->next;

        }
        t->next = p->next;
        value_container = p->data;
        delete [] p; 
    }

}
};

int main(){
    int n;
    cin >>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
Linkedlist ls;
ls.convertArr2LL(arr, n);
//ls.showman();
ls.deletion(1);
ls.showman();
}