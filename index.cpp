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



   
    // cout<<"Enter size: ";
    // cin>>size;
    // for(int i =0;i<size;i++){
    //     cin>>arr[i];
    // }
    int arr[3][3] = {
        {1, 2, 3},
        {5, 6, 7},
        {9, 10, 11}
    };
//    for(int i = 0;i<3;i++) cout<<arr[i][i]<<" ";
//    cout << "\nSecondary Diagonal: ";
//    for(int i =0;i<3;i++) cout<<arr[i][2-i]<<" ";
    // for(int i =0;i<3;i++){
    //     for(int j=0;j<3;j++){
    //         if(i==j){
    //             cout<<arr[i][j]<<" ";
    //         }
    //     }
    // }
    // for(int i =0;i<3;i++){
    //     for(int j=0;j<3;j++){
    //         if((i+j)==3-1){
    //             cout<<arr[i][j]<<" ";
    //         }
    //     }
    // }
    

    
    return 0;

}   