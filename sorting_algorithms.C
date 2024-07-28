#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"


// Shuffle array for bars to be in random order
void shuffleArray(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Swap(&arr[i], &arr[j]);
    }
}   

int Sort(SDL_Renderer *renderer) {
    // Initialize array with sequential values
    int arr[NUM_BARS];
    for (int i = 0; i < NUM_BARS; i++) {
        arr[i] = ((i + 1) * WINDOW_HEIGHT) / NUM_BARS; 
    }

    // Shuffle the array to randomize the order
    srand(time(NULL));
    shuffleArray(arr, NUM_BARS);

    // Draw initial bars
    DrawBars(renderer, arr, BLUE, -1, PAUSE);

    // Sort the array and visualize it
    int sorted = 0;
    if (strcmp(ALGORITHM, "BubbleSort") == 0) {
        sorted = BubbleSort(arr, NUM_BARS, renderer);
    }
    else if (strcmp(ALGORITHM, "SelectionSort") == 0) {
        sorted = SelectionSort(arr, NUM_BARS, renderer);
    }
    else if (strcmp(ALGORITHM, "InsertionSort") == 0) {
        sorted = InsertionSort(arr, NUM_BARS, renderer);
    }
    else if (strcmp(ALGORITHM, "QuickSort") == 0) {
        sorted = QuickSort(arr, NUM_BARS, renderer);
    }
    else if (strcmp(ALGORITHM, "MergeSort") == 0) {
        sorted = MergeSort(arr, NUM_BARS, renderer);
    }
    else if (strcmp(ALGORITHM, "BucketSort") == 0) {
        sorted = BucketSort(arr, NUM_BARS, renderer);
    }
    else if (strcmp(ALGORITHM, "ShellSort") == 0) {
        sorted = ShellSort(arr, NUM_BARS, renderer);
    }
    else if (strcmp(ALGORITHM, "HeapSort") == 0) {
        sorted = HeapSort(arr, NUM_BARS, renderer);
    }
    else {
        sorted = 0;
    }

    // Draw the final sorted bars
    if (sorted == 1) {
        DrawBars(renderer, arr, GREEN, -1, PAUSE);
        return 1;
    }
    else {
        return 0;
    }
}

int BubbleSort(int arr[], int n, SDL_Renderer *renderer) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                // Draw the bars and highlight the swapped bar
                DrawBars(renderer, arr, BLUE, j + 1, PAUSE);
            }
        }
    }
    return 1;
}

int SelectionSort(int arr[], int n, SDL_Renderer *renderer) {
    for (int i = 0; i < n - 1; i++) {
        // Assume the minimum is the first element
        int minIndex = i;

        // Find the index of the minimum element in the remaining unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first unsorted element
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;

            // Draw the bars and highlight the swapped bars
            DrawBars(renderer, arr, BLUE, minIndex, PAUSE);
            DrawBars(renderer, arr, BLUE, i, PAUSE);
        }
    }
    return 1;
}

int InsertionSort(int arr[], int n, SDL_Renderer *renderer) {
    int i, j, key;

    // Iterate over the array from the second element to the end
    for (i = 1; i < n; i++) {
        key = arr[i];

        // Move elements of the sorted portion that are greater than key to one position ahead
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            DrawBars(renderer, arr, BLUE, j, PAUSE);
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    return 1;
}

int QuickSort(int arr[], int n, SDL_Renderer *renderer) {
    QuickSortRecursive(arr, 0, n - 1, renderer);
    return 1;
}

int MergeSort(int arr[], int n, SDL_Renderer *renderer) {
    MergeSortRecursive(arr, 0, n - 1, renderer);
    return 1;
}

int BucketSort(int arr[], int n, SDL_Renderer *renderer) {
    int max_value = WINDOW_HEIGHT;
    int num_buckets = NUM_BARS;
    int buckets[num_buckets][n];
    int bucket_sizes[num_buckets];

    // Initialize all bucket sizes to 0
    for (int i = 0; i < num_buckets; i++) {
        bucket_sizes[i] = 0;
    }

    // Distribute array elements into buckets
    for (int i = 0; i < n; i++) {
        int bucket_index = (arr[i] * num_buckets) / (max_value + 1);
        buckets[bucket_index][bucket_sizes[bucket_index]++] = arr[i];
        DrawBars(renderer, arr, BLUE, i, PAUSE);
    }

    // Sort each bucket and merge back into the original array
    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        InsertionSort(buckets[i], bucket_sizes[i], renderer);
        for (int j = 0; j < bucket_sizes[i]; j++) {
            arr[index++] = buckets[i][j];
            DrawBars(renderer, arr, BLUE, i, PAUSE);
        }
    }

    return 1;
}

int ShellSort(int arr[], int n, SDL_Renderer *renderer) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Perform a gapped insertion sort
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
                
                // Visualize the swap
                DrawBars(renderer, arr, BLUE, j, PAUSE);
            }
            arr[j] = temp;

            // Visualize the insertion
            DrawBars(renderer, arr, BLUE, j, PAUSE);
        }
    }

    return 1;
}

int HeapSort(int arr[], int n, SDL_Renderer *renderer) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(arr, n, i, renderer);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Visualize the swap
        DrawBars(renderer, arr, BLUE, i, PAUSE);

        // Call max heapify on the reduced heap
        Heapify(arr, i, 0, renderer);
    }

    return 1;
}