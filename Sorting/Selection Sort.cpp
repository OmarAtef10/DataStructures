#include <iostream>
using namespace std;
void SelectionSort(int arr[],int n){
    int min=0;
    for (int i = 0 ; i<n-1;i++){
        min = i;
        for(int j = i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
                swap(arr[min],arr[i]);

            }
        }
    }
    for(int i =0 ;i<n;i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;

}
/*void print(int arr[],int size){
for(int i =0 ;i<size;i++){
    cout<<arr[i]<<" ";

}
cout<<endl;
}*/

int main() {
int arr[]={3,2,1,69};
int n = sizeof(arr)/sizeof(arr[0]);
SelectionSort(arr,n);
//print(arr,n);

    return 0;
}
