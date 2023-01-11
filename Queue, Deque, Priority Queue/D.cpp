#include<iostream>
#include<queue>
#define M 1000006
using namespace std;

int n, k;
long long a[M];
priority_queue <pair<long long, int>> pq;

void process(){
    while(pq.size() != 0){
        pq.pop();
    }
    pq.push({a[1], 1});
    for(int i = 2; i <= n; i++){
        while(pq.size() != 0 && pq.top().second < i - k){
            pq.pop();
        }
        long long temp = a[i] + pq.top().first;
        if(i == n){
            cout << temp << "\n";
        }
        pq.push({temp, i});
    }
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        process();
    }
    return 0;
}