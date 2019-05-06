
#include "isort.h"
#include <iostream>
#include <string>
int main() {

	std::vector<double> v({ 7.1,2.5,4.242,1.02,5.92,3.13 });
	insertion_sort_ind(v);
	for (auto i : v) {
		std::cout << i << " ";
	}
	printf("\n\n");
	std::vector<double> v2({ 8, 5, 3, 4 });
	insertion_sort(v2.begin(), v2.end());
	for (auto i : v2) {
		std::cout << i << " ";
	}
	printf("\n");
	std::vector<int> v3 = { 2, 1, 5, 3, 7, 5, 4, 6 };
	insertion_sort1(v3.begin(), v3.end(), v3);
	for (auto i : v3) {
		std::cout << i << " ";
	}

	int  x = binarySearchRecursion(v3, 0, (int)v.size(), 6);

	std::cout << "3 is in position - > " << x;


	return 0;
}