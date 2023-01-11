#include<iostream>
#include<vector>
#define M 1000006
using namespace std;

long long a[M];

void change(int n){
    int count = 0;
    int l = 1;
    int r = n;
    while(l < r){
        if(a[l] == a[r]){
            l++;
            r--;
        }
        else if(a[l] < a[r]){
            l++;
            a[l] += a[l - 1];
            count++;
        }
        else{
            r--;
            a[r] += a[r + 1];
            count++;
        }
    }
    printf("%d", count);
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    change(n);
    return 0;
}