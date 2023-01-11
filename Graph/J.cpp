#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#define M 1000006

using namespace std;
string s;
queue <pair<string, int>> q1, q2;
string s0 = "1238004765";

map<string, int> m;

string left1(string s1, string s){
    s1[0] = s[3];
    s1[1] = s[0];
    s1[3] = s[7];
    s1[5] = s[1];
    s1[7] = s[8];
    s1[8] = s[5];
    return s1;
}

string right1(string s1, string s){
    s1[1] = s[4];
    s1[2] = s[1];
    s1[4] = s[8];
    s1[6] = s[2];
    s1[8] = s[9];
    s1[9] = s[6];
    return s1;
}
string left2(string s1, string s){
    s1[0] = s[1];
    s1[1] = s[5];
    s1[3] = s[0];
    s1[5] = s[8];
    s1[7] = s[3];
    s1[8] = s[7];
    return s1;
}

string right2(string s1, string s){
    s1[1] = s[2];
    s1[2] = s[6];
    s1[4] = s[1];
    s1[6] = s[9];
    s1[8] = s[4];
    s1[9] = s[8];
    return s1;
}

int ans = 999999;
void BFS(){
    while(q1.size() != 0){
        string u = q1.front().first;
        int d = q1.front().second;
        string s1 = u;
        string s2 = u;
        s1 = left1(s1, u);
        q1.push({s1, d + 1});
        if(m[s1] == 0){
            m[s1] = d + 1;
        }

        s2 = right1(s2, u);
        q1.push({s2, d + 1});
        if(m[s2] == 0){
            m[s2] = d + 1;
        
        }
        
        q1.pop();
        
        if(d == 14){
            break;
        }
    }

    while(q2.size() != 0){
        string u = q2.front().first;
        int d = q2.front().second;
        if(m[u] != 0){
            ans = min(ans, m[u] + d);
        }
        
        string s1 = u;
        string s2 = u;
        s1 = left2(s1, u);
        q2.push({s1, d + 1});
        s2 = right2(s2, u);
        q2.push({s2, d + 1});
        q2.pop();
        
        if(d == 14){
            break;
        }
    }


}

int main() {
    char x;
    for(int i = 0; i < 10; i++){
        cin >> x;
        s.push_back(x);
    }
    q1.push({s, 0});
    q2.push({s0, 0});
    BFS();
    cout << ans;
}