#include<iostream>
#include<algorithm>
#include<vector>
#define M 1000006

using namespace std;
int n, m , dem;
vector<vector<int>> f(M);
int mark[M];

void DFS(int u){
    mark[u] = 1;
    for(int i = 0; i < f[u].size(); i++){
        int temp = f[u][i];
        if(mark[temp] == 0){
            DFS(temp);
        }
    }
}

int main(){
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        f[a].push_back(b);
        f[b].push_back(a);
    }
    if(m == 0){
        dem = 0;
    }
    else{
         for(int i = 1; i <= n; i++){
            if(mark[i] == 0){
                dem++;
                DFS(i);
            }
        }
    }
    cout << dem;
    return 0;
}
