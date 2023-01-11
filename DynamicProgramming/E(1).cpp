#include<iostream>
#include<algorithm>
#include<vector>
#define MOD 1000000007

using namespace std;
int n;
vector<long long> f(10006, 999999999999999999);

int b[3] = {2, 3, 5};

void process(){
    f[1] = 1;
    for(int i = 2; i <= 10000; i++){
        for(int j = 1; j <= i - 1; j++){
            for(int k = 0; k <= 2; k++){
                long long x = f[j] * b[k];
                if(x > f[i - 1]){
                    f[i] = min(f[i], x);
                }
            }
        }
    }
}

int main(){
    int T;
    scanf("%d", &T);
    process();
    while(T--){
        scanf("%d", &n);
        printf("%lld\n", f[n]);
    }
    return 0;
}