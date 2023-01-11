#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string s1[1000006]  ;
string s2[1000006]  ;

bool compare1(string a, string b){
    if(a < b){
        return true;
    }
    return false;
}

bool compare2(string a, string b){
    int m = a.size();
    int n = b.size();
    while(m > n){
        b = '0' + b;
        n++;
    }
    while(m < n){
        a = '0' + a;
        m++;
    }
    if(a < b){
        return true;
    }
    return false;
}

void process(){
    string s;
    getline(cin, s);
    int n = s.size();

    int index = 0, index1 = 0, index2 = 0;
    int mark[100006] = {0};
    for(int i = 0; i < n; ){
        if(s[i] == ',' && s[i + 1] == ' ' ){
            if(mark[index] == 1){
                index2++;
            }
            else{
                index1++;
            }
            index++;
            i += 2;
        }
        else if(s[i] == '.'){
            if(mark[index] == 1){
                index2++;
            }
            else{
                index1++;
            }
            index++;
            i++;
        }
        else{
            if(s[i] >= '0' && s[i] <= '9'){
                mark[index] = 1;
                s2[index2].push_back(s[i]);
            }
            else{
                s1[index1].push_back(s[i]);
            }
            i++;
        }
    }
    sort(s1, s1 + index1, compare1);
    sort(s2, s2 + index2, compare2);

    int j = 0, k = 0;
    for(int i = 0; i < index; i++){
        if(mark[i] == 1){
            cout << s2[j];
            j++;
        }
        else{
            cout << s1[k];
            k++;
        }
        if(i != index - 1){
            cout << ", ";
        }
        else{
            cout << ".";
        }
    }
    for(int i = 0; i < index1; i++){
        s1[i].clear();
    }
    for(int i = 0; i < index2; i++){
        s2[i].clear();
    }
    cout << "\n";
    
}

int main(){
    int T;
    scanf("%d", &T);
    cin.ignore();
    while(T--){
        process();
    }
}
    