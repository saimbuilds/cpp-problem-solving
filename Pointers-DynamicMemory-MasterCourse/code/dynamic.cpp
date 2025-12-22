#include<iostream>
using namespace std;
int **createArr(int rows, int cols){
    int **arr = new int*[rows];
    for(int i =0;i<rows;i++) arr[i] = new int[cols];

    cout<<"Enter ELems: ";
    for(int i =0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>arr[i][j];
        }
    }

    cout<<"yourarray: "<<endl;
     for(int i =0;i<rows;i++){
        for(int j=0;j<cols;j++){
             cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    // taking transpose

    for(int i =0;i<rows;i++){
        for(int j=0;j<cols;j++){
             arr[i][j] = arr[j][i];
        }
    }

    // after taking transpose
    cout<<"yourarray after taking transpose: "<<endl;
     for(int i =0;i<rows;i++){
        for(int j=0;j<cols;j++){
             cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return arr;
}
int **addMatrices(int **a, int **b, int rows, int cols){
    int **result = new int*[rows];
    for(int i =0;i<rows;i++) {
        result[i] = new int[cols];
        for(int j =0;j<cols;j++){
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    return result;
        
    
}
void dealocate2d(int **arr, int rows){
    for(int i=0;i<rows;i++) delete[] arr[i];
    delete[] arr;
}
int main(){
    int rows, cols;
    cout<<"Enter rows and cols : ";
    cin>>rows>>cols;
    // int **arr = createArr(rows, cols);
    int **a = new int *[rows];
    int **b = new int *[rows];
      for(int i =0;i<rows;i++) {
        a[i] = new int[cols];
        b[i] = new int[cols];
        for(int j =0;j<cols;j++){
            a[i][j] = i+j+8;
            b[i][j] = i+j+15;
        }
    }

    for(int i =0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i =0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    int **addition = addMatrices(a,b,rows,cols);
     cout<<endl;
    for(int i =0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<addition[i][j]<<" ";
        }
        cout<<endl;
    }
    dealocate2d(a,rows);
    dealocate2d(b,rows);
    dealocate2d(addition,rows);
      for(int i =0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
}