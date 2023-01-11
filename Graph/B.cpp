#include<iostream>
#include<algorithm>
#include<vector>
#define M 1000006

using namespace std;
int V, E;
vector<vector<int>> f(M);

void tinh(){
    for(int i = 1; i <= V; i++){
        int end = f[i].size();
        if(end != 0){
            printf("Dinh ke cua %d : ", i);
            for(int j = 0; j < end; j++){
                cout << f[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
int main(){
    cin >> V >> E;
    int a, b;
    for(int i = 0; i < E; i++){
        cin >> a >> b;
        if(a != b){
            f[a].push_back(b);
            f[b].push_back(a);
        }
    }
    for(int i = 1; i <= V; i++){
        sort(f[i].begin(), f[i].end());
    }
    tinh();
    return 0;
}