#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#define M 1000006
using namespace std;

int V, E, st;
vector<vector<int>> f(M);
stack<int> s;
int mark[M];

void DFS(){
    while(s.size() != 0){
        int u = s.top();
        s.pop();
        if(mark[u] == 0){
            printf("%d ", u);
            mark[u] = 1;
        }
        for(int i = 0; i < f[u].size(); i++){
            int temp = f[u][i];
            if(mark[temp] == 0){
                s.push(u);
                s.push(temp);
                break;
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
            // push b vao tap hop dinh ke cua a
            f[a].push_back(b);
            // push a vao tap hop dinh ke cua b
            f[b].push_back(a);
        }
        for(int i = 1; i <= V; i++){
            sort(f[i].begin(), f[i].end());
            mark[i] = 0;
        }
        // reset stack
        while(s.size() != 0){
            s.pop();
        }
        // push phan tu dau tien
        s.push(st);
        
        DFS();
        printf("\n");
    }
    return 0;
}
