//#include <iostream>
//using namespace std;
//
//int max(int arr[], int size) {
//
//	if (size == 1) {
//		return arr[0];
//	}
//
//	int max1 = max(arr, size - 1);
//	if (arr[size - 1] > max1) {
//		return arr[size - 1];
//	}
//	else {
//		return max1;
//	}
//}
//
//int main() {
//
//	const int size = 5;
//	int arr[size];
//
//	cout << "Enter the element of array: ";
//	for (int i = 0; i < size - 1; i++) {
//		cin >> arr[i];
//	}
//
//	int result = max(arr, size);
//	cout << "The greater element of array: "<<  result << endl;
//	return 0;
//}