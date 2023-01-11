#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
#include<vector>
#define M 1000006
using namespace std;

int V, E, st, en;
vector<vector<pair<int, int>>> f(M);
int a[M], mark[M];

void DFS(int u){
    mark[u] = 1;
    for(int i = 0; i < f[u].size(); i++){
        int v = f[u][i].first;
        int tmp = f[u][i].second;
        if(mark[v] == 0){
            a[v] = max(tmp, a[u]);
            mark[v] = 1;
            DFS(v);
        }
        else{
            if(a[v] > max(tmp, a[u])){
                a[v] = max(tmp, a[u]);
                DFS(v);
            }
        }
    }
}

int main(){
    cin >> V >> E;
    cin >> st >> en;
    int u,v,w;
    for(int i = 0; i < E; i++){
        cin >> u >> v >> w;
        f[u].push_back({v, w});
        f[v].push_back({u, w});
    }
    a[st] = 0;
    DFS(st);
    cout << a[en];
    return 0;
}