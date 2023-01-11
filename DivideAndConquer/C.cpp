#include<iostream>
#include<string>
#define MOD 1000000007

using namespace std;

// Mang luu do dai cua cac xau fibo
long long l[100];

int search(long long n, long long k){
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    // f[n] = f[n - 2] + f[n - 1]
    // neu k <= do dai cua f[n - 2] thì se nam trong f[n - 1]
        //chu thu k trong f[n] la chu thu k trong f[n - 2]
    // neu k >  do dai cua f[n - 2] thi se nam trong f[n - 1]
        // chu thu k trong f[n] la chu thu k - do dai f[n - 2]
    if(k <= l[n - 2]){
        return search(n - 2,k);
    }
    else{
        return search(n - 1, k - l[n - 2]);
    }
}

void process(){
    long long n, k;
    cin >> n >> k;
    if(search(n, k) == 1){
        cout << 'A';
    }
    else{
        cout << 'B';
    }
    cout << "\n";
    
}
int main(){
    int T;
    cin >> T;
    l[1] = 1;
    l[2] = 1;
    for(int i = 3; i < 100; i++){
        l[i] = l[i - 2] + l[i - 1];
    }

    while(T--){
        process();
    }
    return 0;
}