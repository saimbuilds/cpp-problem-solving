
#include <iostream>
using namespace std;




void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Print 2D array
void printMatrix(int matrix[][100], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// void reverseArray(int arr[], int n){
//     int left = 0;
//     int right = n-1;
//     while(left<right){
//         int temp  = arr[left];
//         arr[left] = arr[right];
//         arr[right] = temp;
//         left++;
//         right--;
//     }

// }
int maxSumofKElements(int arr[], int n, int k){
    // Step 1: calculate the sum of window
    int windowSum = 0;
    for(int i =0;i<k;i++){
        windowSum += arr[i];
    }

    int maxSum = windowSum;
    for(int i =k;i<n;i++){
        // remove the left most element of the window and then add the right most elem of the new window after sliding it by 1;
        windowSum = windowSum - arr[i-k] + arr[i];
        if(windowSum>maxSum){
            maxSum = windowSum;
        }
    }
    return maxSum;
}
void buildPrefixSum (int arr[], int prefix[], int n){
    prefix[0] = arr[0];
    for(int i =1;i<n;i++){
        prefix[i] = prefix[i-1] + arr[i];
    }
}
int rangeSum(int prefix[], int l, int r){
    if(l==0) return prefix[r];
    return prefix[r] - prefix[l-1];
}
int kadaneAlgo(int arr[], int n){
    int currentSum = arr[0];
        int maxSum = arr[0];
        for(int i =1;i<n;i++){
            if(arr[i]>currentSum+arr[i]){
                currentSum = arr[i];
            }else{
                currentSum +=arr[i];
            }

            if(currentSum>maxSum){
                maxSum = currentSum;
            }
        }
        return maxSum;
}
int max(int a, int b){
    if(a>b){
        return a;
    }
    else
        return b;
    
}
int min(int a, int b){
    if(a>b){
        return b;
    }else return a;
}

int secondLargest(int arr[], int n){
    if(n<-2)  return -1; // because how tf i can find 2nd largest?
    int large = max(arr[0], arr[1]);
    int large2 = min(arr[0], arr[1]);
    
    for(int i =2;i<n;i++){
        if(arr[i]>large){
            large2 = large;
            large = arr[i];
        }
        else if(arr[i]>large2 && arr[i] !=large){
            large2 = arr[i];
        }
    }
    return large2;
}
void reverseArray(int arr[], int n, int left, int right){
    // int left = 0;
    // int right = n-1;
    while (left<right){
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right]  =temp;
        left++;
        right--;
    }
    

}
void bubbleSort(int arr[], int n){
    // compare two adjacent elements and swap them if it's largest, in this way at eahc iteration the largest will move to the end
    for(int i =0;i<n-1;i++){
        for(int j =0;j<n-i-1;j++){
            if(arr[j]> arr[j+1]){
                arr[j]  = arr[j]  ^ arr[j+1];
                arr[j+1] = arr[j]  ^ arr[j+1];
                arr[j]=  arr[j]  ^ arr[j+1];
            }
        }
    }
}
int removeDuplicateFromSortedArray(int arr[], int n){
    if(n==0 ||n ==1) {
        return n;
    }

    int i = 0;
    for(int j=1;j<n;j++){
        if(arr[j] != arr[i]){
            i++;
            arr[i] = arr[j];
        }
    }
    return i+1;

}
int main() {
    // int arr[] = {3, 1, 4, 1, 5, 3, 3, 2, 1};
    // int n = 9;  
    // int freq[11] = {0};
    // for(int i = 0; i < n; i++) {
    //     cout << arr[i] << " ";
    //     freq[arr[i]]++;  // Increment count for this value
    // }
    // cout << endl << endl;
    // for(int i = 0; i <= 10; i++) {
    //     if(freq[i] > 0) {
    //         cout << i << " appears " << freq[i] << " time(s)" << endl;
    //     }
    // }

    
    // cout<<"Before rotation: ";
    // printArray(arr, n);
    // int k;
    // cout<<"Enter the k: ";
    // cin>>k;
    // k=k%n;
    // reverseArray(arr, n, 0, n-1);
    // reverseArray(arr, n, 0, k-1);
    // reverseArray(arr, n, k, n-1);
    // printArray(arr, n);
    int arr[] = {1, 1, 2, 2, 3, 4, 4};
    int n = 7;
    cout<<"Before Duplication: ";
    printArray(arr, n);
    cout<<"After Duplication: ";
    int newlength = removeDuplicateFromSortedArray(arr, n);
    printArray(arr, newlength);
    
    return 0;
}

