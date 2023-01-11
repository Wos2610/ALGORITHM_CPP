#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>

#define MOD 1000000007

using namespace std;
long long n, k;
long long f[1006][1006];

void tinh(){
    for(int i = 0; i <= 1000; i++){
        f[0][i] = 1;
    }
    for(int i = 1; i <= 1000; i++){
        for(int j = 1; j <= 1000; j++){
            f[i][j] = ( f[i - 1][j - 1] + f[i][j - 1] ) % MOD;
        }
    }
}

int main(){
    int T;
    scanf("%d", &T);
    tinh();
    while(T--){
        scanf("%lld%lld", &n, &k);
        printf("%lld\n", f[k][n]);
    }
    return 0;
}