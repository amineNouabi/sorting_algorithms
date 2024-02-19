#ifndef SORT_H
#define SORT_H

/* Libraries */
#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Utility Functions prototypes */
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void swap_int(int *a, int *b);

/* Main Functions prototypes */
void bubble_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);

/* Utility Functions for Shell Sort */
size_t initial_knuth_gap(size_t size);

/* Utility Functions for Radix Sort */
int *create_counting_array_by_exp(int *array, size_t size, int exp);
void counting_sort_by_exp(int *array, size_t size, int exp);

/* Utility Functions for Cocktail Shaker Sort */
void swap_right(listint_t *cursor, listint_t **head);
void swap_left(listint_t *cursor, listint_t **head);

/* Utility Functions for Counting Sort */
int array_max(int *array, size_t size);
int *create_counting_array(int *array, size_t size);
int *create_sorted_array(int *array, size_t size, int *counting_array);

/* Utility Functions for Insertion Sort */
void swap(listint_t **list, listint_t *a, listint_t *b);
void insertion_sort_list(listint_t **list);

/* Utility Functions for selection Sort */
void selection_sort(int *array, size_t size);

/* Utility Functions for merge Sort */
void merge_sort(int *array, size_t size);
void top_down_merge(int *array, size_t left, size_t right);
void merge(int *array, size_t left, size_t right);

/* Utility Functions for quick Sort (Lomuto) */
void quick_sort(int *array, size_t size);
void sort_quick_Lomuto(int *arr, size_t left, size_t right, size_t size);

/* Utility Functions for heap Sort */
void heap_sort(int *array, size_t size);

/* Utility Functions for quick Sort (Hoare) */
void quick_sort_hoare(int *array, size_t size);
void hoare_sort(int *array, size_t left, size_t right, size_t size);

/* Utility Functions for bitonic Sort */
void bitonic_sort(int *array, size_t size);

#endif /* SORT_H */
