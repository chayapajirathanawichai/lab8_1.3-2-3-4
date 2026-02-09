#include<stdio.h>
#include <stdbool.h>
void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[], int n);
void printArray(int arr[], int size);

int main(){
	int score[4];
	for(int i=0;i<4;i++){
		scanf("%d",&score[i]);
	}
	bubbleSort(score, 4);
	printArray(score, 4);
}
void bubbleSort(int arr[], int n) //min to max
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}
void printArray(int arr[], int size) //no.0 is min so cal.espicially no1-last
{
	int ans=0;
    for (int i = 1; i < size; i++)
    	ans+=arr[i];
        printf("%d", ans);
}
