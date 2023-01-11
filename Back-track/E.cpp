#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, x, dem, sum, l;
int a[26], b[1000006], save[10006][106];

void Try(int i){
    for(int j = i; j <= n; j++){
        b[l] = a[j];
        sum += a[j];
        if(sum < x){
            l++;
            Try(j);
            l--;
        }
        else if(sum == x){
            dem++;
            for(int p = 1; p <= l; p++){
                save[dem][p] = b[p];
            }
            save[dem][0] = l;
        }
        sum -= a[j];
    }
}

void display(){
    if(dem == 0){
        printf("-1\n");
        return;
    }
    printf("%d ", dem);
    for(int i = 1; i <= dem; i++){
        printf("{");
        int y = save[i][0];
        for(int j = 1; j <= y; j++){
            printf("%d", save[i][j]);
            if(j != y){
                printf(" ");
            }
        }
        printf("}");
        if(i != dem){
            printf(" ");
        }
    }
    printf("\n");
}

void process(){
    scanf("%d%d", &n, &x);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    sum = 0, dem = 0, l = 1;
    sort(a + 1, a + 1 + n);
    Try(1);
    display();
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        process();
    }
}
    