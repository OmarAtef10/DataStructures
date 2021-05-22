#include <iostream>
#include <cassert>
using namespace std;
class Queue{
private:
   // static const int max=100;

    int rear, front,length;
    int *arr;
    int maxSize;
public:
    Queue(int size){

        maxSize=size;
        arr=new int [maxSize];
        length=0;
        front=0;
        rear=maxSize-1;

    }
    bool Empty(){
        return length==0;

    }
    bool Full(){
        return length==maxSize;

    }
    void enqueue(int elem){
        if (Full())
            cout<<"Full Queue"<<endl;
        else{
            rear=(rear+1)%maxSize;
            arr[rear]=elem;
            length++;
        }

    }
    void dequeue(){
        if(Empty())
            cout<<"Empty Queue"<<endl;
        else{
            front=(front+1)%maxSize;
            length--;

        }
    }
    int Front(){
        if (Empty())
            cout<<"Empty Queue"<<endl;
        else
        return arr[front];
    }
    int Rear(){
        assert(!Empty());
        return arr[rear];
    }
    void print(){
        if (Empty())
            cout<<"Empty Queue"<<endl;
        else{
        for(int i = front ;i!=rear;i=(i+1)%maxSize){
            cout<< arr[i]<<" ";
        }
        cout<<arr[rear]; //if the for loop ends at rear only (not +1)
        cout<<endl;
    }
    }
    int Search(int elem){
        int pos =-1;
        if(!Empty()){
            for(int i =front;i!=rear;i=(i+1)%maxSize){
                if (arr[i]==elem){
                    pos=i;
                    break;
                }
                if (pos==-1){
                    if (arr[rear]==elem)
                        pos=rear;
                }
            }
        }
        else{
            cout<<"Empty queue"<<endl;

        }
        if(pos==-1){
            cout<<"not found"<<endl;
        }
        return pos;
    }
};
int main() {
Queue Q1(5);
Q1.enqueue(1);
Q1.enqueue(2);
Q1.enqueue(3);
Q1.enqueue(4);
Q1.enqueue(5);
Q1.enqueue(6);

Q1.print();
Q1.dequeue();
Q1.print();
cout<<Q1.Search(5);
    return 0;
}
