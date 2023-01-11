#include<iostream>
#include<algorithm>
#include<stdbool.h>
#include<math.h>
#include<vector>
#include<map>
#define M 100006

using namespace std;
long long n, r, c;
long long tinh(long long dau, long long n, long long d) {
    long long cuoi = 0;
    cuoi = dau + (n - 1) * d;
    long long res = (dau + cuoi) * n / 2;
    return res;
}

void process() {
    long long res = 0;
    long long left = c - 1;
    long long right = n - c;
    if (left > right) {
        swap(left, right);
    }
    long long tang = 0;
    if (r + left <= n) {
        tang = r + left;
        res = tinh(1, left + 1, 2);
    
        right = right - left;

        while (tang + right > n) {
            right--;
        }
        res += tinh(1 + left * 2 + 1 , right, 1);
        tang += right;

        if (tang < n) {
            res += (n - tang) * n;
        }
    }
    else{
        left = left + r - n;
        if(r == n){
            res = 1;
        }
        else{
            res = tinh(1, left + 1, 2);
        }
        
    }

    cout << res;
    // cout << "\n";
}
int main() {
    int T;
    T = 1;
    while(T--){
        cin >> n >> r >> c;
        process();
    }
    
}
