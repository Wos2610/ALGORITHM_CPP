#include<iostream>
#include<algorithm>
#include<stack>
#define M 1000006

using namespace std;

int n;
stack<int> st1, st2;
long long a[M], l[M], r[M];

void tinh(){
    st1.push(0);
    for(int i = 1; i <= n; i++){
        while(st1.size() != 0 && a[st1.top()] >= a[i]){
            st1.pop();
        }
        if(st1.size() != 0){
            l[i] = st1.top();
        }
        st1.push(i);
    }

    st2.push(n + 1);
    for(int i = n; i >= 1; i--){
        while(st2.size() != 0 && a[st2.top()] >= a[i]){
            st2.pop();
        }
        if(st2.size() != 0){
            r[i] = st2.top();
        }
        st2.push(i);
    }

    long long temp = 0, res = -9999999999;
    for(int i = 1; i <= n; i++){
        cout << l[i] << " " << r[i] << "\n";
        // temp = r[i] - l[i] - 1;
        // // temp *= a[i];
        // cout << temp << " ";
        // res = max(res, temp);
    }
    cout << "\n";

    // printf("%lld\n", res);
    
}

int main(){
    int T;
    cin >> T;
    while(T--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%lld", &a[i]);
        }
        while(st1.size() != 0){
            st1.pop();
        }
        while(st2.size() != 0){
            st2.pop();
        }
        for(int i = 1; i <= n; i++){
            l[i] = r[i] = 0;
        }
        tinh();

    }
}
