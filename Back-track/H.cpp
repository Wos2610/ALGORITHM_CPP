#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int k, n, sum = 0;
int a[26], s[26], mark[26];

int Try(int i, int dem){
    for(int j = i; j >= 0; j--){
        if(mark[j] == 0){
            if(s[dem] + a[j]> sum){
                break;
            }
            s[dem] += a[j];
            mark[j] = 1;
            if(s[dem] == sum){
                if(dem == n - 2){
                    return 1;
                }
                else{
                    Try(n - 1, dem + 1);
                }
            }
            else{
                Try(i - 1, dem);
            }
            mark[j] = 0;
            s[dem] -= a[j];
        }
    }
    return 0;
}

int check(){
    if(k > n){
        return 0;
    }
    if(sum % k != 0){
        return 0;
    }
    sum /= k; // sum cua moi tap con
    s[0] = a[n - 1];
    for(int i = 0; i < n; i++){
        mark[i] = 0;
        s[i] = 0;
    }
    mark[n - 1] = 1;
    return Try(n - 1, 0);
}

void process(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n);
    cout << check() << "\n";
}

int main(){
    int T;
    cin >> T;
    while(T--){
        process();
    }
}
    