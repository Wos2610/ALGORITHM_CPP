#include<iostream>
#include<queue>
#include<string>
#include<map>
#define M 1000006
using namespace std;

string s, t;
int a[M], b[M];
queue<pair<string, int>> q;

string left(string v, string u){
    v[0] = u[3];
    v[1] = u[0];
    v[3] = u[4];
    v[4] = u[1];
    return v;
}

string right(string v, string u){
    v[1] = u[4];
    v[2] = u[1];
    v[4] = u[5];
    v[5] = u[2];
    return v;
}

void process(){
    if(s == t){
        cout << "0\n";
        return;
    }
    while(q.size() != 0){
        q.pop();
    }

    q.push({s, 0});
    
    while(q.size() != 0){
        
        string u = q.front().first;

        string v1 = u;
        v1 = left(v1, u);
        // cout << v1 << " " << q.front().second << " ";
        q.push({v1, q.front().second + 1});
        
        
        if(v1 == t){
            break;
        }

        string v2 = u;
        v2 = right(v2, u);
        q.push({v2, q.front().second + 1});
        // cout << v2 << " " << q.front().second << "\n";
        q.pop();

        
        if(v2 == t){
            break;
        }
    }
    
    cout << q.back().second << "\n";
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        s = "";
        t = "";
        for(int i = 0; i < 6; i++){
            cin >> a[i];
            s.push_back(a[i] + '0');
        }
        for(int i = 0; i < 6; i++){
            cin >> b[i];
            t.push_back(b[i] + '0');
        }
        process();
    }
    return 0;
}