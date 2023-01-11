#include<iostream>
#include<algorithm>

using namespace std;

int a[1000006] = {0};

int binarySearch(int a[], int n, int x){
    int l = 0;
    int r = n - 1;
    while(l <= r){
        int mid = (l + r)/2;
        if(a[mid] == x){
            return mid;
        }
        if(a[mid] > x){
            r = mid - 1;
        }
        if(a[mid] < x){
            l = mid + 1;
        }
    }
    return -1;
}

int main(){
    int n,x;
    scanf("%d%d", &n, &x);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    
    sort(a, a + n);
    
    int k = binarySearch(a, n, x);
    if(k == -1){
        printf("NO");
    }
    else{
        printf("YES");
    }
}
