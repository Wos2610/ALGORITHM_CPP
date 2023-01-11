#include<iostream>
#include<algorithm>
#include<stdbool.h>
#include<math.h>
#include<vector>
#include<map>
#include<queue>

#define M 100006

using namespace std;

int n, m;
int mark[26][26];
char a[26][26];
int r0[] = {-1, 1};
vector<pair<int, int>> save;

int mk;

int check(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] != '.' && mark[i][j] == 0){
                return 0;
            }
        }
    }
    return 1;
}

void Try(int d){
    if(d == save.size()){
        if(check()){
            mk = 1;
            return;
        }
    }

    int i = save[d].first;
    int j = save[d].second;
    
    for(int p = 0; p < 2; p++){
        for(int q = 0; q < 2; q++){
            int r = i + r0[p];
            int c = j + r0[q];
            if(r >= 1 && r <= n && c >= 1 && c <= m){
                if(a[r][j] == 'W' && a[i][c] == 'W' && mark[r][j] == 0 && mark[i][c] == 0){
                    mark[r][j] = 1;
                    mark[i][c] = 1;
                    mark[i][j] = 1;
                    Try(d + 1);
                    mark[r][j] = 0;
                    mark[i][c] = 0;
                    mark[i][j] = 0;
                }
            }
        }
    }
}


void process(){
    scanf("%d%d", &n, &m);
    int dem = 0;
    save.resize(0);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            if(a[i][j] == 'B'){
                save.push_back({i,j});
            }
            if(a[i][j] != '.'){
                dem++;
            }
            mark[i][j] = 0;
        }
    }
    mk = 0;
    if(dem % 3 != 0 || save.size() == 0){
        cout << "NO\n";
        return;
    }
    Try(0);
    if(mk == 1){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--){
        process();
    }
    
}