#include<iostream>
#define MOD 1000000007

using namespace std;

long long pow(long long n, long long k){
    if(k == 0){
        return 1;
    }
    else if(k % 2 == 0){
        long long temp = pow(n, k/2);
        return (temp * temp)%MOD;
    }
    else {
        long long temp = pow(n, k/2);
        return((temp * temp)%MOD * (n % MOD))%MOD;
    }
}
void process(){
    long long n, k;
    cin >> n >> k;
    cout << pow(n, k) << "\n";
}
int main(){
    int T;
    cin >> T;
    while(T--){
        process();
    }
    return 0;
}
