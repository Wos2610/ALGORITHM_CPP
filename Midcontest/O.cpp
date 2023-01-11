#include<iostream>
#include<algorithm>
#include<vector>
#define M 1000006

using namespace std;

long long n, k;

string a[3] = "ABC";

void chuyen(int n, int i, int j){
    if(n == 1){
        cout << a[i] << " " << a[j];
    }
    else{
        chuyen(n - 1, 1, 2);
        chuyen(1, 1, 3);
        chuyen(n - 1, 2, 3);
    }
}

int main(){
    while(1){
        cin >> n >> k;
        if(n == 0 && k == 0){
            return 0;
        } 
        chuyen(n, i, j);
    }
    
}
