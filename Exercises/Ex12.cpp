#include <iostream>
#include <stack>
#include <optional>

template <typename T>
class queue_t
{
    std::stack<T> s1, s2;

public:
    void push(T a)
    {
        std::stack<T> temp, temp2;

        s1.push(a);
        temp = s1;
        while (!temp.empty())
        {
            temp2.push(temp.top());
            temp.pop();
        }
        s2 = temp2;
    }
    std::optional<T> pop()
    {
        if (s2.empty())
        {
            return {};
        }
        else
        {
            T popped = s2.top();
            s2.pop();
            return popped;
        }
    }
    std::optional<T> front()
    {
        if (s2.empty())
        {
            return {};
        }
        else
        {
            return s2.top();
        }
    }
    void print_queue()
    {
        std::stack<T> temp = s2;
        while (!temp.empty())
        {
            std::cout << temp.top() << ":";
            temp.pop();
        }
        std::cout << std::endl;
    }
};

int main()
{
    queue_t<int> q;
    bool is_val;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(3);
    q.push(5);
    q.print_queue();
    is_val = q.pop().has_value();
    if (!is_val)
    {
        std::cout << "Problem" << std::endl;
    }
    else
    {
        q.print_queue();
    }
    is_val = q.front().has_value();
    if (!is_val)
    {
        std::cout << "Problem" << std::endl;
    }
    else
    {
        std::cout << "Front " << q.front().value() << std::endl;
    }
    for (int i = 0; i < 5; i++)
    {
        is_val = q.pop().has_value();
        if (!is_val)
        {
            std::cout << "Problem" << std::endl;
        }
        else
        {
            q.print_queue();
        }
    }
    is_val = q.front().has_value();
    if (!is_val)
    {
        std::cout << "Problem" << std::endl;
    }
    else
    {
        std::cout << "Front " << q.front().value() << std::endl;
    }
    return 0;
}