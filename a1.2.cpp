#include <stdio.h>
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int l, int h)
 {
    int p = arr[h];  
    int i = (l - 1);   

    for (int j = l; j <= h - 1; j++) 
	{
        if (arr[j] < p) 
		{
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}

void quickSort(int arr[], int l, int h) 
{
    if (l < h) 
	{
        int pi = partition(arr, l, h);
        quickSort(arr, l, pi - 1);  
        quickSort(arr, pi + 1, h); 
    }
}

int main() {
    int arr[] = {6, 12, 458, 5, 4, 28, 19, 1230, 9, 47};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Î´ÅÅĞò: ");
    for (int i = 0; i < n; i++) 
	{
        printf("%d ", arr[i]);
    }
    
    quickSort(arr, 0, n - 1);
    
    printf("\nÅÅĞòºó: ");
    for (int i = 0; i < n; i++) 
	{
        printf("%d ", arr[i]);
    }
    return 0;
}
