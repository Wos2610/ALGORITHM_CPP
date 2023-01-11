#include<iostream>

using namespace std;

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    int res = 0;
    if(k < 2*n && k > 2){
        if(k % 2 != 0){
            res = k/2;
        }
        else{
            res = k/2 - 1;
        }
        int temp = 0;
        for(int i = 1; i <= k/2; i++){
            if(k - i <= n){
                temp = i;
                break;
            }
        }

        res = res - temp + 1;
    }
    cout << res;
}