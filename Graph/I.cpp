#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define M 1000006
using namespace std;

int V, E, st;
vector<vector<int>> f(M);
queue<int> q;
int mark[M];

void BFS(){
    cout << st << " ";
    mark[st] = 1;
    while(q.size() != 0){
        int u = q.front();
        q.pop();
        for(int i = 0; i < f[u].size(); i++){
            int temp = f[u][i];
            if(mark[temp] == 0){
                printf("%d ", temp);
                mark[temp] = 1;
                q.push(temp);
            }
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
        }
        for(int i = 1; i <= V; i++){
            sort(f[i].begin(), f[i].end());
            mark[i] = 0;
        }
        q.push(st);
        BFS();
        printf("\n");
    }
    return 0;
}
