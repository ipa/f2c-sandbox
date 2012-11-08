#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern void func_3d_(float* arr, int* dim_i, int* dim_j, int* dim_k)
{
	printf("3 D Code length:%i dim_i:%i dim_j:%i dim_k:%i \n", 
		(*dim_k * *dim_i * *dim_j), *dim_i, *dim_j, *dim_k);
	int i, j, k;

	for(i = 0; i < *dim_i; i++)
	{
		for(j = 0; j < *dim_j; j++)
		{
			for(k = 0; k < *dim_k; k++)
			{
				int idx = (k * *dim_i * *dim_j) + (j * *dim_i) + i;
				printf("%.0f idx(%i,%i,%i:%i)\t", arr[idx], i, j, k,idx);
			}
			printf("\n");
		}
		printf("\n");
	}
	/*int size = *dim_i * *dim_j * *dim_k;
	for(i = 0; i < size; i++)
	{
		printf("arr[%i] = %.0f\n", i, arr[i]);
	}*/
	printf("\n3 D Code END\n\n");
}

extern void func_4d_(float* arr, int* dim_i, int* dim_j, int* dim_k, int* dim_l)
{
	printf("4 D Code length:%i dim_i:%i dim_j:%i dim_k:%i dim_l:%i\n", 
		(*dim_i * *dim_j * *dim_k * *dim_l), *dim_i, *dim_j, *dim_k, *dim_l);
	int i, j, k, l;

	for(i = 0; i < *dim_i; i++)
	{
		for(j = 0; j < *dim_j; j++)
		{
			for(k = 0; k < *dim_k; k++)
			{
				for(l = 0; l < *dim_l; l++)
				{
					int idx = (l * *dim_k * *dim_j * *dim_i) +
						(k * *dim_j * *dim_i)+(j * *dim_i)+i;
					printf("%f idx(%i,%i,%i,%i) \t", arr[idx], i, j, k, l);
				}
				printf("\n");
			}
			printf("\n");
		}
		printf("\n");
	}
	/*int N = *dim_i * *dim_j * *dim_k * *dim_l;
	int x;
	for(x = 0; x < N; x++)
	{
		printf("id[%i] = %f\n", x, arr[x]);
	}*/
	printf("\n4 D Code END\n\n");
}

extern void func_2d_(float* arr, int* len)
{
	printf("2 D Code length:%i \n", *len);
	int i, j;
	int dim_i = sqrt(*len);
	int dim_j = sqrt(*len);

	for(i = 0; i < dim_i; i++)
	{
		for(j = 0; j < dim_j; j++)
		{
			int idx = (j*dim_i)+i;
			printf("%f idx(%i,%i) \t", arr[idx], i, j);
		}
		printf("\n");
	}
	printf("\n2 D Code END\n\n");
}


extern void func_2d_sub_(float* arr, int* len)
{
	printf("2 D Code length:%i \n", *len);
	int i, j;
	int dim_i = sqrt(*len);
	int dim_j = sqrt(*len);

	for(i = 0; i < dim_i; i++)
	{
		for(j = 0; j < dim_j; j++)
		{
			int idx = (j*dim_i) + i;
			printf("%f idx(%i,%i) \t", arr[idx], i, j);
		}
		printf("\n");
	}
	printf("\n2 D Code END\n\n");
}

extern void func_(float* arr, int* len)
{
	printf("1 D Code \n");
	int i;
	for(i = 0; i < *len; i++)
	{
		printf("%f\t", arr[i]);
	}
	printf("\n1 D Code END\n\n");
}
