#include<iostream>
#define MOD 1000000007

using namespace std;

int n;
struct Matrix{
    long long m[10][10];
};

Matrix a;  
// Ham nhan hai ma tran
Matrix mul(Matrix a, Matrix b){
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
// Ham luy thua ma tran
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
    cin >> n;
    
    // Khoi tao vector don vi
    for(int i = 0 ; i < 2; i++){
        for(int j = 0; j < 2; j++){
            if(i == j){
                dv.m[i][j] = 1;
            }
            else{
                dv.m[i][j] = 0;
            }
        }
    }

    // Khoi tao ma tran a
    a.m[0][0] = 1;
    a.m[1][0] = 1;
    a.m[0][1] = 1;
    a.m[1][1] = 0;

    Matrix ans = pow(a, n - 1);

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