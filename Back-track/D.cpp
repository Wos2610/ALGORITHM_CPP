#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int k, n;
string s, s1, res;

void Try(string s, int i, int k){
    if(k == 0 || i == n - 1){
        res = max(res, s);
        return;
    }
    for(int j = i + 1; j < n; j++){
        if(s[j] > s[i]){
            swap(s[j], s[i]);
            if(k > 0){
                Try(s, i + 1, k - 1);
            }
            swap(s[i], s[j]);
        }
        else{
            Try(s, i + 1, k);
        }
    }
}

void process(){
    cin >> k;
    cin >> s;
    n = s.size();
    res = s;
    Try(s, 0, k);
    cout << res << "\n";
}

int main(){
    int T;
    cin >> T;
    while(T--){
        process();
    }
}
    