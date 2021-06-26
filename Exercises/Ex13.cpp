#include <iostream>

template <typename T>
class mylistiterator_t;

template <typename T>
class mylistnode_t
{

    T value;

public:
    mylistnode_t *prev;
    mylistnode_t *next;
    mylistnode_t *getprev() { return prev; }
    mylistnode_t *getnext() { return next; }
    T getval() { return value; }
    mylistnode_t(const T &v, const mylistnode_t<T> *n, const mylistnode_t<T> *p) : value(v), next(n), prev(p) {}
    mylistnode_t(const T &v) : value(v), next(nullptr), prev(nullptr) {}
    mylistnode_t(T &&v) : value(v), next(nullptr), prev(nullptr) {}
    mylistnode_t() : next(nullptr), prev(nullptr) {}

    friend class mylistiterator_t<T>;
};

template <typename T>
class mylistiterator_t : public std::iterator<std::forward_iterator_tag, T>
{
    mylistnode_t<T> *ptr;

public:
    mylistiterator_t() : ptr(nullptr) {}
    mylistiterator_t(mylistnode_t<T> *p) : ptr(p) {}
    mylistiterator_t(const mylistiterator_t<T> &it) { ptr = it.ptr; }
    void operator=(const mylistiterator_t<T> &it) { ptr = it.ptr; }
    template <typename T1>
    friend bool operator!=(const mylistiterator_t<T1> &, const mylistiterator_t<T1> &);
    template <typename T1>
    friend bool operator==(const mylistiterator_t<T1> &, const mylistiterator_t<T1> &);
    T &operator*() { return ptr->value; }

    mylistiterator_t<T> &operator++()
    {
        if (ptr != nullptr)
        {
            ptr = ptr->next;
        }
        return *this;
    }
    mylistiterator_t<T> &operator--()
    {
        if (ptr != nullptr)
        {
            ptr = ptr->prev;
        }
        return *this;
    }
    mylistiterator_t<T> operator++(int i)
    {
        mylistiterator_t tmpcopy(ptr);
        ++(*this);
        return tmpcopy;
    }
    mylistiterator_t<T> &operator+()
    {
        if (ptr != nullptr)
        {
            if (ptr->next != nullptr)
            {
                ptr = ptr->next->next;
                return *this;
            }
        }
        return *(new mylistiterator_t<T>);
    }
};

template <typename T>
bool operator!=(const mylistiterator_t<T> &it1, const mylistiterator_t<T> &it2)
{
    return it1.ptr != it2.ptr;
}
template <typename T>
bool operator==(const mylistiterator_t<T> &it1, const mylistiterator_t<T> &it2)
{
    return it1.ptr == it2.ptr;
}

template <typename T>
class mylist_t
{
    mylistnode_t<T> *head;
    mylistnode_t<T> *tail;

public:
    mylist_t() : head(nullptr), tail(nullptr) {}
    bool empty() const { return head == nullptr; }
    void push_front(T v)
    {
        auto p = new mylistnode_t<T>(v);
        p->next = head;
        p->prev = nullptr;
        if (head != nullptr)
        {
            head->prev = p;
        }
        else
        {
            tail = p;
        }
        head = p;
    }
    mylistiterator_t<T> &begin()
    {
        return *(new mylistiterator_t<T>(head));
    }
    mylistiterator_t<T> &end()
    {
        return *(new mylistiterator_t<T>(tail));
    }
    size_t size()
    {
        size_t sz = 0;
        auto it = this->end();
        auto it_front = this->begin();
        while (it != it_front)
        {
            --it;
            sz++;
        }
        return (sz + 1);
    }

    void plus_two()
    {
        auto it = this->begin();
        auto it_end = this->end();
        while (it != *(new mylistiterator_t<T>))
        {
            std::cout << *it << ":";
            it = +it;
        }
        std::cout << std::endl;
    }
};

int main()
{

    int arr[] = {1, 2, 3, 4, 32, 54, -9, 0, 0, 3, 2, -90, 123123, -451212,2};
    constexpr size_t asize = sizeof(arr) / sizeof(int);
    mylist_t<int> l;
    for (unsigned i = 0; i < asize; i++)
    {
        l.push_front(arr[i]);
    }
    std::cout << "pushed" << std::endl;
    std::cout << "size of list is " << l.size() << std::endl;
    std::cout << "Two jumps!" << std::endl;
    l.plus_two();
    return 0;
}