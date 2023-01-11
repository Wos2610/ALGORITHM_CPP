#include<iostream>
#include<algorithm>

using namespace std;


void Try(string s, int n){
    if(s.size() == n){
        cout << s << " ";
        return;
    }
    Try(s + "0", n);
    Try(s + "1", n);
}

void process(){
    int n;
    cin >> n;
    string s = "";
    Try(s, n);
}

int main(){
    process();
}
    