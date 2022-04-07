#include <stdio.h>

void swap(int *a, int *b)
{
    *a += *b;
    *b = *a - *b;
    *a -= *b;
}

void quick_sort_t(int *array, int start, int end)
{

    if (start >= end)
    {
        return;
    }

    int anchor_index = start;

    for (int i = start; i < end; i++)
    {
        if (array[i] < array[anchor_index])
        {
            swap(&array[i], &array[anchor_index]);
            anchor_index = i;
        }
    }

    quick_sort_t(array, start, anchor_index);
    quick_sort_t(array, anchor_index + 1, end);

}

void quick_sort(int *array, int length)
{
    quick_sort_t(array, 0, length);
}

void selection_sort(int *array, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int min_index = i;

        for (int j = i; j < length; j++)
        {
            if (array[j] < array[min_index])
            {
                min_index = j;
            }
        }

        if (min_index != i)
        {
            swap(&array[i], &array[min_index]);
        }
    }
}

void insertion_sort(int *array, int length)
{
    for (int i = 1; i < length; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
                continue;
            }

            break;
        }
    }
}

void comb_sort(int *array, int length)
{
    const double factor = 1.247;
    int distance = length - 1;

    while (distance > 0)
    {

        for (int i = 0; i + distance < length; i++)
        {
            if (array[i] > array[i + distance])
            {
                swap(&array[i], &array[i + distance]);
            }
        }
        
        distance /= factor;
    }
}

void shaker_sort(int *array, int length)
{
    int left = 0;
    int right = length - 1;

    while (left <= right)
    {
        for (int i = left; i < right; i++)
        {
            if (array[i] > array[i + 1])
            {
                swap(&array[i], &array[i + 1]);
            }
        }

        for (int i = right; i > left; i--)
        {
            if (array[i] < array[i - 1])
            {
                swap(&array[i], &array[i - 1]);
            }
        }

        ++left;
        --right;

    }
}

void bubble_sort(int *array, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

void print(int *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int array[] = {9, 2, 1, 6, 7};
    int length = sizeof(array) / sizeof(int);

    print(array, length);

    quick_sort(array, length);
   
    print(array, length);

    return 0;    
}