#include <stdio.h>
// œ£∂˚≈≈–Ú
void shellSort(int arr[], int n) 
{
    int s, i, j, temp;

    for (s = n/2; s > 0; s /= 2) 
	{

        for (i = s; i < n; i++) 
		{
            temp = arr[i];
            for (j = i; j >= s && arr[j-s] > temp; j -= s) 
			{
                arr[j] = arr[j-s];
            }
            
            arr[j] = temp;
        }
    }
}

int main() 
{
    int arr[] = {6, 12, 458, 5, 4, 28, 19, 1230, 9, 47};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Œ¥≈≈–Ú: ");
    for (int i = 0; i < n; i++) 
	{
        printf("%d ", arr[i]);
    }
    
    shellSort(arr, n);
    
    printf("\n≈≈–Ú∫Û: ");
    for (int i = 0; i < n; i++) 
	{
        printf("%d ", arr[i]);
    }

    return 0;
}
