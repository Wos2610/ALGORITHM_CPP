#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

void quickSort(int a[], int l, int r){
    int i = l;
    int j = r;
    int pivot = a[(l + r)/2];

    while(i <= j){
        while(a[i] < pivot){
            i++;
        }
        while(a[j] > pivot){
            j--;
        }
        if(i <= j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if(l < j){
        quickSort(a, l, j);
    }
    if(r > i){
        quickSort(a, i, r);
    }
}

void process(){
    char a[100006], s[100006];
    scanf("%s%s", &a, &s);
    int s1[100006] = {0};
    int m = strlen(a);
    int n = strlen(s);
    for(int i = 0; i < n; i++){
        s1[i] = s[i] - '0';
    }

    quickSort(s1, 0, n - 1);
    
    int j = n - 1;
    for(int i = 0; i < m; i++){
        if(a[i] < s1[j] + '0'){
            a[i] = s1[j] + '0';
            j--;
        }
    }
   printf("%s\n", a);
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        process();
    }
}
    