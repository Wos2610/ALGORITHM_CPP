#include<iostream>

using namespace std;

long long a[1006][1006];

void process(){
    long long m, n;
    scanf("%lld%lld", &m, &n);
    long long res = 0;
    
    for(int i = 0; i <= m + 1; i++){
        for(int j = 0; j <= n + 1; j++){
            a[i][j] = 0;
        }
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            scanf("%lld", &a[i][j]);
        }
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j] != 0){
                res++;
                if(a[i][j] > a[i][j - 1]){
                    res += (a[i][j] - a[i][j - 1]);
                }
                if(a[i][j] > a[i][j + 1]){
                    res += (a[i][j] - a[i][j + 1]);
                }
                if(a[i][j] > a[i - 1][j]){
                    res += (a[i][j] - a[i - 1][j]);
                }
                if(a[i][j] > a[i + 1][j]){
                    res += (a[i][j] - a[i + 1][j]);
                }
            } 
        }
    }

    printf("%lld\n", res);
}
int main(){
    int T;
    scanf("%d", &T);
    
    while(T--){
       process();
    }
    return 0;
}