#include<iostream>
#include<algorithm>
#include<stack>
#define M 1000006

using namespace std;

int n, k;
stack<int> st;
int a[M], res[M];
// a1 a2 ... a(k)
// a2 a3 ... a(k + 1)
// ...
// a(n - k + 1) a(k + 1) ... a(n)

void minTinhTien(){
    for(int i = 1; i <= n; i++){
        // Loai bo het cac phan tu top co gia tri <= a[i] 
        // => a[i] la min trong st
        while(st.size() != 0 && a[st.top()] <= a[i]){
            st.pop();
        }
        // Day vi tri i vao vi tri top cua stack
        st.push(i);
        // Can i >= k vi ta tim min trong khoang [i - k + 1...i]
        if(i >= k){
            // stack temp dung de lay ra vi tri cuoi cung 
            // nam trong khoang [i - k + 1...i] dang xet cua stack st
            stack<int> temp = st;
            while(temp.size() != 0 && temp.top() >= i - k + 1){
                res[i] = temp.top();
                // cout << a[temp.top()] << " ";
                temp.pop();
            }
           
            // stack tmp dung de luu lai cac phan tu cua stack st
            stack<int> tmp = st;

            // Neu phan tu top cua tmp ( phan tu day cua st ) 
            // khong thuoc khoang [i - k + 1...i] dang xet 
            // => khong push lai vao st
            if(tmp.top() < i - k + 1){
                tmp.pop();
            }
            st = tmp;
        }
    }
    
    for(int i = k; i <= n; i++){
        cout << a[res[i]] << " ";
    }
}

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    minTinhTien();
}
