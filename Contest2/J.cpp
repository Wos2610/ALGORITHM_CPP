#include<iostream>
#include<algorithm>
#include<vector>
#define M 1000006
using namespace std;

int n, m;
vector<long long> a(M);
long long x[M], y[M];
long long sum = 0;

void process(){
    
    sort(a.begin() , a.end());
    // for(int i = 1; i <= n; i++){
    //     cout << a[i] << " ";
    // }
    for(int i = 1; i <= m; i++){
        int index2 = lower_bound(a.begin(), a.end(), x[i]) - a.begin();
        int index1 = index2 - 1;
        // cout << index2 << " " << index1;
        long long res = 0, temp1 = 0, temp2 = 0;
        
        if(a[index1] < x[i]){
            temp1 += x[i] - a[index1];
        }

        if(sum - a[index1] < y[i]){
            temp1 += y[i] - sum + a[index1];
        }

        if(a[index2] < x[i]){
            temp2 += x[i] - a[index2];
        }

        if(sum - a[index2] < y[i]){
            temp2 += y[i] - sum + a[index2];
        }
        
        res = min(temp1, temp2);
        printf("%lld\n", res);
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    scanf("%d", &m);
    for(int i = 1; i <= m; i++){
        scanf("%lld", &x[i]);
        scanf("%lld", &y[i]);
    }
    process();
    return 0;
}