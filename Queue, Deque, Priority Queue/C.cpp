#include<iostream>
#include<algorithm>
#include<queue>
#define M 1000006
using namespace std;

int n, s, t;
int a[M], mark[M], d[M], kc[M];


void sieve(){
    for(int i = 2; i * i <= M; i++){
        if(mark[i] == 0){
            for(int j = i * i; j <= M; j += i){
                mark[j] = 1;
            }
        }
    }
}

void process(){
    queue <int> q;
    q.push(s);
    d[s] = 1;
    while(q.size() != 0){
        int u = q.front();
        q.pop();
        int v = u;
        // cs[4] cs[3] cs[2] cs[1]
        int cs[5];
        for(int i = 1; i <= 4; i++){
            cs[i] = v % 10;
            v /= 10;
        }
        
        // Hàng đơn vị
        for(int i = 1; i <= 9; i++){
            v = u - cs[1] + i;
            if(mark[v] == 0 && d[v] == 0){
                q.push(v);
                d[v] = 1;
                kc[v] = kc[u] + 1;
            }
            if(v == t){
                break;
            }
        }
        
        // Hàng chục
        for(int i = 0; i <= 9; i++){
            v = u - cs[2] * 10 + i * 10;
            if(mark[v] == 0 && d[v] == 0){
                q.push(v);
                d[v] = 1;
                kc[v] = kc[u] + 1;
            }
            if(v == t){
                break;
            }
        }
        
        // Hàng trăm
        for(int i = 0; i <= 9; i++){
            v = u - cs[3] * 100 + i * 100;
            if(mark[v] == 0 && d[v] == 0){
                q.push(v);
                d[v] = 1;
                kc[v] = kc[u] + 1;
            }
            if(v == t){
                break;
            }
        }
        
        // Hàng nghìn
        for(int i = 1; i <= 9; i++){
            v = u - cs[4] * 1000 + i * 1000;
            if(mark[v] == 0 && d[v] == 0){
                q.push(v);
                d[v] = 1;
                kc[v] = kc[u] + 1;
            }
            if(v == t){
                break;
            }
        }
    }
    cout << kc[t] << "\n";
}

int main(){
    int T;
    scanf("%d", &T);
    sieve();
    while(T--){
        cin >> s >> t;
        for(int i = 1000; i <= 9999; i++){
            d[i] = 0;
            kc[i] = 0;
        }
        process();
    }
    return 0;
}