#include <stdio.h>

int bubbleSort(int arr[], int size) {
    int steps = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                steps++;
            }
        }
    }
    return steps;
}

int main() {
    int N;
    scanf("%d", &N);
    
    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    
    int steps = bubbleSort(arr, N);
    printf("%d\n", steps);
    
    return 0;
}
