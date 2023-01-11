#include<iostream>
#define MOD 1000000007

using namespace std;

int n;
struct Matrix{
    long long m[16][16];
};

Matrix a;

Matrix mul(Matrix a, Matrix b){
    Matrix ans;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ans.m[i][j] = 0;
            for(int k = 0; k < n; k++){
                long long temp = (a.m[i][k] * b.m[k][j]) % MOD;
                ans.m[i][j] = (ans.m[i][j] + temp) % MOD;
            }
        }
    }

    return ans;
}

Matrix dv;

Matrix pow(Matrix a, int k){
    if(k == 0){
        return dv;
    }
    else if(k % 2 == 0){
        Matrix temp = pow(a, k/2);
        return mul(temp, temp);
    }
    else {
        Matrix temp = pow(a, k - 1);
        return mul(temp, a);
    }
}

void process(){
    int k;
    cin >> n >> k;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a.m[i][j];
        }
    }
    
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                dv.m[i][j] = 1;
            }
            else{
                dv.m[i][j] = 0;
            }
        }
    }

    Matrix ans = pow(a, k);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << ans.m[i][j] << " ";
        }
        cout << "\n";
    }
}
int main(){
    int T;
    cin >> T;
    while(T--){
        process();
    }
    return 0;
}