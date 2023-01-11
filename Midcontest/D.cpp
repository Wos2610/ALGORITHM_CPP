#include<iostream>
#include<algorithm>

using namespace std;

long long n, k;
void process(){
    cin >> n >> k;
    long long temp = n/k;
    if(temp % 2 != 0){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        process();
    }
}
    