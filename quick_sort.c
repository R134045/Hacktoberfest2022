#include <stdio.h>

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int l, int r) {
    int pi = arr[r];
    int i = (l - 1);

    for (int j = l; j <= r - 1; j++) {
        if (arr[j] < pi) {
            i++;
            swap(arr, i, j);
        }
    }

    swap(arr, i + 1, r);
    return i + 1;
}

void QuickSort(int arr[], int l, int r) {
    if (l < r) {
        int pi = partition(arr, l, r);
        QuickSort(arr, l, pi - 1);
        QuickSort(arr, pi + 1, r);
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    QuickSort(arr, 0, n - 1);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
