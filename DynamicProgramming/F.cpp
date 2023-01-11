#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>

#define MOD 1000000007

using namespace std;
int n, k;
long long a[100006];
long long b[100006];
long long res[100006];
// f[i][j] : buoc them i bac dang co j bac

void luyThua(){
    a[1] = 1;
    for(int i = 2;i <= 100006; i++){
        a[i] = (a[i - 1] * 2 ) % MOD;
    }
    b[1] = 1;
    for(int i = 2; i <= 100000; i++){
        b[i] = (b[i - 1] + a[i]) % MOD;
    }
}
void process(){
    for(int i = 1; i <= k; i++){
        res[i] = a[i];
    }
    for(int i = k + 1; i <= n; i++){
        if(i == k + 1){
            res[i] = b[i - 1] ;
        }
        else{
            res[i] = (2 * res[i - 1] % MOD - res[i - 1 - k] % MOD + MOD) % MOD;
        }
    }
    cout << res[n] << "\n";
}

int main(){
    int T;
    scanf("%d", &T);
    luyThua();
    while(T--){
        scanf("%d%d", &n, &k);
        process();
    }
    return 0;
}