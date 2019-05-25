#include <stdio.h>
#include <stdlib.h>
// Brute force solution for finding indices of numbers that give us the target as a sum
int *two_sum(int *arr, int target,int size){
	
	int i,j;
	// Allocates memory for storing the indices of the two numbers that add up to the target
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

int max(int *arr, int size){
	int max = arr[0],i;
	for(i = 1; i < size; i++){
		if(max < arr[i])max = arr[i];
	}
	return max;
}
// Optimal solution for finding wo indices of numbers that add up to target
// This optimal solution uses the same approach from counting sort to find the numbers
// that add up to the target
int *sum(int *arr, int target, int size){
	const int max_val = max(arr,size)+1;
	int b[max_val],i,num1,num2,num1_index,num2_index;
	for(i = 0; i < max_val; i++)
		b[i] = 0;
	for(i = 0; i < max_val; i++){
		printf(" %d",b[i]);
	}
	printf("\n");
	for(i = 0; i < size;i++){
		b[arr[i]] += 1;
	}
	for(i = 0; i < max_val; i++){
		printf(" %d",b[i]);
	}
	for(i = 0; i < size; i++){
		int diff = target - arr[i];
		if(b[diff] > 0){
			num1_index = i;
			num2 = diff;
		}
	}
	for(i = 0; i < size; i++){
		if(num2 == arr[i])num2_index = i;
	}
	printf("\n");
	int *sol = (int*)malloc(sizeof(int*)*2);
	sol[0] = num2_index;
	sol[1] = num1_index;
	return sol;
}
void main(){
	int target = 9, arr[] = {2,7,11,15};
	int i,j;
	for(i = 0; i < 4; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	
	int *sol = two_sum(arr,target,4);
	printf("[%d,%d]\n",sol[0],sol[1]);
	printf("Max : %d\n",max(arr,4));
	int *s = sum(arr,target,4);
	printf("[%d,%d]\n",s[0],s[1]);
}
