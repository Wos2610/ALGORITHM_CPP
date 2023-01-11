#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> a(1000006, 0); 
vector<int> mark(1000006, 0); 
int n = 0;

void Try(int pos){
    for(int i = 1; i <= n; i++){
        if(mark[i] == 0){
            a[pos] = i;
            mark[i] = 1;
            Try(pos + 1);
            mark[i] = 0;
        }
    }
    if(pos == n){
        for(int i = 1; i <= n; i++){
            cout << a[i];
        }
        cout << " ";
        return;
    }
}

void process(){
    cin >> n;
    Try(1);
}

int main(){
    process();
}
    