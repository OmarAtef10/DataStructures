#include <iostream>
using namespace std;
class Stack{
    int top;
    int item[100];
public:
    Stack(){
        top=-1; //initial value.
    }
    void push(int elem){
        if(top>=100-1)
            cout<<"max size reached"<<endl;

        else{
            top++;
        item[top]=elem;

    }
    }
    void pop(){
        if (isEmpty())
            cout<<"empty stack"<<endl;
        else {
            top--;

        }
    }
    void pop(int &elem){
        if (isEmpty())
            cout<<"empty stack"<<endl;
        else {
            elem=item[top];
            top--;

        }
    }

    int getTop(int &S_Top){
        if (isEmpty())
            cout<<"empty stack"<<endl;
        else {
            S_Top=item[top];


        }
        return S_Top;
    }


    bool isEmpty(){
        if(top==0){
            return true;
        }
        else
            return false;
    }
    void print(){
        for (int i = top; i>=0 ; i--){
            cout<<item[i]<<" ";
        }
        cout<<endl;

    }
};
int main() {
Stack s;
s.push(5);
s.push(10);
s.push(15);
s.push(20);
s.print();
int top;
cout<<s.getTop(top);

    return 0;
}
