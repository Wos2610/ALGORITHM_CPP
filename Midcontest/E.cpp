#include<iostream>

#define M 1000006

using namespace std;

int n;
long long a[M], p[M];
long long m = -1;

void check(long long x, int n){
    long long temp = p[n - 1];
    if(x == temp){
        cout << n << " ";
    }
    else if(x < temp){
        check(x, n - 1);
    }
    else{
        x -= temp;
        check(x, n - 1);
    }
}
int main(){
    cin >> n;

    p[0] = 1;

    for(int i = 1; i <= 60; i++){
        p[i] = p[i - 1] * 2;
    }
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        check(a[i], 60);
    }


}
    