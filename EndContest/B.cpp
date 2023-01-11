#include<iostream>
#include<algorithm>
#include<stdbool.h>
#include<math.h>
#include<vector>
#include<map>
#define M 100006

using namespace std;
int n, k;
vector<int> a(M);
int l[M], r[M];

int BS(int n, int x){
    int l = 1;
    int r = n;
    while(l <= r){
        int mid = (l + r)/2;
        if(a[mid] < x){
            l = mid + 1;
        }
        else if(a[mid] > x){
            r = mid - 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

map <int, int> m;
int main() {
    
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    sort(a.begin() + 1, a.begin() + 1 + n);

    // for(int i = 1; i <= n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << "\n";
    for(int i = 1; i <= n; i++){
        if(a[i] != a[i - 1]){
            m[a[i]] = m[a[i - 1]] + 1;
        }
        else{
            m[a[i]] = m[a[i]] + 1;
        }
    }
    // for(int i = 1; i <= n; i++){
    //     cout << m[a[i]] << " ";
    // }
    // cout << "\n";
    for(int i = 0; i < k; i++){
        scanf("%d%d", &l[i], &r[i]);
    }
    
    for(int i = 0; i < k; i++){
        int beg = lower_bound(a.begin() + 1, a.begin() + 1 + n, l[i]) - a.begin();
        int end = lower_bound(a.begin() + 1, a.begin() + 1 + n, r[i]) - a.begin();
       
        if(m[r[i]] == 0){
            end--;
        }
        if(beg < 1){
            beg = 0;
        }
        if(end > n){
            end = n;
        }
        printf("%d\n", m[a[end]] - m[a[beg - 1]]);
    }
}
