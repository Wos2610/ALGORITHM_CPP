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
        // Loai bo het cac phan tu top co gia tri >= a[i] 
        // => a[i] la max trong st
        while(st.size() != 0 && a[st.top()] >= a[i]){
            st.pop();
        }
        // Day vi tri i vao vi tri top cua stack
        st.push(i);

        // Can i >= k vi ta tim min trong khoang [i - k + 1...i]
        if(i >= k){
             // stack tmp dung de luu lai cac phan tu cua stack st
            stack<int> tmp;
            // Neu phan tu day cua tmp ( phan tu day cua st ) 
            // khong thuoc khoang [i - k + 1...i] dang xet 
            // => khong push lai vao st
            while(st.size() != 0){
                tmp.push(st.top());
                st.pop();
            }

            if(tmp.top() < i - k + 1){
                tmp.pop();
            }
            res[i] = tmp.top();
            // stack temp dung de lay ra vi tri cuoi cung 
            // nam trong khoang [i - k + 1...i] dang xet cua stack st
            while(tmp.size() != 0){
                st.push(tmp.top());
                tmp.pop();
            }
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
