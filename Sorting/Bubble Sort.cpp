#include <iostream>
using namespace std;
void BubbleSort(int arr[],int n){
    for (int i=0;i<n-1;i++){

       for(int j=0;j<n-i-1;j++)

        if (arr[j]>arr[j+1]){ //lw 3ayez descending e2leb el comparison

            swap(arr[j],arr[j+1]);
        }
    }
}


void print(int arr[],int size){
for(int i =0 ;i<size;i++){
    cout<<arr[i]<<" ";

}
cout<<endl;
}

int main() {
int arr[]={50,60,20,69};
int n = sizeof(arr)/sizeof(arr[0]);
BubbleSort(arr,n);
print(arr,n);

    return 0;
}
