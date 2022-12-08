#include <iostream>
#include <algorithm>
using namespace std;

const unsigned int ARRSIZE = 10;

int main()
{
	bool fail = false;
	float arr[ARRSIZE];
	for (int i = 0; i < ARRSIZE; i++)
	{
		do
		{
			fail = false;
			cout << "Enter a value for " << i + 1 << " array item: ";
			cin >> arr[i];
			if (cin.fail())
			{
				cout << "\nIncorrect valye has been entered!" << endl << endl;
				fail = true;
			}
			cin.clear();
			cin.ignore();
		} while (fail);
	}
	cout << "\nAn array has been obtained: ";
	for (int i = 0; i < ARRSIZE; i++)
	{
		cout << arr[i] << " ";
	}

	float min_val = arr[0], max_val = arr[0];
	unsigned int min_idx = 0, max_idx = 0;

	for (int i = 0; i < ARRSIZE; i++)
	{
		if (min_val > arr[i])
		{
			min_val = arr[i];
			min_idx = i;
		}
		if (max_val < arr[i])
		{
			max_val = arr[i];
			max_idx = i;
		}
	}

	float product = 1, sum_negative = 0;
	for (int i = 0; i < ARRSIZE; i++)
	{
		if (min_idx < max_idx && i > min_idx && i < max_idx)
			product *= arr[i];
		if (min_idx > max_idx && i < min_idx && i > max_idx)
			product *= arr[i];
		if (arr[i] < 0)
			sum_negative += arr[i];
	}
	if (sum_negative == 0)
		cout << "\n\nThere are no negative items in the array...\n";
	else
	{
		cout.precision(3);
		cout << "\n\nThe sum of negative array elements is equal to " << sum_negative << endl;
	}
	if (min_idx == max_idx + 1 || max_idx == min_idx + 1)
		cout << "\nThere are no elements between the minimum and maximum array value...\n";
	else
	{
		cout.precision(3);
		cout << "The product of the items between the minimum and maximum array value is equal to " << product << endl;
	}

	sort(arr, arr + ARRSIZE);
	cout << "\nSorted array: ";
	for (int i = 0; i < ARRSIZE; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}