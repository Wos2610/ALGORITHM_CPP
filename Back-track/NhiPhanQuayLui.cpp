#include<iostream>
#include<algorithm>

using namespace std;
#define M 1000006

int n;
int a[M];

void display(){
    for(int i = 1; i <= n; i++){
        cout << a[i];
    }
    cout << "\n";
}

void Try(int pos){
    for(int i = 0; i < 2; i++){
        a[pos] = i;
        if(pos == n){
            display();
        }
        else{
            Try(pos + 1);
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
    