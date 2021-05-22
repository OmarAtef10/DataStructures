#include <iostream>
using namespace std;
class linkedlist{
    struct Node{
        int item ;
        Node* next;

    };
    Node* first;
    Node* last;
    int length;

public:
    linkedlist(){
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
        }
        else{
            newNode->next=first;
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
        }else{
            last->next=newNode;
            newNode->next=NULL;
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
            Node* curr=first->next;
            Node* prev = first;
            while (curr!=last){
                prev=curr;
                curr=curr->next;
            }
            delete curr;
            prev->next=NULL;
            last=prev;
            length--;

        }
    }
    void Remove(int elem){
        if (isEmtpy())
            cout<<"empty list "<<endl;


        Node *curr , *prev;
        if(first->item==elem){
            curr=first;
            first=first->next;
            delete curr;
            length--;
            return;
        }
        if(length==0){
            last=NULL;
        }
        else{
            curr=first->next;
            prev=first;
            while (curr!=NULL){
                if(curr->item==elem)
                    break;
                prev=curr;
                curr=curr->next;}
            if(curr==NULL)
                cout<<"item not found"<<endl;
            else {
                prev->next=curr->next;
                if (last==curr){
                    last=prev;
                }
                delete curr;
                length--;

            }
        }
    }
};
int main() {
    linkedlist l ;
    l.insertFirst(10);
    l.insertLast(30);
    l.insertLast(40);
    l.insertAtPos(1,20);
//l.RemoveFirst();  //it Works..
//l.RemoveLast();   //it Works..
    l.Remove(10);
    l.print();

    return 0;
}
