#include<iostream>
#define M 1000006
using namespace std;

int a[M];
int mark[M];


void process(){
    int n,m,k;
    scanf("%d%d%d", &n,&m, &k);

    for(int i = 0; i < m; i++){
        scanf("%d", &a[i]);
        for(int j = a[i] - k; j <= a[i] + k; j++){
            if(j >= 1){
                mark[j] = 1;
            }
        }
    }

    int count = 0;
    for(int i = 1; i <= n; i++){
        if(mark[i] == 0){
            int l = i;
            int r = i + 1;
            while(r <= n && mark[r] == 0){
                r++;
            }
            int temp = (r - 1 - l)/(2*k + 1);
            count += temp + 1;
            for(int j = l; j <= r; j++){
                mark[j] = 1;
            }
        }
    }
    cout << count;
}

int main(){
    process();
    return 0;
}