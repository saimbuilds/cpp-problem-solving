#include<iostream>
using namespace std;
bool isPrimeFunc(int n){
    if(n<=1) return false;
    if(n==2) return true;
    if ((n&1)==0) return false;
    for(int i =3;i*i<=n;i+=2){
        if(n%i==0){
            return false;
        }

    }
    return true;
}
void reverseArray(int arr[], int n){
    int left =0;
    int right = n-1;
    while(left<right){
        arr[left] = arr[left] ^ arr[right];
        arr[right] = arr[left] ^ arr[right];
        arr[left] = arr[left] ^ arr[right];
        left++;
        right--;
    }
}
void printArray(int arr[],int n){
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int findGcd(int a, int b){
    while (b!=0){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}
bool symmetric(int arr[][3]){
    for(int i =0;i<3;i++){
        for(int j = i+1;j<3;j++){
            if(arr[i][j] != arr[j][i]){
                return false;
            }
        }
    }
    return true;
}

void merge2Arrays(int arr1[], int arr2[],int arr3[], int size1, int size2){
    
   int i  = 0, j=0, k=0;
   while(i<size1 && j<size2){

        if(arr1[i]<arr2[j]){
            arr3[k] = arr1[i];
            i++;
        }else{
            arr3[k] = arr2[j];
            j++;
        }
        k++;
        // copying remainig elems of arr1
        
        // copying remaining elems of arr2
    }
    
    while(i<size1){
        arr3[k] = arr1[i];
        k++;
        i++;
    }
    
    while(j<size2){
        arr3[k]= arr2[j];
        k++;
        j++;
    }
}
void removeDuplicate(int arr[], int n){
    for(int i =0;i<n;i++){
        for(int j =i+1;j<n;j++){
            if(arr[i]==arr[j]){
                // now duplicate is found do left shit of array
                for(int k =j;k<n-1;k++){
                    arr[k] = arr[k+1]; // copy the next item
                }
                n--; //reduces the arary size
                j--; // j should point the original siz;e
            }
        }
        
    }
     // print result
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
void removeDuplicateSortedArr(int arr[],int n){
    // step1: do sorting
    for(int i =0;i<n-1;i++){
        for(int j =0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                arr[j]  = arr[j]  ^ arr[j+1];
                arr[j+1] = arr[j]  ^ arr[j+1];
                arr[j]=  arr[j]  ^ arr[j+1];
            }
        }
    }

    int k = 1; //since 0 pr to already unique elem ho ga
    for(int j=1;j<n;j++){
        if(arr[j]!=arr[k-1]){ //duplicate mil gya 
            arr[k] = arr[j];
            k++;
        }
    }

    for(int i =0;i<k;i++) cout<<arr[i]<<" ";
}
int main(){
    int arr1[] = {1,1,2,4,2,3,5,2,4,2};
    // removeDuplicate(arr1, 10);
    removeDuplicateSortedArr(arr1,10);
    return 0;
}