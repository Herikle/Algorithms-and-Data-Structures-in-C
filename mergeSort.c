#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

void merge(int array[],int b,int middle,int e)
{
	int *aux; 
	int s1 = b, s2 = middle+1; 
	int size = e-b+1; 
	int i, j, k;
	int e1 = 0, e2 = 0;
	aux = (int *) malloc(size*sizeof(int));
	if(aux !=NULL)
	{
		for(i = 0; i<size;i++)
		{
			if(!e1 && !e2){
				if(array[s1] < array[s2])
				{
					aux[i] = array[s1++];
				}
				else
				{
					aux[i] = array[s2++];
				}
				if(s1>middle) e1 = 1;
				if(s2>e) e2 = 1;
			}
			else
			{
				if(!e1)
					aux[i] = array[s1++];
				else
					aux[i] = array[s2++];
			}
		}
		for(j = 0, k=b;j<size;j++,k++)
			array[k] = aux[j];
	}	
	free(aux);	
}

void mergeSort(int array[],int b, int e)
{
	int middle;
	if(b < e)
	{
		middle = (b+e)/2;
		mergeSort(array,b,middle);
		mergeSort(array,middle+1,e);
		merge(array,b,middle,e);
	}
}

int main(int argc, char * argv[])
{
	FILE * ptr;

	ptr = fopen("NoOrder.txt","w");

	int x,value,vector[MAX];
	for(x = 1;x<=MAX;x++)				
	{	
		clock_t current = clock();
		double eoq = (double)(current)/CLOCKS_PER_SEC;
		int seed = (int) (eoq*1000000);
		srand(seed);
		fprintf(ptr,"%d\n", rand()%MAX);
	}
	fclose(ptr);
	ptr = fopen("NoOrder.txt","r");
	x = 0;
	while(!feof(ptr))
	{
		fscanf(ptr,"%d",&value);	
		vector[x] = value;
		x++;
	}
	clock_t begin = clock();//initial mergeSort
	mergeSort(vector,0,MAX-1);
	clock_t end = clock();//final mergeSort
	ptr = fopen("MergeSortInOrder.txt","w");
	for(x = 0;x<MAX;x++)
	{
		fprintf(ptr,"%d\n",vector[x]);
	}
	fprintf(ptr,"\nMergeSort Execution Time = %f\n",(double)(end - begin)/CLOCKS_PER_SEC); 
	fclose(ptr);
}