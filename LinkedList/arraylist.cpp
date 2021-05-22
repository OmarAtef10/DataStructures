#include <iostream>
using namespace std;
class arraylist{
private:
    int* arr;
    int maxsize;
    int length;

public:
    arraylist(int s=10){
        if (s<0){
            maxsize=10;
        }
        else maxsize=s;
        length=0;
        arr=new int [maxsize];

    }
    bool isempty(){
        return length==0;
    }

    bool isfull(){
        return length==maxsize;

    }
    int getsize(){
        return length;

    }
    void print (){
        for (size_t i=0;i<length;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void insertAtPos(int pos , int elem){
        if(isfull())
            cout<<"list is full"<<endl;
        else if(pos<0 or pos >length)
            cout<<"Out of range"<<endl;
        else{
            for (size_t i =length ; i>pos;i--){
                arr[i]=arr[i-1];

            }
            arr[pos]=elem;
            length++;
        }
    }
    void insertAtEnd(int elem){
        if (isfull()){
            cout<<"full list"<<endl;
        }
        else arr[length]=elem;
        length++;
    }
    void DeleteElem(int pos ){
        if(isempty()){
            cout<<"empty list"<<endl;
        }
        else if(pos<0 or pos > length){
            cout<<"out of range"<<endl;

        }
        else {
            for (size_t i = pos;i<=length;i++){
                arr[i]=arr[i+1];
            }
            length--;
        }
    }
    ~arraylist(){
        delete [] arr;
    }
};

int main() {
    arraylist ar(100);
    ar.isempty();
    ar.insertAtPos(0,10);
    ar.insertAtPos(1,20);
    ar.insertAtPos(2,30);
    ar.insertAtEnd(40);
    cout<<ar.getsize()<<endl;
    ar.DeleteElem(0);
    cout<<ar.getsize()<<endl;
    ar.print();
    return 0;
}
