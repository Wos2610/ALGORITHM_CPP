#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> a(1000006, 0); 

int n = 0, k = 0;

void Try(int pos){
    if(pos == k){
        for(int i = 1; i <= k; i++){
            cout << a[i];
        }
        cout << " ";
        return;
    }
    for(int i = a[pos] + 1; i <= n; i++){
        a[pos + 1] = i;
        Try(pos + 1);
    }
}

void process(){
    cin >> n >> k;
    Try(0);
}

int main(){
    process();
}
    