/*
Program reads integers into an array and uses a sorting method to sort them from smallest to largest. 
Demonstrates knowledge of sorting algorithms and array manipulation.
*/
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *arr, int length);
void merge_sort(int *arr, int l, int r);
void merge(int *arr, int l, int m, int r);
void quick_sort(int *arr, int l, int r);
int quick(int *arr, int l, int r);

void swap(int *xp, int *yp) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

int main() {
  //prompt for array length
  int length;
  printf("Input array length: ");
  scanf("%d", &length);

  //check if array length is not negative or zero
  if (length < 0) {
    fprintf(stderr, "Cannot accept negative integer as array size.\n");
    return 1;
  } else if (length == 0) {
    printf("\n");
    return 0;
  }

  //read a number of integers specified by the length prompt
  printf("Input array: ");
  int *arr = malloc(length * sizeof(int));
  for (int i = 0; i < length; i++) {
    scanf("%1d", &arr[i]);
  }

  //simple menu to choose the sorting method
  printf("Choose the sorting method:\n1.Bubble Sort\n2.Merge Sort\n3.Quick Sort\nChoice: ");
  int choice;
  scanf("%d", &choice);
  if (choice == 1) {
    bubble_sort(arr, length);
  } else if (choice == 2) {
    merge_sort(arr, 0, length - 1);
  } else if (choice == 3) {
    quick_sort(arr, 0, length - 1);
  }

  //print the sorted array
  printf("Output: ");
  for (int i = 0; i < length; i++) {
    printf("%d", arr[i]);
  }
  free(arr);
  return 0;
}

//bubble sort method
void bubble_sort(int *arr, int length) {
  for (int i = 0; i < length - 1; i++) {
    for (int j = 0; j < length - i - 1; j++) {
      if (arr[j] > arr[j+1]) {
        swap(&arr[j], &arr[j+1]);
      }
    }
  }
}

//merge sort method
void merge_sort(int *arr, int l, int r) {
  if (l < r) {
    int m = (l + r) / 2;

    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);

    merge(arr, l, m, r);

  }
}

//merge sort helper function
void merge(int *arr, int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;
  int L[n1], R[n2];

  int i, j, k;

  for (i = 0; i < n1; i++) {
    L[i] = arr[l + i];
  }
  for (j = 0; j < n2; j++) {
    R[j] = arr[m + 1 + j];
  }

  i = 0;
  j = 0; 
  k = l;
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
  while (i < n1) {
      arr[k] = L[i];
      i++;
      k++;
  }
  while (j < n2) {
      arr[k] = R[j];
      j++;
      k++;
  }

}

//quick sort method
void quick_sort(int *arr, int l, int r) {
  if (l < r) {
    int m = quick(arr, l, r);

    quick_sort(arr, l, m - 1);
    quick_sort(arr, m + 1, r);
  }
}

//quick sort helper function
int quick(int *arr, int l, int r) {
  int i = l - 1;
  for (int j = l; j <= r; j++) {
    if (arr[j] < arr[r]) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[r]);
  return (i + 1);
}