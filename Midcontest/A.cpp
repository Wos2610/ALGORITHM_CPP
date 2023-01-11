#include<iostream>
#include<algorithm>
#include<stdbool.h>
#include<math.h>
#include<vector>
#define M 100006

using namespace std;

int n, q, k;
long long x;

vector<long long> f(M);

struct Number{
    long long p;
    long long s;
};

Number b[M];

bool cmp(Number b1, Number b2){
    return b1.s < b2.s;
}

void tinh(long long x, int k){
    int index = lower_bound(f.begin() + 1, f.begin() + 1 + n, x) - f.begin();
    // cout << index << "\n";
    int l = max(1, index - k);
    int r = min(index + k , n);

    int j = 0;
    for(int i = l; i <= r; i++){
        b[j].p = f[i];
        b[j].s = abs(f[i] - x);
        j++;
    }

    sort(b, b + j, cmp);

    for(int i = 0; i < k; i++){
        cout << b[i].p << " ";
    }
    cout << "\n";

}

int main(){
    cin >> n >> q;

    for(int i = 1; i <= n; i++){
        cin >> f[i];
    }

    sort(f.begin() + 1, f.begin() + 1 + n);

    for(int i = 0; i < q; i++){
        cin >> x >> k;
        tinh(x, k);
        // b.clear();
    }


    
}
