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


void process(){
    scanf("%d", &n);
    queue<pair<int, int>> q;
    q.push({n, 0});
    map<int,int> m;
    if(n == 1){
        cout << "0\n";
        return;
    }
    while(q.size() != 0){
        int temp = q.front().first;
        int d = q.front().second;
        q.pop();
        int temp1 = temp - 1;
        if(temp1 == 1){
            break;
        }
        if(m[temp1] == 0){
            q.push({temp1, d + 1});
            m[temp1] = 1;
        }
        for(int i = 2; i <= sqrt(temp); i++){
            if(temp % i == 0){
                int temp2 = temp/i;
                if(temp2 == 1){
                    break;
                }
                if(m[temp2] == 0){
                    q.push({temp2, d + 1});
                    m[temp2] = 1;
                }
            }
        }
    }
    printf("%d\n", q.back().second);
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--){
        process();
    }
    
}