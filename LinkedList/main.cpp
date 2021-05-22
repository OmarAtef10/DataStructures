#include <iostream>
using namespace std;
class DoubleLinkedList{
  struct Node{
      int item ;
      Node* next;
      Node* prev;


  };
  Node* first;
  Node* last;
  int length;

public:
    DoubleLinkedList(){
        first=last=NULL;
        length=0;

    }
    bool isEmtpy(){
        return length==0;
    }
    void insertFirst(int elem){
        Node* newNode= new Node;
        newNode ->item=elem;
        if (length==0){
            first=last=newNode;
            newNode->next=NULL;
            newNode->prev=NULL;

        }
        else{
            newNode->next=first;
            newNode->prev=NULL;
            first->prev=newNode;
            first=newNode;
        }
        length++;
    }
    void insertLast(int elem){
        Node* newNode= new Node;
        newNode ->item=elem;
        if (length==0){
            first=last=newNode;
            newNode->next=NULL;
            newNode->prev=NULL;
        }else{
            last->next=newNode;
            newNode->next=NULL;
            newNode->prev=last;
            last->next=newNode;
            last=newNode;

        }
        length++;
    }
    void insertAtPos(int pos, int item){

        if(isEmtpy())
            cout<<"empty list "<<endl;
        else if(pos <0 or pos>length)
        cout<<"out of range"<<endl;
        else{
            Node* newNode = new Node;
            newNode->item=item;
            if(pos == 0 )
                insertFirst(item);
            else if(pos ==length)
                insertLast(item);
            else{
                Node* curr = first;
                for (size_t i = 1 ; i<pos ;i++){
                    curr=curr->next;

                }
                newNode->next=curr->next;
                newNode->prev=curr;
                curr->next->prev=newNode;
                curr->next=newNode;
                length++;
            }

        }
    }

    void print(){

    Node* curr=first;
    while (curr!=NULL){
        cout<<curr->item<<" ";
        curr=curr->next;

    }

    }
    void reverse(){
        cout<<"this is reversed "<<endl;
        Node* curr=last;
        while (curr!=NULL){
            cout<<curr->item<<" ";
            curr=curr->prev;

        }
    }
    void RemoveFirst(){
        if (length==0)
            cout<<"empty list"<<endl;
        else if(length==1){
            delete first;
            last=first=NULL;
            length--;

        }
        else{
            Node* curr = first;
            first=first->next;
            first->prev=NULL;
            delete curr;

        }
    }

    void RemoveLast(){
        if (length==0)
            cout<<"empty list"<<endl;
        else if(length==1){
            delete first;
            last=first=NULL;
            length--;

        }
        else{
           Node* curr = last;
           last=last->prev;
           last->next=NULL;
            delete curr;

        }
        length--;
    }
    void Remove(int elem){

        if (isEmtpy());
        cout<<"empty list"<<endl;

        if (first->item==elem)
            RemoveFirst();
        else;
        Node* curr = first->next;
        while (curr!=NULL){
            if(curr->item==elem){
                break;
            curr=curr->next;
        }
        }
        if(curr==NULL)
            cout<<"item not found"<<endl;
        else if (curr->next==NULL){
            RemoveLast();
        }
        else{
            curr->prev->next=curr->next;
            curr->next->prev=curr->prev;
            delete curr;
            length--;
        }

    }
    };
int main() {
DoubleLinkedList l ;
l.insertFirst(10);
l.insertLast(30);
l.insertLast(40);
l.insertAtPos(1,20);
//l.RemoveFirst();  //it Works..
//l.RemoveLast();   //it Works..
//l.Remove(20);
l.print();
cout<<endl;
l.reverse();

    return 0;
}
