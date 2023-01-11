#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

string st, en;
queue <pair<string, int>> q;

int r0[] = {-2, -2, -1, -1, 2, 2, 1, 1};
int r1[] = {-1, 1, -2, 2, -1, 1, -2, 2};

void process(){
    if(en == st){
        cout << "0\n";
        return;
    }
    while(q.size() != 0){
        q.pop();
    }
    q.push({st, 0});
    int mark = 0;
    while(q.size() != 0){
        string u = q.front().first;
        string v = u;
        for(int i = 0; i < 8; i++){
            v[0] = u[0] + r0[i];
            v[1] = u[1] + r1[i];
            if(v[0] >= 'a' && v[0] <= 'h' && v[1] >= '1' && v[1] <= '8'){
                q.push({v, q.front().second + 1});
            }
            if(v == en){
                mark = 1;
                break;
            }
        }
        if(mark == 1){
            break;
        }
        q.pop();
    }
    cout << q.back().second << "\n";
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> st >> en;
        process();
    }
    return 0;
}