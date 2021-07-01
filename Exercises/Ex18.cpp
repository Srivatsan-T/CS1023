#include <iostream>
#include <array>
#include <vector>
#include <optional>

template <typename T>
class search
{
public:
    virtual std::optional<unsigned> bsearch(T a) = 0;
    virtual std::optional<unsigned> lsearch(T a) = 0;
};

template <typename T>
class search_vector : public search<T>
{
    std::vector<T> list;

public:
    search_vector(std::vector<T> t)
    {
        list = t;
    }
    std::optional<unsigned> lsearch(T a)
    {
        for (unsigned i = 0; i < list.size(); i++)
        {
            if (list[i] == a)
            {
                return i;
            }
        }
        return {};
    }

    std::optional<unsigned> bsearch(T a)
    {
        bool end = false;
        unsigned beg, mid, last;
        beg = 0;
        last = list.size() - 1;
        mid = (beg + last) / 2;
        while (!end && !((mid == 0) || (mid == list.size() - 1)))
        {
            if (list[mid] > a)
            {
                last = mid - 1;
                beg = 0;
                mid = (beg + last) / 2;
            }
            else if (list[mid] < a)
            {
                beg = mid + 1;
                last = list.size() - 1;
                mid = (beg + last) / 2;
            }
            else
            {
                end = true;
                return mid;
            }
        }
        return {};
    }
};

template <typename T>
class search_array : public search<T>
{
    std::array<T, 10> list;
    size_t size;

public:
    search_array(std::array<T, 10> t, unsigned n)
    {
        list = t;
        size = n;
    }
    std::optional<unsigned> lsearch(T a)
    {
        for (unsigned i = 0; i < size; i++)
        {
            if (list[i] == a)
            {
                return i;
            }
        }
        return {};
    }

    std::optional<unsigned> bsearch(T a)
    {
        bool end = false;
        unsigned beg, mid, last;
        beg = 0;
        last = size - 1;
        mid = (beg + last) / 2;
        while (!end && !((mid == 0) || (mid == size - 1)))
        {
            if (list[mid] > a)
            {
                last = mid - 1;
                beg = 0;
                mid = (beg + last) / 2;
            }
            else if (list[mid] < a)
            {
                beg = mid + 1;
                last = size - 1;
                mid = (beg + last) / 2;
            }
            else
            {
                end = true;
                return mid;
            }
        }
        return {};
    }
};

int main()
{
    std::vector<int> t = {1, 2, 34, 55};
    bool is_val;
    search<int> *t1 = new search_vector<int>(t);
    is_val = t1->lsearch(2).has_value();
    if (!is_val)
    {
        std::cout << "Not found!" << std::endl;
    }
    else
    {
        std::cout << t1->lsearch(2).value() << std::endl;
    }

    is_val = t1->lsearch(4).has_value();
    if (!is_val)
    {
        std::cout << "Not found!" << std::endl;
    }
    else
    {
        std::cout << t1->lsearch(4).value() << std::endl;
    }

    is_val = t1->bsearch(2).has_value();
    if (!is_val)
    {
        std::cout << "Not found!" << std::endl;
    }
    else
    {
        std::cout << t1->bsearch(2).value() << std::endl;
    }

    is_val = t1->bsearch(4).has_value();
    if (!is_val)
    {
        std::cout << "Not found!" << std::endl;
    }
    else
    {
        std::cout << t1->bsearch(4).value() << std::endl;
    }

    std::cout << "End of vector and beginning of array" << std::endl;

    std::array<int, 10> t3 = {1, 2, 34, 55};
    search<int> *t2 = new search_array<int>(t3, 4);
    is_val = t2->lsearch(2).has_value();
    if (!is_val)
    {
        std::cout << "Not found!" << std::endl;
    }
    else
    {
        std::cout << t2->lsearch(2).value() << std::endl;
    }

    is_val = t2->lsearch(4).has_value();
    if (!is_val)
    {
        std::cout << "Not found!" << std::endl;
    }
    else
    {
        std::cout << t2->lsearch(4).value() << std::endl;
    }

    is_val = t2->bsearch(2).has_value();
    if (!is_val)
    {
        std::cout << "Not found!" << std::endl;
    }
    else
    {
        std::cout << t2->bsearch(2).value() << std::endl;
    }

    is_val = t2->bsearch(4).has_value();
    if (!is_val)
    {
        std::cout << "Not found!" << std::endl;
    }
    else
    {
        std::cout << t2->bsearch(4).value() << std::endl;
    }

    is_val = t2->bsearch(60).has_value();
    if (!is_val)
    {
        std::cout << "Not found!" << std::endl;
    }
    else
    {
        std::cout << t2->bsearch(60).value() << std::endl;
    }

    return 0;
}