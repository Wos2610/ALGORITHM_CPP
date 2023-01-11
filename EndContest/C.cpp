#include<iostream>
#include<algorithm>
#include<stdbool.h>
#include<math.h>
#include<vector>
#include<map>
#define M 100006

using namespace std;
int n, d;
string save;
int mark[M];

int check(string m){
    for(int i = 1; i < n; i++){
        if(m[i] == m[i - 1]){
            return 0;
        }
    }
    return 1;
}

string m ;

map<string, int> mp;
vector<string> res;
void Try(int i, int n){
    for(int j = 0; j < n; j++){
        if(mark[j] == 0){
            m[i] = save[j];
            mark[j] = 1;
            if(i == n - 1){
                // cout << m << ";";
                if(check(m) && mp[m] == 0){
                    d = 1;
                    res.push_back(m);
                    mp[m] = 1;
                    // cout << "\n";
                }
            }
            else{
                Try(i + 1, n);
            }
            mark[j] = 0;
        }
        
    }
}
int main() {
    
    string s;
    cin >> s;
    n = s.size();
    for(int i = 0; i < n; i++){
        save.push_back(s[i]);
    }
    // cout << check(s);
    m.resize(n);
    Try(0, n);
    sort(res.begin(), res.end());
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << "\n";
    }
    if(d == 0){
        cout << "INVALID";
    }
}
