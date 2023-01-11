#include<iostream>
#include<vector>
#define M 46
using namespace std;



void process(){
    int a[M] = {0};
    int b[M] = {0};

    int n,k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= k; i++){
        scanf("%d", &a[i]);
        b[i] = a[i];
    }


    int i = k;
    while(i >= 1 && a[i] == n - k + i){
        i--;
    }
    
    if(i == 0){
        printf("%d\n", k);
        return;
    }

    a[i]++;
    for(int j = i + 1; j <= k; j++){
        a[j] = a[j - 1] + 1;
    }

    int count = 0;
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= k; j++){
            if(b[j] == a[i]){
                count++;
                break;
            }
        }
    }
    printf("%d\n", k - count);

}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        process();
    }
    
    return 0;
}