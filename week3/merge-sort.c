// remember divide and conquoer
// Example visualization of the merge sort algorithm:
//
//          [38, 27, 43, 3, 9, 82, 10]
//                     /   \
//       [38, 27, 43, 3]   [9, 82, 10]
//        /         |         |      \
//   [38, 27]    [43, 3]   [9, 82]   [10]
//    /   |      /    |    /    \      |
// [38]  [27]  [43]  [3]  [9]   [82]  [10]
//    \  /       \   /     \     /     |
//   [27, 38]    [3, 43]   [9, 82]    [10]
//       \         /          \        /
//     [3, 27, 38, 43]        [9, 10, 82]
//           \                  /
//          [3, 9, 10, 27, 38, 43, 82]
//
// The array is first broken up into progressively smaller unsorted portions of
// the array, and once we have "sub-arrays" of 1 element they are by definition
// sorted arrays.  From here the "sorted arrays" are merged together until we
// arrive at the complete sorted array.

#include <stdio.h>

void merge_sorted_arrays(int a[], int l, int m, int r)
{
    int left_length = m - l + 1;
    int right_length = r - m;

    // create temp arrays
    int temp_left[left_length];
    int temp_right[right_length];

    // used as index/counter variables for the 3 arrays a, temp_left, temp_right
    int i, j, k;

    // copy to right and left temp arrays
    for (int i = 0; i < left_length; i++)
    {
        temp_left[i] = a[l + i];
    }

    for (int j = 0; j < right_length; j++)
    {
        temp_right[j] = a[m + 1 + j];
    }

    // Use i to move through the indexes of temp_left, j to move through the
    // indexes of temp_right, and k to move through the portion of the array
    // a from l ... r.  We basically keep checking the "head" of temp_left
    // and temp_right (knowing both arrays are sorted) and put the smaller of
    // the two into array a (using i, j, k to move through the arrays).  When
    // we run out elements in either temp_left or temp_right, the remaining
    // elements from the other array will be copied over into a.

    // whats going on before the loop
    // temp_left = [3, 27, 38, 43]
    // temp_right = [9, 10, 82]

    for (i = 0, j = 0, k = l; k <= r; k++)
    {
        // compares i and j if i<=j then add it to a[k] and do i++
        // else add j to a[k] and do j++
        // then do k++

        if ((i < left_length) &&
            (j >= right_length || temp_left[i] <= temp_right[j]))
        {
            a[k] = temp_left[i];
            i++;
        }

        else
        {
            a[k] = temp_right[j];
            j++;
        }
    }
}

void merge_sort_recursion(int a[], int l, int r)
{
    /// we stop recursion when l >= r
    if (l < r)
    {
        // find the midpoint of l and r
        int m = l + (r - l) / 2;

        // apply the function recursively to the left and right portions split
        // at the midpoint
        merge_sort_recursion(a, l, m);
        merge_sort_recursion(a, m + 1, r);

        // at this point both portions of the array have been sorted, and we now
        // merge the sorted portions of the array
        merge_sorted_arrays(a, l, m, r);
    }
}

void merge_sort(int array[], int length)
{
    // 0 is left most index (start of array) and length - 1 is right most index (excluding null)
    merge_sort_recursion(array, 0, length - 1);
}

int main(void)
{
    int array[] = {38, 27, 43, 3, 9, 82, 10};
    int length = sizeof(array) / sizeof(array[0]);

    // sort array using merge sort
    merge_sort(array, length);

    for (int i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}