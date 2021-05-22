#include <iostream>
using namespace std;
template <class T>
class LinkedStack{
    struct Node{
        T item;
        Node* next;
    };
    Node* top,*curr;
public:

    LinkedStack(){
        top=NULL;
    }
    void push(T elem){
        Node* elemPtr= new Node;
        elemPtr->item=elem;
        elemPtr->next=top;
        top=elemPtr;

    }
    bool Empty(){
        return top==NULL;
    }
    void pop(){
        if(Empty()){
            cout<<"Empty Stack"<<endl;

        }
        else{
            Node* temp = new Node;
            temp = top;
            top=top->next;
            temp=temp->next=NULL;
            delete temp;
        }
    }
    void GetTop(T &StackTop){
        if(Empty())
            cout<<"Empty Stack"<<endl;
        else{
            StackTop=top->item;
        }
    }

    void print(){
        cout<<"Stack elements are"<<endl;
       curr = top;
        cout<<"[ ";
        while (curr!=NULL){
            cout<<curr->item<<" ";
            curr=curr->next;

        }
        cout<<"]"<<endl;
    }
};

int main() {
LinkedStack<int> s;
s.push(1);
s.push(2);
s.push(3);
s.print();
s.pop();
s.print();
    return 0;
}
