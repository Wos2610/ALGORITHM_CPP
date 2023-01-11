#include<iostream>
#include<algorithm>
#include<stdbool.h>
#include<math.h>
#include<vector>
#include<map>
#include<queue>

#define M 100006

using namespace std;
int n;
string save;
int a[M];
int m, in, inl, inr;
queue<pair<int, int>> q;
int mark[M], d[M];

void search(){
    q.push({in,m});
    d[in] = 0;
    mark[in] = 1;
    // cout << q.front().first;
    while(q.size() != 0){
        int temp = q.front().second;
        int i = q.front().first;
        int d1 = 0;
        int d2 = 0;
        q.pop();
        int left = -1;
        int right = -1;
        for(int j = 1; j < i; j++){
            if(mark[j] == 0 && a[j] > left){
                left = a[j];
                inl = j;
                d1 = 1;
            }
        }
        if(d1 == 1){
            q.push({inl,left});
            mark[inl] = 1;
            d[inl] = d[i] + 1;
        }
        
        

        for(int j = i + 1; j <= n; j++){
            if(mark[j] == 0 && a[j] > right){
                right = a[j];
                inr = j;
                d2 = 1;
            }
        }
        if(d2 == 1){
            q.push({inr,right});
            mark[inr] = 1;
            d[inr] = d[i] + 1;
        }
    }
    
}

int main() {
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        m = -1;
        in = -1;
        for(int i = 0; i <= M; i++){
            mark[i] = 0;
            d[i] = 0;
        }
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            if(m < a[i]){
                m = a[i];
                in = i;
            }
        }
        // cout << m << " " << in << "\n";
        d[m] = 1;
        search();
        for(int i = 1; i <= n; i++){
            cout << d[i] << " ";
        }
        cout << "\n";
    }
    
}
