#include <iostream>
using namespace std;

template<class T>
class Queue{
    struct node{
        T item;
        node *next{};
    };
    node *head;
    node *tail;
    int maxsize;
    int length;
public:
    Queue(){
        maxsize=5;
        length=0;
        head= nullptr;
        tail= nullptr;
    }
    bool Empty(){
        return length==0;
    }
    void enqueue(T item){
        if (Empty()){
            head=new node;
            head->item=item;
            head->next= nullptr;
            tail=head;
            length++;
        } else{
            if (length>=maxsize)
                cout<<"max size reached ["<<item<<"] was kicked out of the queue by the guards"<<endl;
            else {
                node *newnode = new node;
                newnode->item = item;
                newnode->next= nullptr;
                tail->next=newnode;
                tail=newnode;
                length++;
            }
        }
    }
    void dequeue(){
        if (Empty())
            cout<<"there's nothing to delete.."<<endl;
        else{
            node *temp = head;
            head=head->next;
            temp->next= nullptr;
            cout<<temp->item<<" was the chosen one and left the queue"<<endl;
            delete temp;
            length--;
        }
    }
    void clear(){
        node *curr = head;
        while (curr!= nullptr){
            curr->next= nullptr;
            head=head->next;
            delete curr;
            curr=head;
        }
        length=0;
    }
    T getTop(){
        return head->item;
    }
    T getTail(){
        return tail->item;
    }
    void print(){
        if (Empty())
            cout<<"empty Queue homie "<<endl;
        else{
            node *curr=head;
            while (curr!= nullptr){
                cout<<curr->item<<" ";
                curr=curr->next;
            }
            cout<<endl;
        }
    }
};
int main() {
    Queue<string>q;
    q.enqueue("omar");
    q.enqueue("godz");
    q.enqueue("medo");
    q.enqueue("tmsa7");
    q.enqueue("mohab");
    q.enqueue("nedal-belta");
    q.print();
    q.dequeue();
    q.print();
    q.clear();
    q.print();
    q.enqueue("belta");
    q.enqueue("3as3oos");
    //q.dequeue();
    q.print();
    cout<<"head is ["<<q.getTop()<<"] tail is ["<<q.getTail()<<"]"<<endl;

    return 0;
}
