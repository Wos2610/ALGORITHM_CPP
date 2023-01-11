#include<iostream>
#include<algorithm>
#include<vector>
#define M 1000006

using namespace std;

int n, l, r;

int a[M], b[M];

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b, b + n);

    for(int i = 0; i < n; i++){
        if(a[i] != b[i]){
            l = i;
            break;
        }
    }

    for(int i = n - 1; i >= 0; i--){
        if(a[i] != b[i]){
            r = i;
            break;
        }
    }

    cout << l + 1 << " " << r + 1;

}
