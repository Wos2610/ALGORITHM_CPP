#include<iostream>

using namespace std;

int a[1000006];

void quickSort(int a[], int l, int r){
    int pivot = a[(l + r)/2];
    int i = l;
    int j = r;
    while(i <= j){
        while(a[i] > pivot){
            i++;
        }
        while(a[j] < pivot){
            j--;
        }
        if(i <= j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if(i < r){
        quickSort(a, i, r);
    }
    if(j > l){
        quickSort(a, l, j);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    quickSort(a, 0, n - 1);
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}