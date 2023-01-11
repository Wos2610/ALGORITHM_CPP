#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<queue>
#define MOD 1000000007

using namespace std;
int n;
long long a[2006];
long long f[2006][2006];

void process(){
    for(int i = n; i >= 1; i--){
        for(int j = i + 1; j <= n; j++){
            f[i][j] = min(f[i + 1][j], f[i][j - 1]) + a[j] - a[i];
        }
    }
    cout << f[1][n];
}

int main(){
    int T;
    T = 1;
    
    while(T--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        process();
    }
    return 0;
}