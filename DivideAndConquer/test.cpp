#include<iostream>
#define MOD 1000000007

using namespace std;

int n;

struct Matrix{
    long long m[10][10];
};

Matrix a;

Matrix operator*(Matrix a, Matrix b){
    Matrix ans;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            ans.m[i][j] = 0;
            for(int k = 0; k < 2; k++){
                long long temp = (a.m[i][k] * b.m[k][j]) % MOD;
                ans.m[i][j] = (ans.m[i][j] + temp) % MOD;
            }
        }
    }
    return ans;
}

Matrix dv;
Matrix operator^(Matrix a, long long k){
    if(k == 0){
        return dv;
    }
    if(k % 2 == 0){
        Matrix temp = a^(k/2);
        return temp * temp;
    }
    else{
        Matrix temp = a^(k - 1);
        return temp * a;
    }
}


void process(){
    cin >> n;

    dv.m[0][0] = dv.m[1][1] = 1;
    dv.m[0][1] = dv.m[1][0] = 0;

    a.m[0][0] = a.m[0][1] = a.m[1][0] = 1;
    a.m[1][1] = 0;
    Matrix ans = a^(n - 1);

    cout << ans.m[0][0] << "\n";
}
int main(){
    int T;
    cin >> T;
    while(T--){
        process();
    }
    return 0;
}