#include <iostream>
using namespace std;
void InsersionSort(int arr[],int n){
int key,j;

    for(int i=1;i<n;i++){
        key=arr[i];
        j=i-1;

        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;

        }
        arr[j+1]=key;
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
InsersionSort(arr,n);
print(arr,n);

    return 0;
}
