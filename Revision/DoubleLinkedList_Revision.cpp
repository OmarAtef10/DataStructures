#include <iostream>
using namespace std;
class Doublelinkedlist{
    struct node{
        int item;
        node *next;
        node *prev;

    };
    node *head,*tail;
    int length;
public:
    Doublelinkedlist(){
        head=tail=NULL;
        length=0;
    }
    bool Empty(){
        return length==0;
    }
    void insertAtHead(int item){
        node *newNode=new node;
        newNode->item=item;

        if (Empty()){
            head=tail=newNode;
            newNode->next=NULL;
            newNode->prev= nullptr;
        } else{
            newNode->next=head;
            newNode->prev= nullptr;
            head->prev=newNode;
            head=newNode;
        }
        length++;
    }
    void insertLast(int elem){
        node* newNode= new node;
        newNode ->item=elem;
        if (length==0){
            head=tail=newNode;
            newNode->next=NULL;
            newNode->prev= nullptr;
        }else{
            tail->next=newNode;
            newNode->next=NULL;
            newNode->prev=tail;
            tail=newNode;

        }
        length++;
    }

    void insertAtpos(int pos , int item){
        if(pos<0 or pos>length)
            cout<<"out of bounds..\n";
        else if (pos==0)
            insertAtHead(item);
        else if(pos==length)
            insertLast(item);
        else {
            node *temp = new node;
            temp->item=item;
            node* curr = head;
            for (int i = 0; i <= pos; ++i) {
                curr=curr->next;
            }
            temp->next=curr->next;
            temp->prev=curr;
            curr->next->prev=temp;
            curr->next=temp;
            length++;
        }
    }
    void del(int item){
        node *temp;
        node *prev;
        if (Empty()){
            cout<<"there's nothing to delete..\n";
        }
        if (head->item==item){
            temp=head;
            head=head->next;
            temp->next=NULL;
            temp->prev= nullptr;
            delete temp;
            length--;
        }
        else{
            temp=head->next;
            while (temp!=NULL){
                if (temp->item==item){
                    break;
                }
                prev=temp;
                temp=temp->next;
                }
            if (temp==NULL)
                cout<<"item not found"<<endl;
            else{
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                if (tail==temp){
                    tail=prev;
                }
                delete temp;
                length--;
            }
            }

    }
    void print(){
        node *curr=head;
        while (curr!= nullptr){
            cout<<curr->item<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }
    void reversed(){
        node *temp=tail;
        cout<<"reversed ";
        while (temp!= nullptr){
            cout<<temp->item<<" ";
            temp=temp->prev;
        }
        cout<<endl;
    }
};

int main() {
    Doublelinkedlist l1;
    l1.insertAtHead(1);
    l1.insertAtHead(2);
    l1.insertAtHead(3);
    l1.print();
    l1.reversed();
    l1.del(3);
    l1.print();
    l1.insertAtpos(69,69);
    l1.insertAtpos(0,69);
    l1.insertAtpos(3,3);
    l1.print();

    return 0;
}

//
//#include <iostream>
//#include <cassert>
//#include <queue>
//#include<vector>
//
//
//#define boost ios_base::sync_with_stdio(0);
//using namespace std;
//
//struct com{
//    bool operator()(int l, int r) {
//        return l > r;
//    }
//
//};
//
//int main()
//{
//    boost;
//    priority_queue<int,vector<int>,com>pq;
//
//    for (int n : {50, 60, 70, 40, 10})
//        pq.push(n);
//
//    while (!pq.empty()) {
//        cout << pq.top() << endl;
//        pq.pop();
//    }
//    return 0;
//}