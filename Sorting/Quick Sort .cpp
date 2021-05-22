#include<iostream>
using namespace std;

int partition(int arr[] , int start , int end) {
    int piv = arr[start];
    int i = start;
    int j = end;
    while (i < j)
    {
        do
        {
            i++;
        } while (arr[i] <= piv);
        do
        {
            j--;
        } while (arr[j] > piv);

        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[start], arr[j]);
    return j;
}
void QuickSort( int arr[], int start, int end){
    if (start<end){
        int piv = partition(arr,start,end);
        QuickSort(arr , start, piv);
        QuickSort(arr,piv+1,end);
    }

}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

}
int main()
{
int arr[] = { 2,69,-1,4,-7,5};
int n = sizeof(arr)/sizeof(arr[0]);
QuickSort(arr,0,n);
print(arr,n);
}