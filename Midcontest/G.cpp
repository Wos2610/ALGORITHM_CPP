#include<iostream>
#include<algorithm>
#include<vector>
#define M 1000006

using namespace std;

int n, res;
int a[M], l[M], r[M];

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    l[0] = 1;
    for(int i = 1; i < n; i++){
        if(a[i] > a[i - 1]){
            l[i] = l[i - 1] + 1;
        }
        else{
            l[i] = 0;
        }
    }
    r[n - 1] = 1;
    for(int i = n - 2; i >= 0; i--){
        if(a[i + 1] < a[i]){
            r[i] = r[i + 1] + 1;
        }
        else{
            r[i] = 0;
        }
    }

    for(int i = 0; i < n; i++){
        res = l[i] + r[i];
        if(l[i] != 0 && r[i] != 0){
            res--;
        }
        cout << res << " ";
    }

}
    