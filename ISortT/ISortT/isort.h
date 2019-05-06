#pragma once

#ifndef _ISORT_H_
#define _ISORT_H_
#include <vector>
#include <iostream>
#include <algorithm> 
#include <iterator> 
// Verzija s indeksima
template <typename Record>
void insertion_sort_ind(std::vector<Record> & vec)
{
	unsigned hole;
	for (unsigned i = 1; i < vec.size(); ++i) {
		Record value = vec[i];
		hole = i;
		while (hole > 0 && vec[hole - 1] > value) {
			vec[hole] = vec[hole - 1];
			--hole;
		}
		vec[hole] = value;
	}
	return;
}


template <typename Iter>
void insertion_sort(Iter first, Iter last) {
	Iter it = first;

	for (it; it != last; ++it) {
		std::cout << *it << " ";
	}
	printf("\n");

	for (Iter i = first + 1; i != last; ++i) {
		printf("\nSljedeca iteracija\n");
		for (Iter j = i; j != first; --j) {
			if (*j < *(std::prev(j, 1))) {

				auto tmp = *j;
				*j = *(std::prev(j, 1));
				*(std::prev(j, 1)) = tmp;
			}
			else {
				break;
			}
		}
		it = first;
		for (it; it != last; ++it) {
			std::cout << *it << " ";
		}
		printf("\n");
	}

	return;


}

// verzija sa algoritmima std::rotate i std::upper_bound
template <typename Iter>
void insertion_sort1(Iter first, Iter last, std::vector<int> &v) {
	std::cout << "pocnetna; \n";
	for (auto x : v) {
		std::cout << x << " ";
	}
	printf("\n\n");
	// Vaša implementacija
	Iter it = first;
	for (it; it != last; ++it) {
		Iter const insertion_point = std::upper_bound(first, it, *it);
		//std::cout << "insettion point = " << *insertion_point << "\n";
		std::rotate(insertion_point, it, it + 1);
		for (auto x : v) {
			std::cout << x << " ";
		}
		printf("\n");
	}

	return;
}

template <typename Type>
Type binarySearch(std::vector<Type> const &v, const Type x) {
	Type start = 0, end = v.size(), mid;

	while (start <= end) {
		mid = (start + end) / 2;
		if (v.at(mid) == x) {
			return mid;
		}
		else if (v.at(mid) < x) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return -1;
}
//2, 1, 5, 3, 7, 5, 4, 6
template <typename Type>
Type binarySearchRecursion(std::vector<Type> const &v, Type low, Type high, const Type x) {

	if (low > high) {
		return -1;
	}
	Type mid = low + (low + high) / 2;

	if (x == (v[mid])) {
		return x;
	}
	else if (x < v.at(mid)) {
		return binarySearchRecursion(v, low, mid - 1, x);
	}
	else {
		return binarySearchRecursion(v, mid + 1, high, x);
	}
}


#endif