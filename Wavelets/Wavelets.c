#include <stdio.h>

void printArray(float arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%f ", arr[i]);
	}
	printf("\n");
}


void FWT(float* input, int length) {
	float sum, diff; //sum and difference of elements

	for (int l = length / 2; l >= 1; l /= 2) {
		printf("l = %d\n", l);
		printf("array: ");
		printArray(input, length);

		for (int i = 0; i < length; i++)
		{
			sum = input[i * 2] + input[i * 2 + 1];
			diff = input[i * 2] - input[i * 2 + 1];
			input[i] = sum;
			input[length + i] = diff;
		}
	}
}

int main()
{
	float arr[] = { 6, 12, 15, 15, 14, 12, 120, 116 };
	int n = 8;
	FWT(arr, n);
	printArray(arr, n);
	return 0;
}




