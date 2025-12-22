#include <iostream>
using namespace std;
void transform(int** matrix, int n, int& trace) {
    trace = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                trace += matrix[i][j];
            matrix[i][j] = matrix[i][j] + i - j;
        }
    }
}

int main() {
    int** m = new int*[3];
    for (int i = 0; i < 3; i++) {
        m[i] = new int[3];
        for (int j = 0; j < 3; j++){
            m[i][j] = i * 3 + j + 1;
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    
    int tr;
    transform(m, 3, tr);
    // cout << tr << " " << m[1][1];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    for (int i = 0; i < 3; i++)
        delete[] m[i];
    delete[] m;
    return 0;
}









