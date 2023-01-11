#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define M 1000006

using namespace std;
int n;
int a[1006][1006];
int mark[1006][1006];
string ans;

void DFS(int c, int d, string s){
    mark[c][d] = 1;
    if(c == n && d == n){
        ans = s;
        return;
    }
    if(a[c + 1][d] == 1 && mark[c + 1][d] == 0){
        DFS(c + 1, d, s + 'D');
    }
    if(a[c][d + 1] == 1 && mark[c][d + 1] == 0){
        DFS(c , d + 1, s + 'R');
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    string s = "";
    
    DFS(1, 1, s);
    if(ans.size() <= n){
        cout << "-1";
        return 0;
    }
    cout << ans;
    return 0;
}