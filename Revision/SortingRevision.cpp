#include <iostream>
using namespace std;
void inserstionSort(int arr[],int n){    ///insertionSort....
    int key,j;
    for (int i = 1; i < n; i++) {
        key=arr[i];
        j=i-1;
        while (j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void selectionSort(int arr[],int n){  ///selectionSort
    int min = 0;
    for (int i = 0; i < n-1; i++) {
        min=i;
        for (int j = i+1; j <n ; j++) {
            if (arr[j]<arr[min]){
                min=j;
                swap(arr[j],arr[i]);
            }
        }
    }
}

void bubbleSort(int arr[], int n){  ///bubbleSort
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if (arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
}

void shellSort(int nums[], int length) {   ///shellSort
    // Rearrange elements at each n/2, n/4, n/8, ... intervals
    for (int interval = length / 2; interval > 0; interval /= 2) {

        for (int i = interval; i < length; i++) {
            int key = nums[i];
            int j = i;

            while (j >= interval && nums[j - interval] > key) {
                nums[j] = nums[j - interval];
                j -= interval;
            }

            nums[j] = key;
        }
    }
}
void merge(int arr[], int left, int middle , int right){ ///mergeSort
    int a1 = middle-left+1;
    int a2 = right-middle;
    int *lft = new int[a1];
    int *rght = new int[a2];
    for (int i= 0; i <a1 ; ++i) {
        lft[i]=arr[left+i];
    }
    for (int i = 0; i < a2; ++i) {
        rght[i]=arr[middle+1+i];
    }
    int k = left;
    int i=0 , j =0;
    while (i<a1 and j<a2){
        if(lft[i]<=rght[j]){
            arr[k]=lft[i];
            i++;
        }
        else{
            arr[k]=rght[j];
            j++;
        }
        k++;
    }

    while (i<a1){
        arr[k]=lft[i];
        i++;
        k++;
    }
    while (i<a2){
        arr[k]=rght[i];
        i++;
        k++;
    }
}

void mergesort(int arr[],int l , int r){  ///MergeSort
    if (l<r){
        int m = l+(r-l)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int pivot(int arr[],int start , int end){ ///Quicksort
    int piv = arr[start];
    int i = start;
    int j = end;
    while (i<j) {
        do {
            i++;
        } while (arr[i] <= piv);
        do {
            j--;
        } while (arr[j] > piv);

        if (i < j)
        swap(arr[i], arr[j]);
    }
    swap(arr[start],arr[j]);
 return j;

}

void Quicksort(int arr[],int start , int end){
    if (start<end){
        int piv = pivot(arr,start,end);
        Quicksort(arr,start,piv);
        Quicksort(arr,piv+1,end);

    }
}

void heapify(int arr[] , int size , int index){ ///HeapSort
    int left = 2*index+1;
    int right = 2*index+2;
    int max = index;
    if (left<size and arr[left]>arr[max])
        max=left;
    if (right<size and arr[right]>arr[max])
        max=right;
    if (max != index){
        swap(arr[index],arr[max]);
        heapify(arr,size,max);
    }
}
void buildHeap(int arr[],int n){
    for (int i = n/2; i >=0 ; i--) {
        heapify(arr,n,i);
    }
}
void HeapSort(int arr[],int n){
    buildHeap(arr,n);
    for (int i = n-1; i >=0 ; i--) {
        swap(arr[0], arr[i]);
        heapify(arr,i,0);
    }
}

void display(int arr[],int n){
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}

int main() {
    int arr[5]={50,60,20,10,69};
    int n = sizeof(arr)/sizeof(arr[0]);
    //HeapSort(arr,5);
    Quicksort(arr,0,n);
    display(arr,n);

    return 0;
}
//
//#include <iostream>
//
//using namespace std;
//
//void print_arr(int nums[], int length){
//    for(int i = 0; i < length; i++){
//        cout << nums[i] << " ";
//    }
//    cout << endl;
//}
//
//void bubbleSort(int nums[], int length) {
//    for(int i = 0; i < length; i++){
//        bool swapped = false;
//        for(int j = 0; j < length - 1 - i; j++){
//            if(nums[j] > nums[j + 1]){
//                swap(nums[j], nums[j+1]);
//                // int temp = nums[j];
//                // nums[j] = nums[j+1];
//                // nums[j+1] = temp;
//                swapped = true;
//            }
//        }
//
//        if(!swapped){
//            break;
//        }
//    }
//
//    cout << "Sorted By Bubble Sort: ";
//    print_arr(nums, length);
//}
//
//
//void selectionSort(int nums[], int length) {
//    int minValue, minIndex;
//
//    // nums.length - 1 because the last element will already be in its sorted place no need for checking.
//    for(int i = 0; i < length - 1; i++){
//        minValue = nums[i];
//        minIndex = i;
//
//        for(int j = i + 1; j < length; j++){
//            // For descending order switch the sign
//            if(nums[j] < minValue){
//                minValue = nums[j];
//                minIndex = j;
//            }
//        }
//
//        swap(nums[i], nums[minIndex]);
//    }
//
//    cout << "Sorted By Selection Sort: ";
//    print_arr(nums, length);
//}
//
//
//
//
//void insertionSort(int nums[], int length){
//    int key;
//
//    for(int i = 1; i < length; i++){
//        key = nums[i];
//        int j = i;
//
//        // For descending order switch the sign
//        while(j >= 1 && nums[j - 1] > key){
//            nums[j] = nums[j - 1];
//            j--;
//        }
//
//        nums[j] = key;
//    }
//
//    cout << "Sorted By Insertion Sort: ";
//    print_arr(nums, length);
//
//}
//
//void shellSort(int nums[], int length) {
//    // Rearrange elements at each n/2, n/4, n/8, ... intervals
//    for (int interval = length / 2; interval > 0; interval /= 2) {
//
//        for (int i = interval; i < length; i++) {
//            int key = nums[i];
//            int j = i;
//
//            while (j >= interval && nums[j - interval] > key) {
//                nums[j] = nums[j - interval];
//                j -= interval;
//            }
//
//            nums[j] = key;
//        }
//    }
//    cout << "Sorted By Shell Sort: ";
//    print_arr(nums, length);
//}
//
//
//
//
//
//void merge(int nums[], int start, int mid, int end) {
//    int leftLength = mid - start + 1;
//    int rightLength = end - mid;
//
//    int* left = new int[leftLength];
//    int* right = new int[rightLength];
//
//    for(int i = 0; i < leftLength; i++){
//        left[i] = nums[start + i];
//    }
//
//    for(int j = 0; j < rightLength; j++){
//        right[j] = nums[mid + 1 + j];
//    }
//
//    int i = 0, j = 0, k = start;
//
//    while(i < leftLength && j < rightLength){
//        if(left[i] < right[j]){
//            nums[k] = left[i];
//            i++;
//        }else{
//            nums[k] = right[j];
//            j++;
//        }
//
//        k++;
//    }
//
//    while(i < leftLength){
//        nums[k] = left[i];
//        i++;
//        k++;
//    }
//
//    while(j < rightLength){
//        nums[k] = right[j];
//        j++;
//        k++;
//    }
//
//}
//
//
//void mergeSort(int nums[], int start, int end) {
//    if(start < end){
//        int mid = (start + end) / 2;
//        mergeSort(nums, start, mid);
//        mergeSort(nums, mid + 1, end);
//        merge(nums, start, mid, end);
//    }
//}
//
//
//void mergeSort(int nums[], int length) {
//    mergeSort(nums, 0, length - 1);
//    cout << "Sorted By Merge Sort: ";
//    print_arr(nums, length);
//}
//
//
//
//
//
//int partitionMiddle(int nums[], int start, int end, int pivot){
//    while(start <= end){
//        while(nums[start] < pivot){
//            start++;
//        }
//
//        while(nums[end] > pivot){
//            end--;
//        }
//
//        if(start <= end){
//            swap(nums[start], nums[end]);
//            start++;
//            end--;
//        }
//    }
//
//    //The right spliting (Pivot in place) position of the array
//    return start;
//}
//
//void quickSortMiddlePivot(int nums[], int start, int end){
//    if(start < end){
//        int pivot = nums[(start + end) / 2];
//
//        int pivotInRightPlaceIndex = partitionMiddle(nums, start, end, pivot);
//
//        quickSortMiddlePivot(nums, start, pivotInRightPlaceIndex - 1);
//        quickSortMiddlePivot(nums, pivotInRightPlaceIndex, end);
//
//    }
//}
//
//void quickSortMiddlePivot(int nums[], int length) {
//    quickSortMiddlePivot(nums, 0, length - 1);
//    cout << "Sorted By Quick Sort: ";
//    print_arr(nums, length);
//}
//
//
//
//
//int partitionEnd(int nums[], int low, int high) {
//
//    // select the rightmost element as pivot
//    int pivot = nums[high];
//
//    // pointer for greater element
//    int i = low;
//
//    // traverse each element of the array
//    // compare them with the pivot
//    for (int j = low; j < high; j++) {
//        if (nums[j] <= pivot) {
//
//            // if element smaller than pivot is found
//            // swap it with the greater element pointed by i
//
//            // swap element at i with element at j
//            swap(nums[i], nums[j]);
//            i++;
//        }
//    }
//
//    // swap pivot with the greater element at i
//    swap(nums[i], nums[high]);
//
//    // return the partition point
//    return i;
//}
//
//void quickSortEndPivot(int nums[], int start, int end){
//    if(start < end){
//
//        int pivotInRightPlaceIndex = partitionEnd(nums, start, end);
//
//        quickSortEndPivot(nums, start, pivotInRightPlaceIndex - 1);
//        quickSortEndPivot(nums, pivotInRightPlaceIndex + 1, end);
//
//    }
//}
//
//
//void quickSortEndPivot(int nums[], int length) {
//    quickSortEndPivot(nums, 0, length - 1);
//    cout << "Sorted By Quick Sort: ";
//    print_arr(nums, length);
//}
//
//
//
//int main(){
//    int nums[] = {21, 20, 32, 5, 6, 13, 8, 23};
//    int length = 8;
//    cout << "original array: ";
//    print_arr(nums, length);
//    bubbleSort(nums, length);
//    selectionSort(nums, length);
//    insertionSort(nums, length);
//    shellSort(nums, length);
//    mergeSort(nums, length);
//    quickSortMiddlePivot(nums, length);
//    return 0;
//}