#include<iostream>
#include<algorithm>
#include<vector>

#define M 1000006

using namespace std;
int n;
int a[1006];
int f[1006];

vector<int> save;

void process(){
    int m = -1;
    for(int i = 0; i < n; i++){
        f[i] = 1;
        for(int j = 0; j < i; j++){
            if(a[j] < a[i]){
                f[i] = max(f[i], f[j] + 1);
            }
        }
        m = max(m, f[i]);
    }

    int mx = m;
    for(int i = n - 1; i >= 0; i--){
        if(f[i] == m){
            save.push_back(a[i]);
            m--;
        }
    }

    cout << mx << "\n";
    for(int i = mx - 1; i >= 0; i--){
        cout << save[i] << " ";
    }
    
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    process();
}