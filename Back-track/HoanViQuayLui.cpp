#include<iostream>
#include<algorithm>

using namespace std;
#define M 1000006

int n;
int a[M], mark[M];

void display(){
    for(int i = 1; i <= n; i++){
        cout << a[i];
    }
    cout << "\n";
}

void Try(int pos){
    for(int i = 1; i <= n; i++){
        if(mark[i] == 0){
            a[pos] = i;
            mark[i] = 1;
            if(pos == n){
                display();
            }
            else{
                Try(pos + 1);
            }
            mark[i] = 0;
        }  
    } 
}

void process(){
    cin >> n;
    Try(1);
}

int main(){
    process();
}
    