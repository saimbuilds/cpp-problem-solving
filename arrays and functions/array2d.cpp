#include <iostream>
using namespace std;


void print2d(int arr[][3], int rows){
    for(int i =0;i<rows;i++){
        for(int j =0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
void printDiagonal(int arr[][3], int rows){
    for(int i =0;i<rows;i++){
        cout<<arr[i][i]<<" "<<endl;
    }
}

void printAntiDiagonal(int arr[][3], int rows){
    for(int i =0;i<rows;i++){
        cout<<arr[i][rows-1-i]<<" "<<endl;
    }
}
void spiralTraversal(int arr[][3], int rows, int cols){
    int top =0;
    int left = 0;
    int right = cols-1;
    int bottom = rows-1;
    while(top<=bottom && left<=right){
        // right
        for(int i = left;i<=right;i++){
            cout<<arr[top][i]<<" ";
        }
        top++;

        // down
        for(int i = top;i<=bottom;i++){
            cout<<arr[i][right]<<" ";
        }
        right--;
        // left
        if(top<=bottom){
            for(int i =right;i>=left;i--){
                cout<<arr[bottom][i]<<" ";
            }
            bottom--;
        }

        //up

        if(left<=right){
            for(int i = right;i>=top;i--){
                cout<<arr[i][left]<<" ";
            }
            left++;
        }
    }
}

void takeTranspose(int matrix[][3], int rows){
    for(int i=0;i<rows;i++){
        for(int j=i+1;j<rows;j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}
void matrixRotate90(int matrix[][3], int rows){
    takeTranspose(matrix, rows);
    for(int i =0;i<rows;i++){
        
            int left = 0;
            int right = rows-1;
            while(left<right){
                int temp = matrix[i][left];
                matrix[i][left] = matrix[i][right];
                matrix[i][right] = temp;

                left++;
                right--;

         
        }
    }
}
void printBoundaryElems(int matrix[][3], int rows, int cols){
    // top 
    for(int j=0;j<=cols-1;j++){
        cout<<matrix[0][j]<<" ";
    }
    cout<<endl;

    // bottom

    for(int j = 0;j<=cols-1;j++){
        cout<<matrix[rows-1][j]<<" ";
    }
    cout<<endl;

    // left
    for(int i = 0;i<=rows-1;i++){
        cout<<matrix[i][0]<<" ";
    }
    cout<<endl;

    // right
    for(int i =0;i<=rows-1;i++){
        cout<<matrix[i][cols-1]<<" ";
    }
    cout<<endl;
}
int sumOfBoundaryElems(int matrix[][3], int rows, int cols){
    int sum = 0;
    //top
    for(int j = 0;j<=cols-1;j++){
        sum+=matrix[0][j];
    }
    //bottom
    for(int j=0;j<=cols-1;j++){
        sum+=matrix[rows-1][j];
    }
    // left
    for(int i = 1;i<rows-1;i++){
        sum +=matrix[i][0];
    }
    // right
    for(int i =1;i<rows-1;i++){
        sum += matrix[i][cols-1];
    }
    return sum;
}

void sort2dArray(int matrix[][3], int rows, int cols){
    for(int i =0;i<rows;i++){
        for(int j=0;j<cols-1;j++){ // go over each row multiple times
            for(int k=0;k<cols-j-1;k++){ // compare and then swap
                if(matrix[i][k]> matrix[i][k+1]){
                    matrix[i][k] = matrix[i][k] ^ matrix[i][k+1];
                    matrix[i][k+1]=  matrix[i][k] ^ matrix[i][k+1];
                    matrix[i][k] = matrix[i][k] ^ matrix[i][k+1];

                }
            }

        }
    }
    print2d(matrix, rows);
}
void searchElemInSorted2d(int matrix[][3], int rows){
    print2d(matrix, rows);
    int target;
    cout<<"Enter the target: ";
    cin>>target;
    bool stop = false;
    for(int i =0;i<rows && !stop;i++){
        for(int j=0;j<3;j++){
            if(matrix[i][j] ==target){
                stop = true;
                cout<<target<<" found at ("<<i<<", "<<j<<")";
                break;
            }
        }
    }
}
void counterClockWise(int matrix[][3],int rows){
    cout<<"Before: "<<endl;
    print2d(matrix, rows);

    // transpose logic

    // for(int i =0;i<rows;i++){
    //     for(int j =i+1;j<3;j++){
    //         int temp = matrix[i][j];
    //         matrix[i][j] = matrix[j][i];
    //         matrix[j][i] = temp;

    //     }
    // }
    takeTranspose(matrix, rows);
    
    

    for(int j=0;j<3;j++){
        int top = 0;
        int bottom = rows-1;
        while(top<bottom){
            int temp = matrix[top][j];
            matrix[top][j] = matrix[bottom][j];
            matrix[bottom][j] = temp;

            top++;
            bottom--;
        }
    }
    cout<<"After: "<<endl;
    print2d(matrix, rows);

}
void printSpiral4x4(int matrix[][4] , int rows, int cols){
    int top = 0;
    int bottom = rows-1;
    int left = 0;
    int right = cols-1;

    while(top <= bottom && left <= right){
        // right
        for(int i = left; i <= right; i++)
            cout << matrix[top][i] << " ";
        top++;

        // down
        for(int i = top; i <= bottom; i++)
            cout << matrix[i][right] << " ";
        right--;

        // left
        if(top <= bottom){
            for(int i = right; i >= left; i--)
                cout << matrix[bottom][i] << " ";
            bottom--;
        }

        // up
        if(left <= right){
            for(int i = bottom; i >= top; i--)
                cout << matrix[i][left] << " ";
            left++;
        }
    }
}
int maxNumOf1(int matrix[][4], int rows, int cols){
    for(int i =0;i<rows;i++){
        for(int j=0;j<cols-1;j++){ // go over each row multiple times
            for(int k=0;k<cols-j-1;k++){ // compare and then swap
                if(matrix[i][k]> matrix[i][k+1]){
                    matrix[i][k] = matrix[i][k] ^ matrix[i][k+1];
                    matrix[i][k+1]=  matrix[i][k] ^ matrix[i][k+1];
                    matrix[i][k] = matrix[i][k] ^ matrix[i][k+1];

                }
            }

        }
    }
    int maxOnes = -1;
    int highestOneRowIdx = -1;
    for(int i =0;i<rows;i++){
        int oneCount = 0;
        for(int j =0;j<cols;j++){
            if(matrix[i][j] == 1){
                oneCount++;
            }
            
            if(oneCount>maxOnes){
                maxOnes = oneCount;
                highestOneRowIdx = i;
            }
        }
    }
    return highestOneRowIdx;

}
int main() {
    
    int rows = 3;
    int cols = 3;
    int matrix[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int matrix4[4][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    int matrix01[][4]= {
        0,0,1,1,0,1,1,1,0,0,0,1
    };
    // printDiagonal(matrix, 3);
    // printAntiDiagonal(matrix, 3);
    // spiralTraversal(matrix, rows, cols);
    // matrixRotate90(matrix, rows);
    // print2d(matrix, rows);
    // printBoundaryElems(matrix, rows, cols);
    // print2d(matrix, rows);
    // cout<<"THe sum of it's boundary elems are: "<< sumOfBoundaryElems(matrix, rows, cols);
    // sort2dArray(matrix, rows, cols);
    // searchElemInSorted2d(matrix, rows);
    // counterClockWise(matrix, rows);
    // printSpiral4x4(matrix4, 4, 4);
    // cout<<"Row "<<maxNumOf1(matrix01, 3, 4)+1<<" have the highest number of 1's";
    return 0;
}