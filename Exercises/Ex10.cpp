#include <iostream>
#include <list>
#include <array>
#include<optional>
//#include <iterator>
template <typename T>
class stack_t
{
public:
    stack_t()
    {
    }
    virtual std::optional<int> push(T a) = 0;
    virtual std::optional<T> pop() = 0;
    virtual std::optional<T> top() = 0;
    virtual void show_stack() = 0;
};

template <typename T>
class stack_list : public stack_t<T>
{
    std::list<T> stack;

public:
    stack_list()
    {
    }
    std::optional<int> push(T a)
    {
        stack.push_front(a);
        return 1;
    }
    std::optional<T> pop()
    {
        if(stack.size() == 0)
        {
            std::cout<<"The stack is empty!"<<std::endl;
            return {};
        }
        T popped = stack.front();
        stack.pop_front();
        return popped;
    }
    std::optional<T> top()
    {
        if(stack.size() == 0)
        {
            std::cout<<"The stack is empty!"<<std::endl;
            return {};
        }
        return stack.front();
    }
    void show_stack()
    {
        for (const auto t : stack)
        {
            std::cout << ":" << t;
        }
        std::cout << std::endl;
    }
};

template <typename T>
class stack_array : public stack_t<T>
{
    std::array<T, 100> stack;
    unsigned size;

public:
    stack_array()
    {
        size = 0;
    }
    std::optional<int> push(T a)
    {
        if(size == 100)
        {
            std::cout<<"Stack overflow!"<<std::endl;
            return {};
        }
        if (size != 0)
        {
            for (int i = size - 1; i >= 0; i--)
            {
                stack[i + 1] = stack[i];
            }
        }
        stack[0] = a;
        size++;
        return 1;
    }
    std::optional<T> pop()
    {
        if(size == 0)
        {
            std::cout<<"Stack is empty"<<std::endl;
            return {};
        }
        T popped = stack[0];
        for (int i = 0; i < size; i++)
        {
            stack[i] = stack[i + 1];
        }
        size--;
        return popped;
    }
    std::optional<T> top()
    {
        if(size == 0)
        {
            std::cout<<"Stack is empty"<<std::endl;
            return {};
        }
        return stack[0];
    }
    void show_stack()
    {
        for (unsigned i = 0; i < size; i++)
        {
            std::cout << ":" << stack[i];
        }
        std::cout << std::endl;
    }
};

int main()
{
    stack_t<int> *list_stack = new stack_list<int>;
    bool is_val;
    for(int i =0;i<8;i++)
    {
        is_val = list_stack->push(i*10+10).has_value();
        if(!is_val)
        {
            std::cout<<"Problem"<<std::endl;
            break;
        }  
    }
    list_stack->show_stack();
    for(int i=0;i<5;i++)
    {
        is_val = list_stack->pop().has_value();
        if(!is_val)
        {
            std::cout<<"Problem"<<std::endl;
        }
    }
    is_val = list_stack->top().has_value();
    if(!is_val)
    {
        std::cout<<"Problem"<<std::endl;
    }
    else
    {
        std::cout<<"TOP "<<list_stack->top().value()<<std::endl;
    }
    list_stack->show_stack();
    std::cout << std::endl;
    std::cout << "End of list- beginning of array" << std::endl;

    stack_t<int> *array_stack = new stack_array<int>;
    for(int i =0;i<3;i++)
    {
        is_val = array_stack->push(i*10+10).has_value();
        if(!is_val)
        {
            std::cout<<"Problem"<<std::endl;
        }  
    }
    array_stack->show_stack();
    is_val = array_stack->top().has_value();
    if(!is_val)
    {
        std::cout<<"Problem"<<std::endl;
    }
    else
    {
        std::cout<<"TOP "<<array_stack->top().value()<<std::endl;
    }
    for(int i=0;i<5;i++)
    {
        is_val = array_stack->pop().has_value();
        if(!is_val)
        {
            std::cout<<"Problem"<<std::endl;
        }
    }
        is_val = array_stack->top().has_value();
    if(!is_val)
    {
        std::cout<<"Problem"<<std::endl;
    }
    else
    {
        std::cout<<"TOP "<<array_stack->top().value()<<std::endl;
    }

    return 0;
}
