#include<iostream>
#include<algorithm>
#include<queue>
#define M 1000006

using namespace std;

queue <int> q;

int main(){
    long long n;
    cin >> n;
    if(n <= 5){
        cout << n;
        return 0;
    }

    long long m = n;
    long long temp = 1;
    long long tmp = 0;
    while(1){
        tmp += temp * 5;
        if(tmp >= n){
            break;
        }
        else{
            if(m > temp * 5){
                m -= temp * 5;
            }
            else{
                break;
            }
            temp *= 2;
        }
        
    }
    long long res = 0;
    if(m % temp == 0){
        res = m / temp;
    }
    else{
        res = m / temp + 1;
    }
    cout << res;
}
