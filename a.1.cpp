#include <stdio.h>
#include <stdlib.h>
// 希尔排序
void shellSort(int arr[], int n) 
{
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2) 
	{
        for (i = gap; i < n; i++) 
		{
            temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
			{
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}
// 快速排序
void quickSort(int arr[], int left, int right) 
{
    if (left >= right) return;
    int i = left, j = right, pivot = arr[left];
    while (i < j) 
	{
        while (i < j && arr[j] >= pivot) j--;
        if (i < j) arr[i++] = arr[j];
        while (i < j && arr[i] < pivot) i++;
        if (i < j) arr[j--] = arr[i];
    }
    arr[i] = pivot;
    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}

// 大根堆排序
void maxHeapify(int arr[], int start, int end) 
{
    int dad = start, son = dad * 2 + 1;
    while (son <= end) {
        if (son + 1 <= end && arr[son] < arr[son + 1]) 
		{
            son++;
        }
        if (arr[dad] > arr[son]) 
		{
            return;
        } else {
            int temp = arr[dad];
            arr[dad] = arr[son];
            arr[son] = temp;
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void heapSort(int arr[], int len) 
{
    int i;
    for (i = len / 2 - 1; i >= 0; i--) 
	{
        maxHeapify(arr, i, len - 1);
    }
    for (i = len - 1; i > 0; i--) 
	{
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        maxHeapify(arr, 0, i - 1);
    }
}

// 小根堆排序
void minHeapify(int arr[], int start, int end) 
{
    int dad = start, son = dad * 2 + 1;
    while (son <= end) 
	{
        if (son + 1 <= end && arr[son] > arr[son + 1]) 
		{
            son++;
        }
        if (arr[dad] < arr[son]) 
		{
            return;
        } 
		else 
		{
            int temp = arr[dad];
            arr[dad] = arr[son];
            arr[son] = temp;
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void minHeapSort(int arr[], int len) 
{
    int i;
    for (i = len / 2 - 1; i >= 0; i--) 
	{
        minHeapify(arr, i, len - 1);
    }
    for (i = len - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        minHeapify(arr, 0, i - 1);
    }
}
// 归并排序
void merge(int arr[], int left, int mid, int right) 
{
    int len = right - left + 1;
    int *temp = (int*)malloc(sizeof(int) * len);
    int p1 = left, p2 = mid + 1, i = 0;
    while (p1 <= mid && p2 <= right) 
	{
        temp[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
    }
    while (p1 <= mid) 
	{
        temp[i++] = arr[p1++];
    }
    while (p2 <= right) {
        temp[i++] = arr[p2++];
    }
    for (i = 0; i < len; i++) 
	{
        arr[left + i] = temp[i];
    }
    free(temp);
}
void mergeSort(int arr[], int left, int right) 
{
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// 计数排序
void countingSort(int arr[], int n) 
{
    int max = arr[0], min = arr[0];
    for (int i = 1; i < n; i++) 
	{
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    int len = max - min + 1;
    int *count = (int*)malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++) 
	{
        count[i] = 0;
    }
    for (int i = 0; i < n; i++) 
	{
        count[arr[i] - min]++;
    }
    int index = 0;
    for (int i = 0; i < len; i++) 
	{
        for (int j = 0; j < count[i]; j++) 
		{
            arr[index++] = i + min;
        }
    }
    free(count);
}
int main() {
    int arr[] = {6, 12, 458, 5, 4, 28, 19, 1230, 9, 47};
    int n = sizeof(arr) / sizeof(arr[0]);

    // 希尔排序
    shellSort(arr, n);
    printf("希尔排序结果：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 快速排序
    quickSort(arr, 0, n - 1);
    printf("快速排序结果：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 大根堆排序
    heapSort(arr, n);
    printf("大根堆排序结果：");
    for (int i = 0; i < n; i++) 
	{
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 小根堆排序
    minHeapSort(arr, n);
    printf("小根堆排序结果：");
    for (int i = 0; i < n; i++) 
	{
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // 归并排序
    mergeSort(arr, 0, n - 1);
    printf("归并排序结果：");
    for (int i = 0; i < n; i++) 
	{
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // 计数排序
    countingSort(arr, n);
    printf("计数排序结果：");
    for (int i = 0; i < n; i++) 
	{
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
