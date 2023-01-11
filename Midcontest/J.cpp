#include<iostream>
#include<algorithm>
#include<map>
#define M 1000006

using namespace std;

int n, res = -1;
long long a[M];

int main(){
    cin >> n;

    map<int, int> m;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        m[a[i]]++;
        if(m[a[i]] > res){
            res = m[a[i]];
        }
    }
    for(int i = 0; i < n; i++){
        if(m[a[i]] == res){
            cout << a[i];
            return 0;
        }
    }
}
    