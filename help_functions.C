#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

void Merge(int arr[], int left, int mid, int right, SDL_Renderer *renderer) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
        DrawBars(renderer, arr, BLUE, k, PAUSE);
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k++] = L[i++];
        DrawBars(renderer, arr, BLUE, k, PAUSE);
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k++] = R[j++];
        DrawBars(renderer, arr, BLUE, k, PAUSE);
    }

    // Free temporary arrays
    free(L);
    free(R);
}

void Swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// Partition function to place pivot element at its correct position
int Partition(int arr[], int low, int high, SDL_Renderer *renderer) {
    DrawBars(renderer, arr, BLUE, low, PAUSE);
    DrawBars(renderer, arr, BLUE, high, PAUSE);

    int pivot = arr[high]; // Choose the last element as the pivot
    int i = (low - 1); // Index of the smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++;
            Swap(&arr[i], &arr[j]);
        }
    }
    Swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void Heapify(int arr[], int n, int i, SDL_Renderer *renderer) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        int swap = arr[i];
        arr[i] = arr[largest];
        arr[largest] = swap;

        // Visualize the swap
        DrawBars(renderer, arr, BLUE, i, PAUSE);

        // Recursively heapify the affected sub-tree
        Heapify(arr, n, largest, renderer);
    }
}


void MergeSortRecursive(int arr[], int left, int right, SDL_Renderer *renderer) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort the first and second halves
        MergeSortRecursive(arr, left, mid, renderer);
        MergeSortRecursive(arr, mid + 1, right, renderer);

        // Merge the sorted halves
        Merge(arr, left, mid, right, renderer);
    }
}

void QuickSortRecursive(int arr[], int low, int high, SDL_Renderer *renderer) {
    if (low < high) {
        // Partition the array and get the pivot element index
        int pi = Partition(arr, low, high, renderer);

        // Recursively sort the elements before and after partition
        QuickSortRecursive(arr, low, pi - 1, renderer);
        QuickSortRecursive(arr, pi + 1, high, renderer);
    }
}