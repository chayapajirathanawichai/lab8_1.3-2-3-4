#include <stdio.h>
int checkscore(char std[],char keys[]);
int peopleone(char std[][10],char keys[]);
int hard(char std[8][10],char keys[]);

int main() {
    char ans[8][10]={
        	{'A','B','A','C','C','D','E','E','A','D'},//7
			{'D','B','A','B','C','A','E','E','A','D'},//6
			{'E','D','D','A','C','B','E','E','A','D'},//5
			{'C','B','A','E','D','C','E','E','A','D'},//4
			{'A','B','D','C','C','D','E','E','A','D'},//8
			{'B','B','E','C','C','D','E','E','A','D'},//7
			{'B','B','A','C','C','D','E','E','A','D'},//7
			{'E','B','E','C','C','D','E','E','A','D'}};//7

	char keys[10]={'D','B','D','C','C','D','A','E','A','D'};
   	for(int i=0;i<8;i++){
   		printf("std %d => %d\n", (i+1), checkscore(ans[i],keys));
	   }
	printf("\n");
	printf("people = %d\n",peopleone(ans, keys));
	printf("\n");
	printf("hard is %d",hard(ans,keys));
}

int checkscore(char std[],char keys[]){
	int p=0;
	for(int i=0;i<10;i++){
		if(std[i]==keys[i]){
			p++;
		}
	}
	return p;
}
int peopleone(char std[][10],char keys[]){
	int people=0;
	for(int i=0;i<8;i++){
		if(std[i][0]==keys[0]){
		people++;
		}
	}
	return people;
}
int hard(char std[8][10],char keys[]){
	int score[10]={0},i,j;
	for(i=0;i<8;i++){
		for(j=0;j<10;j++){
			if(std[i][j]==keys[j]){
				score[j]++;
			}
		}
	}
	int min=score[0];
	int hard=1;
	for(i=0;i<10;i++){
		if(score[i]<min){
			min=score[i];
			hard=i+1;
		}
			
	}
	return hard;
}
