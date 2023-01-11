#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>

#define MOD 1000000007

using namespace std;
int n;

struct Box{
    int w;
    int d;
    int h;
};

Box b[1006];

bool cmp(Box b1, Box b2){
    if(b1.w == b2.w){
        return b1.d > b2.d;
    }
    return b1.w > b2.w;
}

int f[1006];
void process(){
    for(int i = 0; i < n; i++){
        int j = i - 1;
        int temp = 0;
        while(j >= 0){
            if(b[i].w < b[j].w && b[i].d < b[j].d){
                temp = max(temp, f[j]);
            }
            j--;
        }
        if(temp == 0){
            f[i] = b[i].h;
        }
        else{
            f[i] = temp + b[i].h;
        }
    }

    sort(f, f + n);
    cout << f[n - 1];
}
int main(){
    int T;
    T = 1;
    while(T--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            cin >> b[i].w >> b[i].d >> b[i].h;
        }
        sort(b, b + n, cmp);
        process();
    }
    return 0;
}