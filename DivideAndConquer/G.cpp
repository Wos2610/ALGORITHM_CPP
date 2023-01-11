#include<iostream>
#define M 10000006

using namespace std;

int m, n;
long long p[100], q[100];

void sum(){
    long long a[100006] = {0};
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            a[i + j] += p[i] * q[j];
        }
    }

    for(int i = 0; i < m + n - 1; i++){
        printf("%lld ", a[i]);
    }
    printf("\n");
}

void process(){
    scanf("%d%d", &m, &n);
    for(int i = 0; i < m; i++){
        scanf("%lld", &p[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%lld", &q[i]);
    }
    sum();
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        process();
    }
    return 0;
}