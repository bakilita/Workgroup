//F91901
//HW 4 - Merge Sort
/*Предайте работещ код на сортиране чрез сливане, като приложите изход от програмата, на който се проследяват сливаните масиви, на изплуване, с коментар: "сливам масив ...."     "и масив....."*/

#include <iostream>
#include <vector>

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

void merge(int arr[], int from, int mid, int to)
{
	int i, j, k;
	int n1=mid - from + 1;
	int n2=to - mid;

	vector <int> arrL(n1);  //temp arr creation
	vector <int> arrR(n2);

	for (i=0; i < n1; i++)
	{
		arrL[i]=arr[from + i];
	}
	for (j=0; j < n2; j++)
	{
		arrR[j]=arr[mid + j + 1];
	}

	//Merging the arays into arr
	i=0;
	j=0;
	k=from;
	while (i < n1 && j < n2)
	{
		if (arrL[i] <= arrR[j])
		{
			arr[k]=arrL[i];
			i++;
		}
		else
		{
			arr[k]=arrR[j];
			j++;
		}
		k++;
	}
	//Copy remaining elements if any
	while (i < n1)
	{
		arr[k]=arrL[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k]=arrR[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int from, int to)
{
	if (sizeof(arr)<=1)
	{
	cout << "The array is empty or contains just 1 value." << endl;
		return;
	}
	if (from == to)
	{
		cout << "Bottom" << endl;
		return;
	}
	else if (from < to)
	{
		int mid=(from+to)/2;
		cout << "Sinking left " << endl;
		mergeSort(arr, from, mid);
		cout << "Emerging l" << endl;

		cout << "Sinking right " << endl;
		mergeSort(arr, mid+1, from);
		cout << "Emerging r" << endl;

		merge(arr, from, mid, to);
	}
}

int main()
{
	int inputArr[]={ 9,1,9,0,1,9,9,0,4 };
	int Arr[7];
	arrMerge(inputArr, Arr);
	cout << "Array created:";
	arrPrint(Arr, 7);

	mergeSort(Arr, 0, 7-1);
	cout << "End array: ";
	arrPrint(Arr, 7);
	system("pause");
}