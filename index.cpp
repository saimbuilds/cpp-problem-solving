#include <iostream>
#include <cmath>
using namespace std;
void modifyArr(int arr[], int size){
    arr[9] = 69;
}
void printArr(int arr[], int size){
    for(int i =0;i<size;i++){
        cout<<arr[i]<<"  ";
    }
}
int findMax(int arr[], int size){
    int max = arr[0];
    for(int i =1;i<size;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}
int findMin(int arr[], int size){
    int min = arr[0];
    for(int i =1;i<size;i++){
        if(arr[i]<min){
            min = arr[i];
        }
    }
    return min;
}
int linearSearchIdx (int arr[], int size, int toFind){
    int idx = -1;
    for(int i =0;i<size;i++){
        if(arr[i]==toFind){
            idx = i;
            break;
        }
    }
    return idx;
}
void reverseArr(int arr[], int size){
    for(int i =0;i<size/2;i++){
        int temp =  arr[i];
        arr[i]  = arr[size - i-1];
        arr[size - i-1] = temp;
    }
}
int main() {
    // int arr[100];
    // int size;
    // cout<<"Enter size: ";
    // cin>>size;
    // for(int i =0;i<size;i++){
    //     cin>>arr[i];
    // }
    
    // for(int i =0;i<size;i++){
    //     cout<<arr[i];
    // }
  
    // int arr[10]= {1,2,3,4,5,6,7,8,9,10};
    // modifyArr(arr, 10);
    // cout<<arr[9];


    int arr[10];
    int size;
    cout<<"Enter size: ";
    cin>>size;
    for(int i =0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"Before Reverse: "<<endl;
    printArr(arr, size);
    cout<<"\n After Reverse: "<<endl;
    reverseArr(arr, size);
    printArr(arr, size);
    
    return 0;

}   