#include<iostream>
#include<algorithm>

using namespace std;

long long a[1000006];


void process(){
    int n;
    scanf("%d", &n);
    long long k;
    scanf("%lld", &k);
    for(int i = 0; i < n; i++){
        scanf("%lld", &a[i]);
    }
    sort(a, a + n);

    int c = 0;
    int l = 0;
    int r = n - 1;
    while(l <= r){
        if(a[l] + a[r] < k){
            l++;
        }
        else if(a[l] + a[r] > k){
            r--;
        }
        else{
            if(r > l){
              c++;  
            }
            int res = r - 1;
            while(a[res] == a[r] && res > l){
                c++;
                res--;
            }
            l++;
        }
    }
    printf("%d\n", c);
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        process();
    }
}
    