#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
int random1to100();
void bubbleSort(int numAr[],int numArSize);
void printAr(int numAr[],int numArSize);
int checkNum(int numAr[],int numArSize);
int searchNum(int numAr[],int numArSize,int target);

void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int main() {
    int N,i,t,ans;
    int A[100];
    scanf("%d %d",&N,&t);
    if (N>100) 
	 N=100;
    srand(time(NULL));
    for (i=0;i<N;i++)
    {
       	A[i]=checkNum(A,i);
	}
     
    printf("\n********\n");
    printAr(A,N);
    
    bubbleSort(A, N);
    ans=searchNum(A,N,t);
    printf("\n");
    if(ans == -1) 
		printf("Element is not present in array");
    else 
		printf("Element is present at index %d",ans);
    
    return 0;
}

void printAr(int numAr[],int numArSize) {
    int i;
    for (i=0;i<numArSize;i++)
        printf("%d ",numAr[i]);
} 

int checkNum(int numAr[],int numArSize) {
    int rnum,numok=1;
    while (numok==1) //same
	{
        rnum=random1to100();
        numok=0;
        for(int i=0;i<numArSize-1;i++){
        	if(numAr[numArSize]==rnum){
        		numok=1;break;
			}
		}
    }
    return rnum;
}

void bubbleSort(int numAr[],int numArSize){
    int i, j;
    bool swapped;
    for (i = 0; i < numArSize - 1; i++) {
        swapped = false;
        for (j = 0; j < numArSize - i - 1; j++) {
            if (numAr[j] > numAr[j + 1]) {
                swap(&numAr[j], &numAr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

int searchNum(int numAr[],int numArSize, int target) {
        //sol2 use binary search
        int i,found=0,high=numArSize-1;
        while (found <= high) {
        	int mid = found + (high - found) / 2;
        	if (numAr[mid] == target)
            	return mid;
        	if (numAr[mid] < target)
            	found = mid + 1;
        	else
            	high = mid - 1;
    	}
		return -1;
}
  
int random1to100() {
    int random_num = (rand() % 100) + 1;
    printf("%d ", random_num);
    return random_num;
}
