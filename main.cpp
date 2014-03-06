#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int  run(const int *a,int n) {
	int * arr = new int[n]();
	memcpy(arr , a , n *sizeof(int));
	int arr_size = n;
	int swap_times = 0;

	//bubble
	for(int i = 0 ; i < arr_size ; ++ i)
		for(int j = 0 ; j < arr_size - i - 1 ; ++ j)
			if(arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}

	//count different and get the swap_times
	for(int i = 0 ; i < arr_size ; ++ i)   
		if(arr[i] != a[i])
			++ swap_times;
	swap_times = swap_times % 2 == 0 ? swap_times : swap_times + 1;
	swap_times >>= 1;

	// some print operations
	printf("swap_times:%d \n regin array :" , swap_times);
	for(int i = 0 ; i < n ; ++ i )   
		printf("%d " , a[i]);
	printf("\nsorted array :");
	for(int i = 0 ; i < n ; ++ i )   
		printf("%d " , arr[i]);
	printf("\n");

	delete [] arr;
	return swap_times;
}



int main()
{   

	const int arr[] = {
	93,52,12,70,25,36,18,37,27,99,68,40,84,
	3,76,57,60,19,33,41,92,87,58,13,15,43,
	28,63,64,59,31,97,14,69,4,88,72,65,10,
	23,67,81,21,80,90,82,74,1,95,42,89,29,
	53,44,17,61,50,8,85,73,30,62,7,46,54,
	77,9,34,38,16,26,56,71,32,83,48,49,11,
	91,35,24,75,78,20,86,45,94,55,98,2,39,
	96,5,22,100,6,79,66,51,47
	};

	run(arr, sizeof(arr) / sizeof(int));

	system("PAUSE");
} 
