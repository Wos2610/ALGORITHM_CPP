#include<iostream>
#include<algorithm>
#include<vector>
#define M 1000006

using namespace std;

long long l, r;
vector<long long> a, res;
vector<vector<long long>> save;

void Try(int i, int n){
    for(int j = 1; j <= 9; j++){
        a[i] = a[i - 1] + 1;
        if(i == n){
            save.push_back(a);
            i = 0;
        }
        else{
            Try(i + 1, n);
        }
        a.clear();
    }
}

int main(){
    cin >> l >> r;

    int k = 1;
    for(int i = 2; i <= 9; i++){
        for(int j = 1; j < 9; j++){
            a.push_back(j);
            k = j + 1;
            while(a.size() != i){
                a.push_back(k);
                k++;
                if(k > 9){
                    break;
                }
            }
            if(a.size() == i){
                save.push_back(a);
            }
            a.clear();
        }
    }

    // for(int i = 0; i < save.size(); i++){
    //     for(int j = 0; j < save[i].size(); j++){
    //         cout << save[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    for(int i = 0; i < save.size(); i++){
        long long temp = 0;
        for(int j = 0; j < save[i].size(); j++){
            temp = temp * 10 + save[i][j];
        }
        res.push_back(temp);
    }

    // for(int i = 0; i < res.size(); i++){
    //     cout << res[i] << " ";
    // }
    int dem = 0;
    for(int i = 0; i < res.size(); i++){
        if(res[i] >= l && res[i] <= r){
            dem++;
        }
    }
    cout << dem << "\n";
    
    cout << "[";
    for(int i = 0; i < res.size(); i++){
        if(res[i] >= l && res[i] <= r){
            cout << "[" << res[i] << "]";
            if(res[i + 1] < r){
                cout << ", ";
            }
        }
    }
    cout << "]";
}