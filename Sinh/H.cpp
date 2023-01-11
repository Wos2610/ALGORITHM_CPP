#include<iostream>
#include<vector>

using namespace std;

int a[1030][1030];

int pow(int a, int b){
    int res = 1;
    for(int i = 1; i <= b; i++){
        res *= a;
    }
    return res;
}

void Gray(int n, int end){
    int k = 1;
    for(int i = 1; i <= n; i++){
        k = pow(2, i);
        for(int j = 1; j <= k; j++){
            if(j > k/2){
                a[j][i] = 1;
            }
        }
        int b = k + 1;
        int c = b + k - 1;
        while(c <= end){
            for(int j = b; j <= c; j++){
                a[j][i] = a[c - j + b - k][i];
            }
            b += k;
            c += k;
        }
    }
}



void process(){
    int n;
    scanf("%d", &n);
    int end = pow(2,n);
    Gray(n, end);
    
    for(int i = 1; i <= end; i++){
        for(int j = n; j >= 1; j--){
            printf("%d", a[i][j]) ;
        }
        printf(" ");
    }
    printf("\n");
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
         process();
    }
    return 0;
}