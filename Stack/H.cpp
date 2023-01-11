#include<iostream>
#include<string>
#include<stack>
#define M 1000006
using namespace std;


int n;
int a[1006][1006];
int col[M], row[M];

int check(){
    for(int i = 0; i < n; i++){
        for(int  j = 0; j < n; j++){
            if(a[i][j] == 1){
                col[j]++;
                row[i]++;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(col[i] == n - 1 && row[i] == 0){
            return i;
        }
    }
    return -1;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int  j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    int res = check();
    if(res == -1){
        cout << "No celebrity detected";
    }
    else{
        cout << res << " is celebrity";
    }
}
