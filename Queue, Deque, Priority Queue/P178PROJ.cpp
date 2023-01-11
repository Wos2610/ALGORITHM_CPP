#include<iostream>
#include<queue>
#define M 1000006
#define MOD 1000000007
using namespace std;
 
int n;
long long x, res;

priority_queue<long long, vector<long long>, greater<long long>> pq;

int main(){
    cin >> n;
 
    for(int i = 0; i < n; i++){
        cin >> x;
        pq.push(x);
    }

    while(pq.size() > 1){
        long long temp = pq.top() % MOD;
        pq.pop();
        temp = (temp + pq.top()) % MOD;
        pq.pop();
        res = (res + temp) % MOD;
        pq.push(temp);
    }

    cout << res;
    
 
}