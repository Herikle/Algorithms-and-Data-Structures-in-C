#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
void insertionSort(int array[],int size)
{
	int i,j;
	for(i = 1;i<size;i++)
	{
		j = i;
		while(array[j]<array[j-1] && j > 0)
		{
			int aux = array[j];
			array[j] = array[j-1];
			array[j-1] = aux;
			j--;
		}

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
	clock_t begin = clock();//initial insertion
	insertionSort(vector,MAX);
	clock_t end = clock();//final insertion
	ptr = fopen("InsertInOrder.txt","w");
	for(x = 0;x<MAX;x++)
	{
		fprintf(ptr,"%d\n",vector[x]);
	}
	fprintf(ptr,"\nInsertionSort Execution Time = %f\n",(double)(end - begin)/CLOCKS_PER_SEC); 
	fclose(ptr);
}