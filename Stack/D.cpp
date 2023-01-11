#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

int n, m; 
stack <int> st;
int a[1006][1006];
int c[1006][1006];
int l[1006][1006];
int r[1006][1006];

void dem(){
    for(int i = 1; i <= n; i++){
        for(int  j = 1; j <= m; j++){
            if(a[i][j] == 1){
                c[i][j] = c[i - 1][j] + 1;
            }
            else{
                c[i][j] = 0;
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int  j = 1; j <= m; j++){
            cout << c[i][j] << " ";
        }
        cout << "\n";
    }

    stack <int> st1, st2;

    for(int i = 1; i <= n; i++){
        while(st1.size() != 0){
            st1.pop();
        }
        st1.push(0);
        while(st2.size() != 0){
            st2.pop();
        }
        st2.push(m + 1);
        for(int  j = 1; j <= m; j++){
            while(st1.size() != 0 && c[i][st1.top()] >= c[i][j]){
                st1.pop();
            }
            if(st1.size() != 0){
                l[i][j] = st1.top();
            }
            st1.push(j);
        }
        for(int j = m; j >= 1; j--){
            while(st2.size() != 0 && c[i][st2.top()] >= c[i][j]){
                st2.pop();
            }
            if(st2.size() != 0){
                r[i][j] = st2.top();
            }
            st2.push(j);
        }
    }
    int temp = 0, res = -9999;
    for(int i = 1; i <= n; i++){
        for(int  j = 1; j <= m; j++){
            temp = (r[i][j] - l[i][j] - 1) * c[i][j];
            res = max(res, temp);
        }
    }

    cout << res;

}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int  j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    dem();
}
