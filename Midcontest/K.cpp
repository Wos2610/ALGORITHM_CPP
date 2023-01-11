#include<iostream>
#include<algorithm>
#include<vector>
#define M 1000006

using namespace std;

int n;
long long k;
vector<long long> a(M, 0);

int main(){
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.begin() + n);

    long long count = 0;
    int j = -1;
    for(int i = n - 1; i >= 0; i--){
        int temp = a[i] - k;
        if(temp >= 0){
            j = upper_bound(a.begin(), a.begin() + i, temp) - a.begin();
        }
        else{
            j = lower_bound(a.begin(), a.begin() + i, temp) - a.begin();
        }
        count += i - j ;
    }

    cout << count;

}