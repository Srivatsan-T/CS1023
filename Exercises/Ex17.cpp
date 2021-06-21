#include <iostream>
#include <vector>

template <typename T>
class sort_t
{
public:
    std::vector<T> list;
    virtual std::vector<T> sort_list() = 0;
};

template <typename T>
class quick_sort_t : public sort_t<T>
{
public:
    int partition(std::vector<T> arr, int low, int high)
    {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                std::swap(&arr[i], &arr[j]);
            }
        }
        std::swap(&arr[i + 1], &arr[high]);
        return (i + 1);
    }

    std::vector<T> sort_list()
    {
        int low = 0;
        int high = list.size() - 1;
        if (low < high)
        {
            int pi = partition(list, low, high);
            sort_list(list, low, pi - 1);
            sort_list(list, pi + 1, high);
        }
        return list;
    }
};

template <typename T>
class merge_sort_t : public sort_t<T>
{
public:
    void merge(std::vector<T> arr, int l, int m, int r)
    {
        int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]

    // Initial index of first subarray
    int i = 0;

    // Initial index of second subarray
    int j = 0;

    // Initial index of merged subarray
    int k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


std::vector<T> sort_list()
{
    int l = 0;
    int r = list.size() - 1;
    if (l >= r)
    {
        return; //returns recursively
    }
    int m = l + (r - l) / 2;
    mergeSort(list, l, m);
    mergeSort(list, m + 1, r);
    merge(list, l, m, r);
    return list;
}

};

template <typename T>
class insertion_sort_t : public sort_t<T>
{
public:
    std::vector<T> sort_list()
    {
        int n = list.size();
        int i,j;
        T key;
        for (i = 1; i < n; i++)
        {
            key = list[i];
            j = i - 1;

            /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
            while (j >= 0 && list[j] > key)
            {
                list[j + 1] = list[j];
                j = j - 1;
            }
            list[j + 1] = key;
        }
        return list;
    }
}