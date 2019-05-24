#include <stdio.h>
#include <stdlib.h>
int *two_sum(int *arr, int target,int size){
	
	int i,j;
	int *sol = (int*)malloc(sizeof(int)*2);
	for(i = 0; i < size - 1; i++){
		for(j = i + 1; j < size; j++){
			int sum = arr[i] + arr[j];
		
			if( sum == target){
				sol[0] = i;
				sol[1] = j;
				return sol;
			}
	
		}
	}
	return NULL;
}
void main(){
	int target = 26, arr[] = {2,7,11,15};
	int i,j;
	for(i = 0; i < 4; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	
	int *sol = two_sum(arr,target,4);
	printf("[%d,%d]\n",sol[0],sol[1]);
}
