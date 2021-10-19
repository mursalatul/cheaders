#ifndef ARRAY_H
#define ARRAY_H

// headers
#include "number.h"

// macros will be imported from number.h header file

// merge main_sort
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(ll arr[], ll l, ll m, ll r)
{
	ll i, j, k;
	ll n1 = m - l + 1;
	ll n2 = r - m;

	/* create temp arrays */
	ll L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void main_sort(ll arr[], ll l, ll r)
{
	// ll l = 0, r = array_size - 1;
	if (l < r) {
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		ll m = l + (r - l) / 2;

		// main_sort first and second halves
		main_sort(arr, l, m);
		main_sort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

// this funtion will be called from the program. this function will call main_sort(). we are using this bridge function to call another function main_sort() function needs l and r . but we will not take this l and r from user. we will just take size instead of l and r. this will help the user to use the function more easily

void sort(ll arr[], ll array_size)
{
	main_sort(arr, 0, array_size - 1);
}

// sort function end

// return max and min element of an array as an array of 2 elements. 1st element will be maximum value and 2nd element will be minimum value. use a pointer to receieve the returned array from this function.
ll* max_min_element(ll arr[], ll array_size)
{
    ll max_ele, min_ele; // store max and min element
    static ll max_min_arr[2]; // after store max min in an array to reture both
    max_ele = min_ele = arr[0]; 

    for (ll i = 0; i < array_size; i++)
    {
        if (arr[i] > max_ele)
        {
            max_ele = arr[i];
        }
        if (arr[i] < min_ele)
        {
            min_ele = arr[i];
        }
    }

    max_min_arr[0] = max_ele;
    max_min_arr[1] = min_ele;

    return max_min_arr; // returning the array. basically it will return the address of the max_min_arr array. so we will use a pointer to get this output when we will use this function.
}

#endif