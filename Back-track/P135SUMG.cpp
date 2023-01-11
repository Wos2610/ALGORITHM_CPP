#include<iostream>
#include<string>
#include<vector>

using namespace std;
#define M 1000006

string s;
int n;
long long dem;
int a[106], mark[106];

// mang a     dung de xet xem ki tu la nguyen am hay phu am 
//            nguyen am : 1     phu am : 0
// mang mark  dung de luu chi so trong b
//            mark[i] = 1 -> nguyen am -> thoa man thi temp *= 5
//            mark[i] = 2 -> phu am    -> thoa man thi temp *= 20
//            mark[i] = 3 -> L         -> thoa man thi temp *= 1

string b = " ABL";
// string dai dien 
// A dai dien cho 5 nguyen am -> A thoa man thi 5 nguyen am thoa man
// B dai dien cho 20 phu am tru L -> B thoa man thi 20 phu am thoa man
// L dai dien cho L 

int check(string s){
    int count = 0;
    for(int i = 1; i <= n; i++){
        a[i] = 0;
    }

    for(int i = 1; i <= n; i++){
        if(s[i] == 'A' || s[i] == 'E' || s[i] == 'O' || s[i] == 'U' || s[i] == 'I'){
            a[i] = 1;
        }
        if(s[i] == 'L'){
            count++;
        }
    }
    if(count == 0){ // neu khong co ki tu L 
        return 0;
    }

    for(int i = 1; i <= n - 2; i++){
        if(a[i] == a[i + 1] && a[i + 1] == a[i + 2]){ // neu 3 nguyen am hoac 3 phu am lien ke
            return 0;
        }
    }
    return 1;
}

// Neu ham s thoa man thi tien hanh cong vao ket qua
void cong(){
    long long temp = 1;
    for(int i = 1; i <= n; i++){
        // Neu nguyen am thoa man
        if(mark[i] == 1){
            temp *= 5;
        }
        // Neu phu am tru L thoa man
        else if(mark[i] == 2){
            temp *= 20;
        }
    }
    dem += temp;
}

// string b = " ABL";
void Try(int i){
    if(s[i] == '_'){
        for(int j = 1; j <= 3; j++){
            s[i] = b[j];
            mark[i] = j;
            if(i == n){
                if(check(s)){
                    cong();
                }
            }
            else{
                Try(i + 1);
            }
            s[i] = '_';
        }
    }
    else{
        if(i == n){
            if(check(s)){
                cong();
            }
        }
        else{
            Try(i + 1);
        }
    }  
}
int main(){
    cin >> s;
    n = s.size();
    s = ' ' + s;
    Try(1);
    cout << dem;
}
    