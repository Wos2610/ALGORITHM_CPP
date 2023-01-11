#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<vector<int>> a(1000, vector<int> (1000, 0));
vector<vector<int>> save(10000, vector<int> (1000, 0));
vector<int> b(1000000);
int mark = 0, n = 0, k = 0, c = 0;

void sinhHV(){
    int i = n - 1;
    while(i >= 1 && b[i] >= b[i + 1]){
        i--;
    }
    if(i == 0){
        mark = 1;
    }
    else{
        int temp = -1;
        for(int j = n; j > i; j--){
            if(b[j] > b[i]){
                temp = j;
                break;
            }
        }
        swap(b[temp], b[i]);
        sort(b.begin() + 1 + i, b.begin() + 1 + n);
    }
}

void hienThi(){
    cout << c << "\n";
    for(int i = 1; i <= c; i++){
        for(int j = 1; j <= n; j++){
            cout << save[i][j] << " ";
        }
        cout << "\n";
    }
    
}

void process(){
    for(int i = 1; i <= n; i++){
        b[i] = i;
    }

    while(mark == 0){
        int sum = 0;
        for(int i = 1; i <= n; i++){
            sum += a[i][b[i]];  
        }
        if(sum == k){
            c++;
            for(int j = 1; j <= n; j++){
                save[c][j] = b[j];
            }
             
        }
        sinhHV();
    }
    hienThi();

}
int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    process();
}