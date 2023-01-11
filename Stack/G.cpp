#include<iostream>
#include<string>
#include<stack>
#define M 1000006

using namespace std;

stack <char> st;

int main(){
    string s;
    cin >> s;
    long long n = s.size();
    long long count = 0;
    for(long long i = 0; i < n; i++){
        if(s[i] == '('){
            st.push(s[i]);
        }
        if(st.size() != 0 && s[i] == ')'){
            count += 2;
            st.pop();
        }
    }

    cout << count;
}