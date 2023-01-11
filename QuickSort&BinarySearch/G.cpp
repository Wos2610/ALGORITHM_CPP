#include<iostream>
#include<algorithm>

using namespace std;

long long a[1000006];
long long s[1000006];

int BS(long long a[], int l, int r, long long x){
    while(l <= r){
        int mid = (l + r)/2;
        if(a[mid] > x){
            r = mid - 1;
        }
        else if(a[mid] < x){
            l = mid + 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

void process(){
    int n;
    scanf("%d", &n);
    long long k;
    scanf("%lld", &k);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }
    s[0] = 0;
    for(int i = 1; i <= n; i++){
        s[i] = s[i - 1] + a[i];
    }
    // for(int i = 0; i <= n; i++){
    //     printf("%d ", s[i]);
    // }
    // printf("\n");
    int x = -1;
    for(int i = 0; i < n; i++){
        x = BS(s, i + 1, n, k + s[i]);
        // printf("%d ", k + s[i]);
        if( x != -1){
            for(int j = i + 1; j <= x; j++){
                printf("%lld ", a[j]);
            }
            break;
        }
    }
    if(x == -1){
        printf("NOT FOUND");
    }
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        process();
        printf("\n");
    }
}
    