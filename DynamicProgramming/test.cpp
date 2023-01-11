#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
#include<deque>
#define MOD 1000000007

using namespace std;
int n, k;
long long g[100006];
// f[i][j] : buoc them i bac dang co j bac
vector<long long> f;

void process(){
    for(int i = 1; i <= n; i++){
        g[i] = 0;
    }
    f.push_back(0);
    f.push_back(1);
    for(int i = 2; i <= n; i++){
        f[i] = f[i - 1] + f[i  1];
    }

    
    printf("%lld\n", g[n]);
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &k);
        process();
    }
    return 0;
}