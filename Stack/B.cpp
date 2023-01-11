#include<iostream>
#include<string>
#include<vector>
#include<stack>

#define M 1000006

using namespace std;

int n;
string s;
stack<char> tt;

void check(){
    for(int i = 0; i < n; i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            cout << s[i] ;
        }
        if(s[i] == '('){
            tt.push(s[i]);
        }
        if(s[i] == ')'){
            while(tt.size() != 0 && tt.top() != '('){
                cout << tt.top();
                tt.pop();
            }
            if(tt.size() != 0 && tt.top() == '('){
                tt.pop();
            }
        }

        if(s[i] == '+' || s[i] == '-'){
            if(tt.size() != 0){
                while(tt.size() != 0 && tt.top() != '('){
                    cout << tt.top();
                    tt.pop();
                }
            }
            tt.push(s[i]);
        }

        if(s[i] == '*' || s[i] == '/'){
            if(tt.size() != 0){
                while(tt.size() != 0 && (tt.top() == '*' || tt.top() == '/' ) ){
                    cout << tt.top();
                    tt.pop();
                }
            }
            tt.push(s[i]);
        }
    }
    
    while(tt.size() != 0){
        cout << tt.top();
        tt.pop();
    }
}
int main(){
    cin >> s;
    n = s.size();
    check();
}
