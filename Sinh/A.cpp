#include<iostream>
#include<string.h>

using namespace std;

void NP(char s[]){
    int n = strlen(s);
    int mark = 0;
    for(int i = n - 1; i >= 0; i--){
        if(s[i] == '0'){
            mark = 1;
            s[i] = '1';
            for(int j = i + 1; j < n; j++){
                s[j] = '0';
            }
            break;
        }
    }
    if(mark == 0){
        for(int i = 0; i < n; i++){
            s[i] = '0';
        }
    }
    printf("%s\n", s);
}

char s[1000006];
void process(){
    scanf("%s", &s);
    NP(s);
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        process();
    }
    return 0;
}