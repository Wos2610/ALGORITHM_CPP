#include <iostream>
#define M 1000006
using namespace std;

long long a[M];
long long s[M];

void process(){
    int n;
    scanf("%d", &n);
    long long max = -99999999999;
    long long min = 99999999999;

    for (int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        if(a[i] > 0){
            s[i] = s[i - 1] + 2 * a[i]; 
        }
        else{
            s[i] = s[i - 1];
        }
    }

    for (int i = 0; i <= n; i++){
        if(s[i] < min){
            min = s[i];
        }
        if(s[i] - min > max){
            max = s[i] - min;
        }
    }

    printf("%lld\n", max);
}

int main(){
    int T;
    scanf("%d", &T);
    while (T--){
        process();
    }
    return 0;
}