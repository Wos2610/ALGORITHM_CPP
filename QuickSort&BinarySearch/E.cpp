#include<iostream>
#include<algorithm>

using namespace std;

struct Number{
    int num;
    int count = 0;
};

Number a[1000006];

int isAppear(Number a[], int index, int x){
    for(int i = 0; i < index; i++){
        if(x == a[i].num){
            return i;
        }
    }
    return -1;
}

bool compare(Number a1, Number a2){
    if(a1.count != a2.count){
        return a1.count > a2.count;
    }
    return a1.num < a2.num;
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        int x;
        int index = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            if(isAppear(a, index, x) == -1){
                a[index].num = x;
                a[index].count = 1;
                index++;
            }
            else{
                a[isAppear(a, index, x)].count++;
            }
        }
        sort(a, a + index, compare);
        for(int i = 0; i < index; i++){
            for(int j = 0; j < a[i].count; j++){
                 printf("%d ", a[i].num);
            }
        }
        printf("\n");
    }
    }
    