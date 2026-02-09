#include <stdio.h>
void addthree(int number[], int pos[3][2], int size); 

int main() {
	int number[5] = {20,50,100,99,9};
	int pos[3][2]={{1,2},{3,4},{5,6}};
	addthree(number,pos,sizeof(number)/sizeof(number[0]));
}
void addthree(int number[], int pos[3][2], int size){
	for(int i=0;i<3;i++){
		int index=pos[i][0];
		int add=pos[i][1];
		if(index<size){
			number[index]+=add;
		}
	}
	for(int i=0;i<size;i++){
		printf("%d ",number[i]);
	}
}
