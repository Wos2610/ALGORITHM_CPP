#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> a(1000006, 0);
vector<int> b(1000006, 0);
vector<int> mark(1000006, 0);
int n = 0;

void Try2(int pos){
    
    for(int i = 1; i <= n; i++){
        b[pos] = i;
        if(pos == n){
            for(int i = 1; i <= n; i++){
                cout << char(a[i] - 1 + 'A');
            }
            for(int j = 1; j <= n; j++){
                cout << b[j];
            }
            cout << "\n";
        }
        else if(pos > n){
            break;
        }
        Try2(pos + 1);
    }
}

void Try(int pos){
    for(int i = 1; i <= n; i++){
        if(mark[i] == 0){
            a[pos] = i;
            mark[i] = 1;
            Try(pos + 1);
            mark[i] = 0;
        }
    }
    if(pos == n){
        Try2(1);
    }
}

void hienThi(){
    Try(1);
}

void process(){
    scanf("%d", &n);
    hienThi();
}
int main(){
    process();
    return 0;
}