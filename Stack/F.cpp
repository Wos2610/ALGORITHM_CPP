#include<iostream>
#include<algorithm>
#include<stack>
#define M 1000006

using namespace std;

int n;
stack<int> st1, st2;
long long a[M], nho[M], lon[M];

void tinh(){
    for(int i = n; i >= 1; i--){
        while(st1.size() != 0 && a[st1.top()] >= a[i]){
            st1.pop();
        }
        if(st1.size() == 0){
            nho[i] = -1;
        }
        else{
            nho[i] = st1.top();
        }
        st1.push(i);
    }

    for(int i = n; i >= 1; i--){
        while(st2.size() != 0 && a[st2.top()] <= a[i]){
            st2.pop();
        }
        if(st2.size() == 0){
            lon[i] = -1;
        }
        else{
            lon[i] = st2.top();
        }
        st2.push(i);
    }

    for(int i = 1; i <= n; i++){
        if(lon[i] == -1 || nho[lon[i]] == -1){
            cout << "-1" << " ";
        }
        else{
            cout << a[nho[lon[i]]] << " ";
        }
        // cout << nho[i] << " " << lon[i] << " " << nho[lon[i]] << "\n";
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }
    tinh();
}
