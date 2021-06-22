#include <iostream>
using namespace std;

template<class T>
class Stack{
    struct node{
        T item;
        node *next{};
    };
    node *head;
    int maxsize;
    int length;
public:
    Stack(){
        maxsize=5;
        length=0;
        head= nullptr;
    }
    bool Empty(){
        return length==0;
    }
    void push(T item){
        if (Empty()){
            node *newnode= new node;
            newnode->item=item;
            head=newnode;
            head->next= nullptr;
            length++;
        } else{
            if (length>=maxsize)
                cout<<"max size reached cant add ["<<item<<"] to the stack"<<endl;
            else {
                node *newnode = new node;
                newnode->item = item;
                newnode->next = head;
                head = newnode;
                length++;
            }
        }
    }
    void pop(){
        node *temp = head;
        head=head->next;
        temp->next= nullptr;
        delete temp;
        length--;
    }
    void print(){
        node *curr=head;
        while (curr!= nullptr){
            cout<<curr->item<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }
    T top(){
        return head->item;
    }
    void clear(){
        node *curr=head;
        while (curr!= nullptr){
            curr->next= nullptr;
            delete curr;
            head=head->next;
            curr=head;
            length--;
        }
    }
};

int main() {
    Stack<string>s;
    s.push("omar");
    s.push("atef");
    s.push("mohamed");
    s.push("yassin");
    s.push("khalaf");
    s.push("mohamed");
    s.print();
    s.pop();
    s.print();
    s.push("Salma");
    s.print();
    cout<<"top element is "<<s.top()<<endl;
    s.clear();
    cout<<s.Empty();

    return 0;
}
