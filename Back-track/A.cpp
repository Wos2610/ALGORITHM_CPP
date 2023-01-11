#include<iostream>
#include<algorithm>

using namespace std;
#define M 1000006

int n;
int a[16][16];

void process(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[1][i];
    }
    cout << "[";
    for(int i = 1; i <= n; i++){
        cout << a[1][i];
        if(i != n){
            cout << " ";
        }
    }
    cout << "]\n";
    for(int i = 2; i <= n; i++){
        cout << "[";
        for(int j = 1; j <= n - i + 1; j++){
            a[i][j] = a[i - 1][j] + a[i - 1][j + 1];
            cout << a[i][j] ;
            if(j != n - i + 1){
                cout << " ";
            }
        }
        cout << "]\n";
    }
}

int main(){
    int T;
    cin >> T;
    while(T--){
        process();
    }
}
    