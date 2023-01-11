#include<iostream>

using namespace std;

int a[1000006];

void TH(int n, int k){
    int i = k;
    while(i >= 1 && a[i] == n - k + i){
        i--;
    }
    if(i == 0){
        i = 1;
        a[i] = 1;
    }
    else{
        a[i]++;
    }
    for(int j = i + 1; j <= k; j++){
        a[j] = a[j - 1] + 1;
    }
}

void process(){
    int n,k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= k; i++){
        scanf("%d", &a[i]);
    }
    TH(n, k);
    for(int i = 1; i <= k; i++){
        printf("%d ", a[i]);
    }
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        process();
        printf("\n");
    }
    return 0;
}