#include<iostream>
#include<vector>

using namespace std;

int a[100];
int n = 0, c = 1, mark = 0;
void sinh(){
    int i = c; 
    while(i > 0 && a[i] == 1){
        i--;
    }   
    if(i == 0){
        mark = 1;
    }
    else{
        a[i]--;
        int d = 1 + c - i;
        c = i;
        int nguyen = d / a[i];
        int du = d % a[i];
        for(int j = 1; j <= nguyen; j++){
            c++;
            a[c] = a[i];
        }
        if(du != 0){
            c++;
            a[c] = du;
        }
    }
    
}

void hienThi(){
    cout << "(";
    for(int i = 1; i < c; i++){
        cout << a[i] << " ";
    }
    cout << a[c] << ") ";
}

void process(){
    int n;
    scanf("%d", &n);
    a[1] = n;
    c = 1;
    mark = 0;
    while(mark == 0){
        hienThi();
        sinh();
    }
    printf("\n");
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
         process();
    }
    return 0;
}