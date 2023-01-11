#include<iostream>
#include<vector>
#define M 1000006

using namespace std;

int a, b;
vector<int> mark(1000006, 1);
int f[M], dem[M];

void sieve() {
	mark[0] = mark[1] = 0;
	for (int i = 2; i * i <= M; i++) {
		if (mark[i] == 1) {
			for (int j = i * i; j <= M; j += i) {
				mark[j] = 0;
			}
		}
	}
}


void process(){
    cin >> a >> b;
    cout << f[b] - f[a - 1] << "\n";
}

int main(){
    int T;
    scanf("%d", &T);
    
    sieve();

    dem[0] = dem[1] = 1;
    for(int i = 1; i <= M; i++){
        for(int j = i; j <= M; j += i){
            dem[j]++;
        }
    }

    f[0] = f[1] = 0;
    for(int i = 2; i < M; i++){
        f[i] = f[i - 1];
        if(mark[dem[i]] == 1){
            f[i]++;
        }
    }
    
    while(T--){
        process();
    }
}
    