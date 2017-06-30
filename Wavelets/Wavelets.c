#include <stdio.h>

#define ARRAYMAX 1024
#define SQRT2 1.4142135623730950488016887242097

void printArray(float arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%f ", arr[i]);
	}
	printf("\n");
}

void FWT(float* input, int length) {
	float sum, diff; //sum and difference of elements

	for (int l = length / 2; l >= 1; l /= 2) {
		

		for (int i = 0; i < l; i++)
		{
			sum = input[i * 2] + input[i * 2 + 1];
			diff = input[i * 2] - input[i * 2 + 1];
			input[i] = sum / SQRT2;
			input[l + i] = diff / SQRT2;
		}
		printf("l = %d\n", l);
		printf("array: ");
		printArray(input, length);
	}
}

void FWT_A(float* input, float* output, int length) {
	float sum, diff; //sum and difference of elements
	for (int l = length / 2; l >= 1; l /= 2) {
		for (int i = 0; i < l; i++)
		{
			sum = input[i * 2] + input[i * 2 + 1];
			diff = input[i * 2] - input[i * 2 + 1];
			input[i] = sum;
			input[l + i] = diff;
		}

		printf("l = %d\n", l);
		printf("array: ");
		printArray(input, length);
	}
}

int main()
{
	float arr[] = { 6, 12, 15, 15, 14, 12, 120, 116 };
	int n = 8;
	printArray(arr, n);
	FWT(arr, n);
	return 0;
}




