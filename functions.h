#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <SDL2/SDL.h>

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 600
#define NUM_BARS 10000
#define BAR_WIDTH (WINDOW_WIDTH / NUM_BARS)

#define VISUALIZE 0                     // Choose whether to visualize or not
#define NUM_SORTS 100                     // Number of sorting to be performed (for timing)
#define PAUSE 10
#define ALGORITHM "BucketSort"

static const SDL_Color GREEN = {0, 255, 0, 255};
static const SDL_Color BLUE = {0, 0, 255, 255};

// GUI
void DrawBar(SDL_Renderer *renderer, int x, int height, SDL_Color color);
void DrawBars(SDL_Renderer *renderer, int arr[], SDL_Color color, int highlight, int pause);

// Algorithms
void shuffleArray(int arr[], int n);
int Sort(SDL_Renderer *renderer);
int BubbleSort(int arr[], int n, SDL_Renderer *renderer);
int SelectionSort(int arr[], int n, SDL_Renderer *renderer);
int InsertionSort(int arr[], int n, SDL_Renderer *renderer);
int QuickSort(int arr[], int n, SDL_Renderer *renderer);
int MergeSort(int arr[], int n, SDL_Renderer *renderer);
int BucketSort(int arr[], int n, SDL_Renderer *renderer);
int ShellSort(int arr[], int n, SDL_Renderer *renderer);
int HeapSort(int arr[], int n, SDL_Renderer *renderer);

// Help functions
void Merge(int arr[], int left, int mid, int right, SDL_Renderer *renderer);
void Swap(int *a, int *b);
int Partition(int arr[], int low, int high, SDL_Renderer *renderer);
void Heapify(int arr[], int n, int i, SDL_Renderer *renderer);
void MergeSortRecursive(int arr[], int left, int right, SDL_Renderer *renderer);
void QuickSortRecursive(int arr[], int low, int high, SDL_Renderer *renderer);

#endif