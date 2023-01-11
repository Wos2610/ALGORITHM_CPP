#include<iostream>
#include<vector>

using namespace std;

int a[1000006];
vector<int> save;

void quickSort(int a[], int l, int r){
    int pivot = a[(l + r)/2];
    int i = l;
    int j = r;
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

    if(i < r){
        quickSort(a, i, r);
    }
    if(j > l){
        quickSort(a, l, j);
    }
}

void search(int a[], int k, int n ){
    save.emplace_back(a[0]);
    for(int i = 1; i < n ; i++){
        if(a[i] != a[i - 1]){
            save.emplace_back(a[i]);
        }
    }
    // for(int i = 0; i < save.size() ; i++){
    //     printf("%d ", save[i]);
    // }
    if(save.size() < k){
        printf("-1");
    }
    else{
        printf("%d", save[k - 1]);
    }
    
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    quickSort(a, 0, n - 1);
    search(a, k, n);
}