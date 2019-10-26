#include "sort.h"
/**
 * quick_sort - function that sorts an array
 * of integers in ascending order using the
 * quick sort algorithm
 *
 * @array: input arrray
 * @size: size of the array
 * Return: no return
 */
void quick_sort(int *array, size_t size)
{
	_qsort(array, 0, size - 1, size);
}
/**
 * _qsort - auxiliar function for the
 * quick_sort function
 * @a: input arrray
 * @low: index for the first element
 * @high: index for the last element
 * @size: size of the array
 * Return: no return
 */
void _qsort(int *a, size_t low, size_t high, size_t size)
{
	size_t p, w, i;
	int tmp;

	p = high;
	w = low;
	for (i = low; i < high; i++)
	{
		if (a[i] < a[p])
		{
			if (i != w)
			{
				tmp = a[i];
				a[i] = a[w];
				a[w] = tmp;
				print_array(a, size);
			}
			w++;
		}
	}
	if (w != p && a[w] != a[p])
	{
		tmp = a[w];
		a[w] = a[p];
		a[p] = tmp;
		print_array(a, size);
	}
	if (w != high)
		_qsort(a, w + 1, high, size);
	if (low != w)
		_qsort(a, low, w - 1, size);
}
