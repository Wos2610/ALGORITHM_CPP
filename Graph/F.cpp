#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#define M 1000006

using namespace std;
int n, m, sum0, sum1;
vector<vector<int>> f(M);
vector<vector<int>> road(M);

int mark[M], level[M];
queue<int> q;
map<pair<int, int>, int> mp;

void BFS() {
    q.push(1);
    mark[1] = 1;
    level[1] = 1;
    while (q.size() != 0) {
        int u = q.front();
        for (int i = 0; i < f[u].size(); i++) {
            int temp = f[u][i];
            if (mark[temp] == 0) {
                q.push(temp);
                mark[temp] = 1;
                road[temp].push_back(u);
                level[temp] = level[u] + 1;
            }
            else {
                if (level[temp] > level[u]) {
                    road[temp].push_back(u);
                    level[temp] = level[u] + 1;
                }
            }
        }
        q.pop();
    }
}

int res = 999999;
void Try(int i, int dem1, int dem0) {
    if (i == 1) {
        int temp = dem0 + sum1 - dem1;
        res = min(res, temp);
        return;
    }
    for (int j = 0; j < road[i].size(); j++) {
        int tmp = road[i][j];
        if (mp[{tmp,i}] == 1) {
            Try(tmp, dem1 + 1, dem0);
        }
        else {
            Try(tmp, dem1, dem0 + 1);
        }
    }
}

int main() {
    cin >> n >> m;
    int x, y, z;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        f[x].push_back(y);
        f[y].push_back(x);
        mp[{x,y}] = z;
        mp[{y,x}] = z;
        if (z == 1) {
            sum1++;
        }
        else {
            sum0++;
        }
    }
    BFS();
    Try(n, 0, 0);
    cout << res;
    return 0;
}