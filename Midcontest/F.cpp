#include<iostream>
#include<algorithm>

using namespace std;

long long n, a, b;
long long c, d;

long long tinh(long long a, long long b){
    long long d = n/b;
    long long du = n - d*b;
    if(a < b){
        swap(a, b);
    }
    while(1){
        if(du % a == 0){
            d += du/a;
            break;
        }
        else{
            du += b;
            d--;
            if(d < 0){
                return -1;
            }
        }
    }
    return d;
}

void process(){
    cin >> n >> a >> b;
    long long d1 = tinh(1, 2);
    long long d2 = tinh(2, 1);
    long long res1 = a * (n - 2 * d1) + b * d1;
    long long res2 = a * d2 + b * (n - d2) / 2;
    if(res1 > res2){
        cout << res2;
    }
    else{
        cout << res1;
    }
    cout << "\n";
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        process();
    }
}
    