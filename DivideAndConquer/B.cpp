#include<iostream>
#include<string>
#define MOD 1000000007

using namespace std;

long long l[100];

int search(long long n, long long k){
    if(n == 1){
        return 1;
    }
    if(k <= l[n - 1]){
        return search(n - 1, k);
    }
    else if(k == l[n - 1] + 1){
        return n;
    }
    else{
        return search(n - 1, k - l[n - 1] - 1);
    }
}

void process(){
    long long n, k;
    cin >> n >> k;
    cout << search(n, k);
    cout << "\n";
    
}
int main(){
    int T;
    cin >> T;
    l[1] = 1;
    for(int i = 2; i < 56; i++){
        l[i] = 2 * l[i - 1] + 1;
    }

    while(T--){
        process();
    }
    return 0;
}