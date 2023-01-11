#include<iostream>
#include<string>

using namespace std;

int a[1000006] = {0};

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

int main(){
    int n;
    scanf("%d", &n);
    int index = 0;
    for(int i = 0; i < n; i++){
        string x;
        cin >> x;
        int m = x.size();
        for(int j = 0; j < m; j++){
            a[index] = x[j] - '0';
            index++;
        }
    }
    quickSort(a, 0, index - 1);

    for(int i = 0; i < index; i++){
        cout << a[i] << " ";
    }
    
}