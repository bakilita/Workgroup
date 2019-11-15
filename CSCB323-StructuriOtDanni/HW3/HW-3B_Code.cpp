//F91901 Georgi Ivanov 
//HW-3B
#include  <iostream>

using namespace std;

void arrPrint(int arr[], int arrLength)
{
	for (int i=0; i<arrLength; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
}

void arrMerge(int inputArr[], int resultArr[])
{
	resultArr[0]=inputArr[0]*10 + inputArr[1];
	resultArr[1]=inputArr[2];
	resultArr[2]=inputArr[3];
	resultArr[3]=inputArr[4]*10+inputArr[5];
	resultArr[4]=inputArr[6];
	resultArr[5]=inputArr[7];
	resultArr[6]=inputArr[8];
}

void swap(int* a, int* b)
{
	int t=*a;
	*a=*b;
	*b=t;
}

int partition(int arr[], int low, int high)
{
	int pivot=arr[low + (high - low) / 2];
	cout << "Pivot " << pivot << endl;
	int	i=low - 1;
	int	j=high + 1;
	bool didSwap=0; //optional
		while (true)
		{
			do
			{
				i++;
			} while (arr[i] < pivot);
			do
			{
				j--;
			} while (arr[j] > pivot);
			if (i >= j)
			{
				if (didSwap)
				{
					cout << endl;
				}
				cout << "End of swapping" << endl;
				return j;
			}
			cout << "Swapping " << arr[i] << " and " << arr[j] << " ";
			swap(&arr[i], &arr[j]);
			didSwap=1;
		}
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		cout << "Copy, borders from index " << low << " to " << high << endl;
		int	pIndex=partition(arr, low, high);
		cout << "Sinking left" << endl;
		quickSort(arr, low, pIndex);
		cout << "Emerging" << endl;
		cout << "Sinking Right" << endl;
		quickSort(arr, pIndex + 1, high);
		cout << "Emerging" << endl;
	}
	else
	{
		cout << "--Bottom--" << endl;
	}

}


int main()
{
	int inputArr[]={9,1,9,0,1,9,9,0,4};
	int Arr[7];
	arrMerge(inputArr,Arr);
	cout << "Array created:";
	arrPrint(Arr, 7);

	quickSort(Arr, 0, 7-1);

	cout << "Array end state:";
	arrPrint(Arr, 7);
	system("pause");
}