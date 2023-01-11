#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<queue>
#define MOD 1000000007

using namespace std;
int n, k;
vector<long long> f;
priority_queue<long long, vector<long long>, greater<long long>> q;
vector<long long> a;
map<long long, int> mark;

void process(){
    q.push(1);
    while(a.size() <= 10000){
        long long b = q.top();
        q.pop();
        a.push_back(b);
        long long temp = 0;
        temp = 2 * b;
        if(mark[temp] == 0){
            mark[temp] = 1;
            q.push(temp);
        }
        temp = 3 * b;
        if(mark[temp] == 0){
            mark[temp] = 1;
            q.push(temp);
        }
        temp = 5 * b;
        if(mark[temp] == 0){
            mark[temp] = 1;
            q.push(temp);
        }
    }
    sort(a.begin(), a.end());
}

int main(){
    int T;
    scanf("%d", &T);
    process();
    while(T--){
        scanf("%d", &n);
        cout << a[n - 1] << "\n";
    }
    return 0;
}