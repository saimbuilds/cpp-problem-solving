#include <iostream>
using namespace std;
void printArray(int arr[], int size){
    int *ptr = arr;
    for(int i =0;i<size;i++){
        // cout<<*(ptr+i)<<" ";
        cout<<*ptr<<" ";
        ptr++;
        
    }
}
void printArrayViaPointers(int arr[], int size){
    int *start = arr;
    int *end = arr+5;
    for(int *ptr=start; ptr<end;ptr++){
        cout<<*ptr<<" ";
    }
}

void findTargetLocation(int arr[], int size, int target){
    bool isFound = false;
    int *ptr = arr;
    for(int i =0;i<size;i++){
        if(*ptr==target){
            isFound=true;
            cout<<"Target found at index: "<<i;
            break;
        }
        ptr++;
    }
}
int arraySum(int arr[], int size){
    int sum =0;
    int *ptr = arr;
    for(int i =0;i<size;i++){
        sum+=*ptr;
        ptr++;
    }
    return sum;
}

int findMax(int* arr, int size) {
    // Your code - no arr[i] notation allowed!
    int *ptr = arr;
    for(int i=0;i<size;i++){
        if(*(ptr+i)>*(ptr+i+1)){
            return *ptr;
        }
        ptr++;
    }
    return *ptr;
    
}
void printReverseArray(int arr[], int size){
    int end = size-1;
    int *ptr = arr+end;
    for(int i =end;i>=0;i--){
        cout<<*ptr<<" ";
        ptr--;
    }
}
int countOccurences(int arr[], int size, int target){
    int *ptr = arr;
    int count =0;
    for(int i =0;i<size;i++){
        if(*ptr==target) count++;
        ptr++;
    }
    return count;
}
// Test

int main(){
    // int arr[] = {1,2,3,4,5};
    // int size = 5;
    // int target = 3;
    // printArray(arr, size);
    // printArrayViaPointers(arr, size);
    // printReverseArray(arr, size);
    // findTargetLocation(arr, size, target);
    // cout<<"Array Sum: "<<arraySum(arr, size)<<endl;
    // cout << findMax(arr, 5);  
    // printReverseArray(arr, 5);
    int arr[] = {5, 3, 5, 7, 5, 2};
    cout << countOccurences(arr, 6, 5);
    return 0;
}