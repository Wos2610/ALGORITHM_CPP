#include<iostream>
#include<string>
#include<stack>

using namespace std;

int n;
string s;
stack<string> st;

void check(){
    for(int i = 0; i < n; i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            string s1 = "";
            s1 = s[i];
            st.push(s1);
        }
        else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            string c1 = "";
            string c2 = "";
            if(st.size() != 0){
                c1 = st.top();
                st.pop();
            }
            if(st.size() != 0){
                c2 = st.top();
                st.pop();
            }

            string temp = s[i] + c2 + c1;

            st.push(temp);
        }
    }

    cout << st.top();
}

int main(){
    cin >> s;
    n = s.size();
    check();
}
