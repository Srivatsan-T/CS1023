#include <iostream>
#include <vector>

template <typename T>
class sort_t
{
public:
    virtual std::vector<T> sort_list() = 0;
    void print_vec(std::vector<T> a)
    {
        for (unsigned i = 0; i < a.size(); i++)
        {
            std::cout << a[i] << ":";
        }
        std::cout << std::endl;
    }
};

template <typename T>
class quick_sort_t : public sort_t<T>
{
    std::vector<T> list;

public:
    quick_sort_t(std::vector<T> i)
    {
        list = i;
    }
    void swap(T *a, T *b)
    {
        T t = *a;
        *a = *b;
        *b = t;
    }

    /* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
    int partition(std::vector<T> arr, int low, int high)
    {
        T pivot = arr[high]; // pivot
        int i = (low - 1);     // Index of smaller element and indicates the right position of pivot found so far

        for (int j = low; j <= high - 1; j++)
        {
            // If current element is smaller than the pivot
            if (arr[j] < pivot)
            {
                i++; // increment index of smaller element
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        return (i + 1);
    }

    /* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
    void quickSort(std::vector<T> arr, int low, int high)
    {
        if (low < high)
        {
            /* pi is partitioning index, arr[p] is now
        at right place */
            int pi = partition(arr, low, high);

            // Separately sort elements before
            // partition and after partition
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    std::vector<T> sort_list()
    {
        quickSort(list,0,list.size()-1);
        return list;
    }
};

template <typename T>
class merge_sort_t : public sort_t<T>
{
    std::vector<T> list;

public:
    merge_sort_t(std::vector<T> i)
    {
        list = i;
    }
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
    void mergeSort(std::vector<T> arr, int l, int r)
    {
        if (l >= r)
        {
            return; //returns recursively
        }
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
    std::vector<T> sort_list()
    {
        mergeSort(list, 0, list.size() - 1);
        return list;
    }
};

template <typename T>
class insertion_sort_t : public sort_t<T>
{
    std::vector<T> list;

public:
    insertion_sort_t(std::vector<T> i)
    {
        list = i;
    }
    std::vector<T> sort_list()
    {
        int n = list.size();
        int i, j;
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
};

int main()
{
    std::vector<int> a = {2, 13, 5, 34, 1, 43};
    sort_t<int> *t1 = new insertion_sort_t<int>(a);
    sort_t<int> *t2 = new merge_sort_t<int>(a);
    sort_t<int> *t3 = new quick_sort_t<int>(a);
    t1->print_vec(t1->sort_list());
    t2->print_vec(t2->sort_list());
    t3->print_vec(t3->sort_list());
    return 0;
}