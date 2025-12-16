#include<iostream>
using namespace std;
int factorial(int n){
    if(n==0 || n==1){
        return 1;
    }
    return n*factorial(n-1);
}
void printTo1(int n){
    if(n==0) return;
    cout<<n<<" ";
    printTo1(n-1);
}
void print1toN(int n){
    if(n==0) return;
    print1toN(n-1);
    cout<<n<<" ";
}
int sumOfN(int n){
    if(n==0) return 0;
    return n+sumOfN(n-1);
}
void printOdd(int n){
    if(n==0) return;
    printOdd(n-1);
    cout<<2*n-1<<" ";
}
void printEven(int n){
    if(n==0) return;
    printEven(n-1);
    cout<<2*n<<" ";

}
void reverseNumber(int n){
    if(n<=0) return;
    cout<<n%10;
    reverseNumber(n/=10);
}
int main(){
    int n =54321;
    
    // printTo1(n);
    // print1toN(n);
    // cout<<sumOfN(n);
    // printOdd(n);
    // printEven(5);
    reverseNumber(n);

    return 0;
}