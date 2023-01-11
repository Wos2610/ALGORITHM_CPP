#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;


int main(){
    string s;
    cin >> s;
    int n = s.size();
    int index = 0;
    
    string res;
    for(int i = 0; i < n; i++){
        int k = res.size();
        if(k != 0 && s[i] == '-' && index != 0){
            res.erase(index - 1,1);
            index--;
        }
        else if(s[i] == '<' && index != 0){
            index--;
        }
        else if(s[i] == '>' && index != k){
            index++;
        }
        else if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')){
            res.insert(res.begin() + index, s[i]);
            index++;
        }
    }

    for(int i = 0;i < res.size(); i++){
        cout << res[i];
    }
}