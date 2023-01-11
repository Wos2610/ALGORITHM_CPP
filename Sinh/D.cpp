#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> a(1000006, 0);
int mark = 0;
void NP(int n){
    int i = n;
    while(i >= 1 && a[i] == 1){
        a[i] = 0;
        i--;
    }
    if(i == 0){
        mark = 1;
    }
    else{
        a[i] = 1;
    }
}

void process(){
    int n;
    scanf("%d", &n);
    mark = 0;
    for(int i = 1; i <= n; i++){
        a[i] = 0;
    }
    while(mark == 0){
        for(int i = 1; i <= n; i++){
            printf("%c", a[i] + 'A');
        } 
        printf(" ");
        NP(n);
    } 
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        process();
        printf("\n");
    }
    return 0;
}