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
int main() {
    
    int rows = 3;
    int cols = 3;
    int matrix[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    // printDiagonal(matrix, 3);
    // printAntiDiagonal(matrix, 3);
    // spiralTraversal(matrix, rows, cols);
    // matrixRotate90(matrix, rows);
    // print2d(matrix, rows);
    // printBoundaryElems(matrix, rows, cols);
    // print2d(matrix, rows);
    // cout<<"THe sum of it's boundary elems are: "<< sumOfBoundaryElems(matrix, rows, cols);
    
    return 0;
}