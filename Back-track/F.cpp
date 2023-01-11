#include<iostream>
#include<algorithm>

using namespace std;

int n;
long long res = 999999999999999999, sum;
long long c[16][16];
int a[16], mark[16];


// 1 3 2 4
void Try(int i){
    for(int j = 2; j <= n; j++){
        if(mark[j] == 0){
            if(sum > res){
                break;
            }
            a[i] = j;
            mark[j] = 1;
            sum += c[a[i - 1]][j];
            if(i == n){
                sum += c[a[i]][1];
                // for(int k = 2; k <= n; k++){
                //     cout << a[k] << " ";
                // }
                // cout << sum << "\n" ;
                
                res = min(res, sum);
                sum -= c[a[i]][1];
            }
            else{
                Try(i + 1);
            }
            sum -= c[a[i - 1]][j];
            mark[j] = 0;
        }
    }
}

void process(){
    cin >> n ;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> c[i][j];
        }
    }
    if(n == 1){
        cout << c[1][1];
        return;
    }
    a[1] = 1;
    Try(2);
    cout << res;
}

int main(){
    process();
}
    