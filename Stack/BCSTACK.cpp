#include<iostream>
#include<algorithm>
#include<stack>
#define M 1000006

using namespace std;

stack<int> st;
int x;


int main(){
    string s;
    while(1){
        cin >> s;
        if(s == "end"){
            return 0;
        }
        if(s == "init"){
            while(st.size() != 0){
                st.pop();
            }
        }
        if(s == "push"){
            cin >> x;
            st.push(x);
        }
        if(s == "pop"){
            if(st.size() != 0){
                st.pop();
            }
        }
        if(s == "top"){
            if(st.size() != 0){
                cout << st.top() << "\n";
            }
            else{
                cout << "-1\n";
            }
        }
        if(s == "size"){
            cout << st.size() << "\n";
        }
        if(s == "empty"){
            if(st.empty() == true){
                cout << "1" << "\n";
            }
            else{
                cout << "0" << "\n";
            }
        }
    }
}
