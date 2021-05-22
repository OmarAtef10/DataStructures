#include <iostream>
#include <cassert>
using namespace std;
class LinkedQueue{
private:
    struct Node{
        int item;
        Node *next;
    };
    Node *front;
    Node *rear;
    int length;
public:
    LinkedQueue(){
        front=rear=NULL;
        length=0;

    }
    bool Empty(){
        return length == 0;
    }

    void enqueue(int elem){
        if (Empty()){
            front=new Node;
            front->item=elem;
            front->next=NULL;
            rear=front;
            length++;
        }
        else{
            Node *newptr = new Node;
            newptr->item=elem;
            newptr->next=NULL;
            rear->next=newptr;
            rear=newptr;
            length++;

        }
    }
void Dequeue(){
        if(Empty())
            cout<<"Empty Queue"<<endl;
        else{
            Node *Temp=front;
            if(front==rear){
                front=NULL;
                rear=NULL;
                length--;
            }
            else {
                front = front->next;
                Temp->next = NULL;
                delete Temp;
                length--;
            }
        }
    }
    int GetRear(){
        if (Empty())
            cout<<"Empty queue"<<endl;
        else
            return rear->item;
    }
    int GetFront(){
        if (Empty())
            cout<<"Empty queue"<<endl;
        else
            return front->item;
    }
    void clear(){
        Node *curr;
        while (front!=NULL){
            curr=front;
            front=front->next;
            delete curr;
        }
        rear=NULL;
        length=0;
    }
    void print(){
        if (Empty())
            cout<<"Empty queue"<<endl;
        else{
        Node *cur;
        cur=front;
        while (cur!=NULL){
            cout<<cur->item<<" ";
            cur=cur->next;
        }
        cout<<endl;
    }
    }
};

int main() {
LinkedQueue Q1;
Q1.enqueue(1);
Q1.enqueue(2);
Q1.enqueue(3);
Q1.enqueue(4);
Q1.enqueue(5);
Q1.print();
Q1.Dequeue();
Q1.print();
cout<<"front= "<<Q1.GetFront()<<endl;
cout<<"rear= "<<Q1.GetRear()<<endl;
Q1.clear();
Q1.print();

    return 0;
}
