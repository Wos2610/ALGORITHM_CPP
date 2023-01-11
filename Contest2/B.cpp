#include<iostream>
#include<vector>
#define M 1000006
using namespace std;

vector<int> mark(M, 0);
vector<int> save;

void sieve(){
    mark[0] = mark[1] = 0;
    for(int i = 2; i * i <= M; i++){
        if(mark[i] == 0){
            for(int j = i * i; j <= M; j += i){
                mark[j] = 1;
            }
        }
    }
}

int main(){
    int T;
    scanf("%d", &T);
    sieve();
    for(int i = 2; i <= M; i++){
        if(mark[i] == 0){
            save.emplace_back(i);
        }
    }

    int a = save.size();
    while(T--){
        int n;
        scanf("%d", &n);
        for(int i = 0; i < a; i++){
            if(save[i] < n){
                printf("%d ", save[i]);
            }
        }
        printf("\n");
    }
    return 0;
}