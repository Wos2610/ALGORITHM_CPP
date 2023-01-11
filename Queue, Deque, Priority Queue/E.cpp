#include<iostream>
#include<algorithm>
#include<deque>
#define M 1000006

using namespace std;

int n, k;
long long dem;
int a[M];

deque <int> dq;

void tinh(){
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        while(dq.size() != 0 && (a[i] - a[dq.front()] >= k)){
            dq.pop_front();
        }
        dem += (long long)dq.size();
        dq.push_back(i);
    }
    cout << dem;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    tinh();
}
