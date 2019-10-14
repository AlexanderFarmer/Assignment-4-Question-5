#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>

using namespace std;

void ShellSort(vector <int> &num) {
	int i, temp, flag = 1, numLength = num.size();
	int gap = numLength;
	bool insertionNeeded = false;
	int swapPos = 0;
	int key;
	int exchange = 0;
	int compare = 0;
	while (true)  {    // boolean flag (true when not equal to 0) 
		gap = (gap - 1) / 2;
		if (gap == 0)
			break;

		for (int k = 0; k < gap; k++) {
			for (int j = gap + k; j < numLength; j += gap) {
				key = num[j];

				insertionNeeded = false;
				for (i = j - gap; i >= 0; i -= gap) {   // Smaller values move right
					compare += 1;
					if (key < num[i]) {
						swapPos = i;
						num[i + gap] = num[i];
						insertionNeeded = true;
						exchange += 1;
					}
					else
						break;
				}
				if (insertionNeeded) {
					num[swapPos] = key;  
					exchange += 1;
				}
			}
		}
	}
	cout << "Shell Sort" << "Exchanges" << exchange << "Comparisons" << compare << endl;
	return;
}


void selection_sort(vector<int>& vec){
	int compare = 0;
	int exchange = 0;

	for (int fill = 0; fill != vec.size(); ++fill) {
		int pos_min = fill;
		compare += 1;
		for (int next = fill + 1; next != vec.size(); ++next) {

			if (vec[next] < vec[pos_min])
				pos_min = next;

		}
		if (fill != pos_min)
			swap(vec[pos_min], vec[fill]);
		exchange += 1;

	}
	cout << "Selection Sort" << "Exchanges" << exchange << "Comparisons" << compare << endl;
}


void bubble_sort_improved(vector <int> &vec){
	int exchange = 0;
	int compare = 0;
	bool exchanges = false;
	for (int i = 1; i <= vec.size(); i++){
		exchanges = false;
		for (int j = 0; j < vec.size() - i; j++){
			compare += 1;
			if (vec[j + 1] < vec[j]){
				swap(vec[j], vec[j + 1]);// swap elements
				exchanges = true;
				exchange += 1;
			}
		}
		if (!exchanges)
			break;
	}
	cout << "Bubble Sort" << "Exchanges" << exchange << "Comparisons" << compare << endl;
}


void insertion_sort(std::vector <int> &num) {
	int i, j, key;
	bool insertionNeeded = false;
	int exchange = 0;
	int compare = 0;

	for (j = 1; j < num.size(); j++) {
		key = num[j];
		insertionNeeded = false;
		for (i = j - 1; i >= 0; i--){ // larger values move right

			compare += 1;
			if (key < num[i]) {
				num[i + 1] = num[i];
				insertionNeeded = true;
			}
			else
				break;
		}
		if (insertionNeeded)
			num[i + 1] = key; 
			exchange += 1;
	}
	cout << "Insertation Sort" << "Exchanges" << exchange << "Comparisons" << compare << endl;
}


void merge(std::vector<int>& array, std::vector<int>& result, int lowPointer, int highPointer, int upperBound) {

	int j = 0;
	int lowerBound = lowPointer;
	int mid = highPointer - 1;
	int n = upperBound - lowerBound + 1; //number of items

	while (lowPointer <= mid && highPointer <= upperBound){

		if (array[lowPointer] < array[highPointer])
			result[j++] = array[lowPointer++];
		else
			result[j++] = array[highPointer++];
	}

	while (lowPointer <= mid) 
		result[j++] = array[lowPointer++];


	while (highPointer <= upperBound) 
		result[j++] = array[highPointer++];
	

	for (j = 0; j < n; j++) //copy the items from the temporary array to the original array
		array[lowerBound + j] = result[j];
}

void mergesort(std::vector<int>& array, std::vector<int>& result, int lowerBand, int upperBand) {
	int midpoint;
	if (lowerBand < upperBand) {
		midpoint = (lowerBand + upperBand) / 2;
		mergesort(array, result, lowerBand, midpoint); //merge sort the left half
		mergesort(array, result, midpoint + 1, upperBand); //merge sort the right half
		merge(array, result, lowerBand, midpoint + 1, upperBand);
	}
}

void mergeSort(std::vector<int>& array){
	std::vector<int> result = array;
	mergesort(array, result, 0, array.size() - 1);
}



int partition(int first, int last, std::vector<int>& arr) {
	// Start up and down at either end of the sequence.
	// The first table element is the pivot value.
	int up = first+1;
	int down = last-1;
	do {

		while ((up != last) && !(arr[first] < arr[up])) {
			++up;
		}
		while (arr[first] < arr[down]) {
			--down;
		}
		if (up < down) {
			// if up is to the left of down,
			swap(arr[up], arr[down]);
		}
	} while (up < down); // Repeat while up is left of down.

	swap(arr[down], arr[first]);
	return down;
}

void sort_median(std::vector<int>& arr, int first, int last){

	bool exchanges = true;
	int middle = (first + last) / 2;
	if (arr[first]>arr[middle])
		swap(arr[first], arr[middle]);
	if (arr[middle] > arr[last])
		swap(arr[middle], arr[last]);
	if (arr[first] > arr[middle])
		swap(arr[first], arr[middle]);


	//swap the middle with the left 
	swap(arr[middle], arr[first]);
}

int partitionB(int first, int last, std::vector<int>& arr) {
	// Start up and down at either end of the sequence.
	// The first table element is the pivot value.


	int up = first+1;
	int down = last-1;
	sort_median(arr, first, last-1);
	int mid = first;
	do {
		while ((up != last - 1) && !(arr[mid] < arr[up])) {
			++up;
		}
		while (arr[mid] < arr[down]) {
			--down;
		}
		if (up < down) {
			// if up is to the left of down,
			swap(arr[up], arr[down]);
		}
	} while (up < down); // Repeat while up is left of down.

	swap(arr[mid], arr[down]);
	
	return down;
}

void middle_quick_sort(int first, int last, std::vector<int>& arr) {
	if (last - first > 1) {
		// There is data to be sorted.
		// Partition the table.
		int pivot = partitionB(first, last, arr);

		// Sort the left half.
		middle_quick_sort(first, pivot, arr);

		// Sort the right half.
		middle_quick_sort(pivot + 1, last, arr);
	}
}

void middle_quick_sort_wrapper(vector<int>& arr){
	middle_quick_sort(0, arr.size(), arr);
}

void quick_sort(int first, int last, std::vector<int>& arr) {
	
	if (last - first > 1) {
		// There is data to be sorted.
		// Partition the table.
		int pivot = partition(first, last, arr);

		// Sort the left subarray.
		quick_sort(first, pivot, arr);

		// Sort the right subarray.
		quick_sort(pivot + 1, last, arr);
	}
}

void quick_sort_wrapper(vector<int>& arr){
	quick_sort(0, arr.size(), arr);
}


vector<int> random_vector(size_t size){
	vector<int> v1;
	for (int i = 0; i < size; i++)
		v1.push_back(rand() % size); //put a random number between 0 and size
	return v1;
}

vector<int> sorted_vector(size_t size){
	vector<int> v1;
	for (int i = 0; i < size; i++)
		v1.push_back(i); 
	return v1;
}

vector<int> reversed_vector(size_t size){
	vector<int> v1;
	for (int i = size-1; i >= 0; i--)
		v1.push_back(i);
	return v1;
}

int main(){
	//Alphabetical Sort
	cout << "Sorts for Alphabetical Sort" << endl;
	cout << "-----------------------------" << endl;
	vector<int> v0 = sorted_vector(10000);
	bubble_sort_improved(v0);

	v0 = sorted_vector(10000);
	selection_sort(v0);

	v0 = sorted_vector(10000);
	insertion_sort(v0);

	v0 = sorted_vector(10000);
	ShellSort(v0);

	v0 = sorted_vector(10000);
	mergeSort(v0);

	v0 = sorted_vector(10000);
	middle_quick_sort_wrapper(v0);

	cout << endl;
	
	//Reversed
	cout << "Sorts for Reversed Sort" << endl;
	cout << "-----------------------------" << endl;
	vector<int> v5 = reversed_vector(10000);
	bubble_sort_improved(v5);

	v5 = reversed_vector(10000);
	selection_sort(v5);

	v5 = reversed_vector(10000);
	insertion_sort(v5);

	v5 = reversed_vector(10000);
	ShellSort(v5);

	v5 = reversed_vector(10000);
	mergeSort(v5);

	v5 = reversed_vector(10000);
	middle_quick_sort_wrapper(v5);

	cout << endl;

	//Random Sort
	cout << "Sorts for Random Sort" << endl;
	cout << "-----------------------------" << endl;
	vector<int> v1 = random_vector(10000);
	bubble_sort_improved(v1);

	v1 = random_vector(10000);
	selection_sort(v1);
	
	v1 = random_vector(10000);
	insertion_sort(v1);

	v1 = random_vector(10000);
	ShellSort(v1);

	v1 = random_vector(10000);
	mergeSort(v1);

	v1 = random_vector(10000);
	middle_quick_sort_wrapper(v1);


	return 0;
}