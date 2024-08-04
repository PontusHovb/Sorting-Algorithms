# Sorting Algorithms
In this project, 8 of the most common sorting algorithms are implemented in C. 
<p align="center">
    <img src="https://github.com/PontusHovb/Sorting-Algorithms/blob/main/Visualizations/TimeComplexity.png" width="400"/>
</p>
<p align="center"><i>Time Complexity</i></p>

Three of the algorithms (Selection Sort, Bubble Sort and Insertion Sort) are all of time complexity $`\mathcal{O}(n^2)`$ on average as seen by above plot. The rest are $`\mathcal{O}(n \log n)`$ on average with different best and worse cases for respective algorithm. 
 
## Selection Sort
<p align="center">
    <img src="https://github.com/PontusHovb/Sorting-Algorithms/blob/main/Visualizations/SelectionSort.gif" width="400"/>
</p>
<p align="center"><i>Selection Sort</i></p>

Selection sort is a simple comparison-based sorting algorithm that divides the input list into two parts: a sorted sublist and an unsorted sublist. It **repeatedly selects the smallest element** from the unsorted sublist and swaps it with the leftmost unsorted element, moving the boundary of the sorted sublist one element to the right. This process continues until the entire list is sorted. 

**Time complexity**
- Best: $`\mathcal{O}(n^2)`$
- Average: $`\mathcal{O}(n^2)`$
- Worst: $`\mathcal{O}(n^2)`$

## Bubble Sort
<p align="center">
    <img src="https://github.com/PontusHovb/Sorting-Algorithms/blob/main/Visualizations/BubbleSort.gif" width="400"/>
</p>
<p align="center"><i>Bubble Sort</i></p>

Bubble sort is a straightforward comparison-based sorting algorithm that repeatedly steps through the list, compares adjacent elements, and **swaps them if they are in the wrong order**. This process is repeated for each element in the list until no more swaps are needed, indicating that the list is sorted.

**Time complexity**
- Best: $`\mathcal{O}(n)`$
- Average: $`\mathcal{O}(n^2)`$
- Worst: $`\mathcal{O}(n^2)`$

## Insertion Sort
<p align="center">
    <img src="https://github.com/PontusHovb/Sorting-Algorithms/blob/main/Visualizations/InsertionSort.gif" width="400"/>
</p>
<p align="center"><i>Insertion Sort</i></p>

Insertion sort is a simple comparison-based sorting algorithm that builds the final sorted array one element at a time. It works by taking elements from the unsorted portion and **inserting them into their correct position in the sorted portion**, effectively shifting larger elements one position to the right to make space. This process is repeated until all elements are sorted. Insertion sort is efficient for small datasets.

**Time complexity**
- Best: $`\mathcal{O}(n)`$
- Average: $`\mathcal{O}(n^2)`$
- Worst: $`\mathcal{O}(n^2)`$

## Quick Sort
<p align="center">
    <img src="https://github.com/PontusHovb/Sorting-Algorithms/blob/main/Visualizations/QuickSort.gif" width="400"/>
</p>
<p align="center"><i>Quick Sort</i></p>

Quick sort is an efficient, comparison-based sorting algorithm that uses a divide-and-conquer approach to sort elements. It works by selecting a **'pivot' element from the array and partitioning the other elements into two sub-arrays**, according to whether they are less than or greater than the pivot. The sub-arrays are then recursively sorted. This process continues until the entire array is sorted. Quick sort is highly efficient for large datasets.

**Time complexity**
- Best: $`\mathcal{O}(n \log n)`$
- Average: $`\mathcal{O}(n \log n)`$
- Worst: $`\mathcal{O}(n^2)`$

## Merge Sort
<p align="center">
    <img src="https://github.com/PontusHovb/Sorting-Algorithms/blob/main/Visualizations/MergeSort.gif" width="400"/>
</p>
<p align="center"><i>Merge Sort</i></p>

Merge sort is a stable, comparison-based sorting algorithm that follows the divide-and-conquer paradigm. It works by **recursively splitting the array into two halves** until each sub-array contains a single element, then merging these sub-arrays back together in sorted order. The merging process ensures that the combined array is sorted. Merge sort is particularly efficient for large datasets.

**Time complexity**
- Best: $`\mathcal{O}(n \log n)`$
- Average: $`\mathcal{O}(n \log n)`$
- Worst: $`\mathcal{O}(n \log n)`$

## Bucket Sort
<p align="center">
    <img src="https://github.com/PontusHovb/Sorting-Algorithms/blob/main/Visualizations/BucketSort.gif" width="400"/>
</p>
<p align="center"><i>Bucket Sort</i></p>

Bucket sort is a distribution-based sorting algorithm that distributes elements into a number of 'buckets'. **Each bucket is then sorted individually**, in this case through insertion sort. After sorting the buckets, the elements are concatenated to form the final sorted array. This algorithm is particularly efficient when the input is uniformly distributed over a range.

**Time complexity**
- Best: $`\mathcal{O}(n + k)`$
- Average: 
- Worst: $`\mathcal{O}(n^2)`$

## Shell Sort
<p align="center">
    <img src="https://github.com/PontusHovb/Sorting-Algorithms/blob/main/Visualizations/ShellSort.gif" width="400"/>
</p>
<p align="center"><i>Shell Sort</i></p>

Shell sort is an in-place comparison-based sorting algorithm that generalizes insertion sort to allow the exchange of items that are far apart. The algorithm starts by sorting pairs of elements far apart from each other, then **progressively reduces the gap between elements to be compared**. This gap reduction continues until the gap is 1, at which point the algorithm performs a final insertion sort. Shell sort significantly improves the performance of insertion sort on large lists by diminishing the increment sequence.

**Time complexity**
- Best: $`\mathcal{O}(n \log n)`$
- Average: $`\mathcal{O}(n \log n)`$
- Worst: $`\mathcal{O}(n^2)`$

## Heap Sort
<p align="center">
    <img src="https://github.com/PontusHovb/Sorting-Algorithms/blob/main/Visualizations/HeapSort.gif" width="400"/>
</p>
<p align="center"><i>Heap Sort</i></p>

Heap sort is a comparison-based sorting algorithm that leverages a **binary heap data structure to efficiently sort elements**. The process begins by building a max-heap from the input data, where the largest element is at the root of the heap. The largest element is then swapped with the last item in the heap and removed from consideration, and the heap is restructured to maintain the heap property. This process is repeated, reducing the heap size each time, until all elements are removed and the list is sorted. 

**Time complexity**
- Best: $`\mathcal{O}(n \log n)`$
- Average: $`\mathcal{O}(n \log n)`$
- Worst: $`\mathcal{O}(n \log n)`$
