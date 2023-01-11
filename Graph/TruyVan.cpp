#include<iostream>
#include<vector>
#include<algorithm>
#define M 1000006
using namespace std;

int V, E, st;
vector<vector<int>> f(M);
int c[M];

int mark[M];
void DFS(int u){
    printf("%d ", u);
    mark[u] = 1;
    for(int i = 0; i < f[u].size(); i++){
        int temp = f[u][i];
        if(mark[temp] == 0){
            DFS(temp);
        }
    }
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d", &V, &E, &st);
        for(int i = 0; i <= V; i++){
            f[i].resize(0);
        }
        int a, b;
        for(int i = 0; i < E; i++){
            scanf("%d%d", &a, &b);
            f[a].push_back(b);
            f[b].push_back(a);
        }
        for(int i = 1; i <= V; i++){
            sort(f[i].begin(), f[i].end());
            mark[i] = 0;
        }
        int m, n;
        cin >> m >> n;
        DFS(1);
        
        for(int ){
            if()
        }
        printf("\n");
    }
    return 0;
}