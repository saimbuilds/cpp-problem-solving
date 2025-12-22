#include<iostream>
using namespace std;

int sumOf3d(int matrix[][3][3]){
    int sum = 0;
    for(int i =0;i<3;i++){
        for(int j = 0;j<3;j++){
            for(int k =0;k<3;k++){
                sum+=matrix[i][j][k];
            }
        }
    }
    return sum;
}
int main(){
    int matrix[3][3][3] = {
    {   // Layer 0
        {1, 7, 3},
        {4, 0, 8},
        {2, 5, 6}
    },
    {   // Layer 1
        {9, 2, 1},
        {3, 7, 4},
        {0, 6, 5}
    },
    {   // Layer 2
        {8, 3, 2},
        {1, 9, 0},
        {7, 4, 6}
    }
};
    cout<<"Sum of 3d Array: "<<sumOf3d(matrix)<<endl;
}