#include<iostream>
#include<algorithm>

using namespace std;

long long a[1000006];
long long b[1000006];
long long c[1000006];

int binarySearch(long long a[], int n, long long x){
    int l = 0;
    int r = n - 1;
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
    int n1 , n2, n3;
    scanf("%d%d%d", &n1, &n2, &n3);
    for(int i = 0; i < n1; i++){
        scanf("%lld", &a[i]);
    }
    for(int i = 0; i < n2; i++){
        scanf("%lld", &b[i]);
    }
    for(int i = 0; i < n3; i++){
        scanf("%lld", &c[i]);
    }
    int mark = 0;
    for(int i = 0; i < n1; i++){
        if(binarySearch(b, n2, a[i]) != -1 && binarySearch(c, n3, a[i]) != -1){
            mark = 1;
            printf("%lld ", a[i]);
        }
    }
    if(mark == 0){
        printf("-1");
    }

    printf("\n");
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        process();
    }
}
    