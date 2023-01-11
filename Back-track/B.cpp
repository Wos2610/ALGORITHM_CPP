#include<iostream>

using namespace std;
#define M 1000006

int m, n;
long long a[26][26], b[26][26];

void Try(int i, int j){
    if(b[i][j] > 0){
        return;
    }
    Try(i - 1, j);
    Try(i, j - 1);

    b[i][j] = b[i - 1][j] + b[i][j - 1];
}

void process(){
    scanf("%d%d", &m, &n);
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            scanf("%lld", &a[i][j]);
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(i == 1 || j == 1){
                b[i][j] = 1;
            }
            else{
                b[i][j] = 0;
            }
        }
    }

    Try(m, n);
    
    printf("%lld\n", b[m][n]);
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        process();
    }
}
    