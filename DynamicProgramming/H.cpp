#include<iostream>
#include<algorithm>
#include<vector>
#define M 1000006

using namespace std;
int n, k;
int a[1006][1006];
int f[1006][1006], g[1006][1006], h[1006][1006];

void process(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            f[i][j] = f[i][j - 1] + a[i][j];
            // cout << f[i][j] << " ";
        }
        // cout << "\n";
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            f[i][j] = f[i - 1][j] + f[i][j];
            // cout << f[i][j] << " ";
        }
        // cout << "\n";
    }

    for(int i = k; i <= n; i++){
        for(int j = 1; j <= n; j++){
            g[i][j] = f[i][j] - f[i - k][j];
            // cout << g[i][j] << " ";
        }
        // cout << "\n";
    }

    int m = -1;
    for(int i = k; i <= n; i++){
        for(int j = k; j <= n; j++){
            h[i][j] = g[i][j] - g[i][j - k];
            if(m < h[i][j]){
                m = h[i][j];
            }
            // cout << h[i][j] << " ";
        }
        // cout << "\n";
    }
    cout << m;

}

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    process();
}