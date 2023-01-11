#include<iostream>
#include<string>
#include<vector>
#include<stack>

#define M 1000006

using namespace std;

string s;
vector<char> m;
stack<char> c;

int main(){
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            c.push(s[i]);
        }
        if(s[i] >= 'a' && s[i] <= 'z'){
            c.push(s[i]);
        }
        if(s[i] >= '0' && s[i] <= '9'){
            m.push_back(s[i]);
        }
    }

    while(c.size() != 0){
        cout << c.top();
        c.pop();
    }

    cout << "\n";

    for(int i = 0; i < m.size(); i++){
        cout << m[i];
    }
}
