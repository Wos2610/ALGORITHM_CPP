#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

#define M 1000006

using namespace std;

int a[1006];
int f[1006][1006];
string s1, s2;

void process(){
    int n = s1.size();
    int m = s2.size();
    s1 = ' ' + s1;
    s2 = ' ' + s2;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i] == s2[j]){
                f[i][j] = f[i - 1][j - 1] + 1;
            }
            else{
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }
    cout << f[n][m];
}

int main() {
    cin >> s1 >> s2;
    process();
}