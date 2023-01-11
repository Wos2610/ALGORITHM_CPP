#include<iostream>
#include<vector>

using namespace std;

vector<int> a(1000006, 0);
int mark = 0;

void TH(int n, int k){
    int i = k;
    while(i >= 1 && a[i] == n - k + i){
        i--;
    }
    if(i == 0){
        mark = 1;
    }
    else{
        a[i]++;
        for(int j = i + 1; j <= k; j++){
            a[j] = a[j - 1] + 1;
        }
    }
}

void process(){
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= k; i++){
        a[i] = i;
    }
    while(mark == 0){
        for(int i = 1; i <= k; i++){
            printf("%d", a[i]);
        }
        printf(" ");
        TH(n, k);
    }
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        process();
        printf("\n");
        mark = 0;
    }
    return 0;
}