#include<stdio.h> 
int findMax(int arr[], int n) { 
int max = arr[0]; 
for (int i = 1; i < n; i++) { 
if (arr[i] > max) 
max = arr[i]; 
} 
return max; 
} 
int main() {
	int arr[] = {10, 20, 30, 40, 50}; 
int n = sizeof(arr)/sizeof(arr[0]); 
int max_val = findMax(arr, n); 
printf("Maximum value in array is %d\n", max_val); 
return 0; 
}
