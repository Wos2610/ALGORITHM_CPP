#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> a(1000006, 0);

void HV(int n){
    int i = n - 1;
    while(i >= 1 && a[i] >= a[i + 1]){
        i--;
    }
    if(i == 0){
        for(int i = 1; i <= n; i++){
            a[i] = i;
        }
    }
    else{
        int k = i;
        int temp = -1;
        for(int j = n; j > k; j--){
            if(a[j] > a[k]){
                temp = j;
                break;
            }
        }
        swap(a[k], a[temp]);
        sort(a.begin() + 1 + k, a.begin() + 1 + n);
    }
}

void process(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    HV(n);
    for(int i = 1; i <= n; i++){
        printf("%d ", a[i]);
    }
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        process();
        printf("\n");
    }
    return 0;
}