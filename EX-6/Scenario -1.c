#include <stdio.h>
#include <stdlib.h>

void merge(double arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    double* L = (double*)malloc(n1 * sizeof(double));
    double* R = (double*)malloc(n2 * sizeof(double));
    
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    free(L);
    free(R);
}

void mergeSort(double arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void displayPrices(double arr[], int size) {
    printf("Sorted Product Prices:\n");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of products: ");
    scanf("%d", &n);
    
    double* prices = (double*)malloc(n * sizeof(double));
    if (prices == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    printf("Enter the prices of the products:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &prices[i]);
    }
    
    mergeSort(prices, 0, n - 1);
    displayPrices(prices, n);
    
    free(prices);
    return 0;
}
