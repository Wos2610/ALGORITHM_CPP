#include<iostream>
#include<algorithm>
#include<stdbool.h>
#include<math.h>
#include<vector>
#include<map>
#include<queue>

#define M 100006

using namespace std;

int a[M], mark[M];
int n;
void Try(int l, int r, int count){
    if(l >= r){
        return;
    }
    int i = max_element(a + l, a + r) - a;
    if(mark[i] == 0){
        mark[i] = count;
    }
    Try(l, i, count + 1);
    Try(i + 1, r, count + 1);

}
void process(){
    cin >> n;

    for(int i = 0; i < n; i++){
        mark[i] = 0;
        cin >> a[i];
    }

    Try(0, n, 0);
    
    for(int i = 0; i < n; i++){
        cout << mark[i] << " ";
    }
    cout << "\n";
}

int main() {
    int T;
    cin >> T;
    while(T--){
        process();
    }
    
}
