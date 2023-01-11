#include<iostream>
#include<algorithm>
#define M 1000006

using namespace std;
int n;
int a[M];
int l[M];
void process(){
    for(int i = 1; i <= n; i++){
        l[i] = 1;
        for(int j = 1; j < i; j++){
            if(a[j] < a[i]){
                l[i] = max(l[i], l[j] + 1);
            }
        }
    }
    sort(l + 1, l + 1 + n);
    cout << l[n];
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    process();
}