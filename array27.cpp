#include<iostream>
#include<string>
using namespace std;
int digitProduct(int n) {
    int product = 1;

    while (n > 0) {
        product *= n % 10;
        n /= 10;
    }

    return product;
}

int main(){
    int n=15 , t=4;

    int number=-1;

    while(true){
        int product =digitProduct(n);
        if (product%t==0){
            number=n;
            break;
        }else{
            n++;
        }
    }
}