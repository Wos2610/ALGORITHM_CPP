#include<iostream>
#define M 10000006

using namespace std;

int n;
int a[M];

int binarySearch(int k){
    int l = 1;
    int r = n;
    while(l <= r){
        int mid = (l + r)/2;
        if(a[mid] > k){
            r = mid - 1;
        }
        else if(a[mid] < k){
            l = mid + 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

void process(){
    int k;
    scanf("%d%d", &n, &k);
    
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    
    if(binarySearch(k) == -1){
        printf("NO\n");
    }
    else{
        printf("%d\n", binarySearch(k));
    }
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        process();
    }
    return 0;
}