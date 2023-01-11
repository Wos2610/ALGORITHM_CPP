#include<iostream>
#include<algorithm>
#include<stack>
#define M 1000006

using namespace std;

int n;
stack<int> st1, st2;
int a[M], l[M], r[M];

void tinh(){
    // Tim phan tu ben trai a[i] dau tien khong the cat duoc
    st1.push(0);
    for(int i = 1; i <= n; i++){
        // Loai bo cac phan tu trong stack st1 ma >= a[i]
        while(st1.size() != 0 && a[st1.top()] >= a[i]){
            st1.pop();
        }
        if(st1.size() != 0){
            l[i] = st1.top();
        }
        st1.push(i);
    }

    // Tim phan tu ben phai a[i] dau tien khong the cat duoc
    st2.push(n + 1);
    for(int i = n; i >= 1; i--){
        while(st2.size() != 0 && a[st2.top()] >= a[i]){
            st2.pop();
        }
        if(st2.size() != 0){
            r[i] = st2.top();
        }
        st2.push(i);
        // cout << st2.top() << "\n";
    }

    int temp = 0, res = -9999;
    for(int i = 1; i <= n; i++){
        // cout << l[i] << " " << r[i] << "\n";
        temp = r[i] - l[i] - 1;
        if(temp >= a[i]){
            res = max(res, a[i]);
        }
    }
    cout << res;

}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    tinh();
}
