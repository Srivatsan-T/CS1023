#include <iostream>
#include <vector>

template <typename T>
class matrix_t
{
    unsigned row;
    unsigned column;
    std::vector<std::vector<T>> matrix;

public:
    matrix_t(unsigned a, unsigned b)
    {
        row = a;
        column = b;
    }

    void input_matrix (std::vector<std::vector<T>>& vec)
    {
        std::cout<<"Input Started"<<std::endl;
        matrix = vec;
        std::cout<<"Matrix Ready"<<std::endl;
    }

    void show_matrix()
    {
        for (unsigned i = 0; i < row; i++)
        {
            for (unsigned j = 0; j < column; j++)
            {
                std::cout << matrix[i][j] << "*";
            }
        }
    }

    unsigned get_row()
    {
        return row;
    }

    unsigned get_column()
    {
        return column;
    }

    std::vector<std::vector<T>>& get_matrix()
    {
        return matrix;
    }
};

template <typename T, typename U>
matrix_t<T> add_matrix(matrix_t<T> a, matrix_t<U> b)
{
    matrix_t<T> res(a.get_row(), b.get_column());
    if (a.get_row() != b.get_row() || a.get_column() != b.get_column())
    {
        std::cout << "The two matrices cant be added";
    }
    else
    {
        std::vector<T> col_vect;
        for(unsigned i = 0;i<b.get_column();i++)
        {
            col_vect.push_back(0);
        }
        for(unsigned i = 0;i<a.get_row();i++)
        {
            res.get_matrix().push_back(col_vect);
        }
        for (unsigned i = 0; i < a.get_row(); i++)
        {
            for (unsigned j = 0; j < b.get_column(); j++)
            {
                res.get_matrix()[i][j] = a.get_matrix()[i][j] + b.get_matrix()[i][j];
            }
        }
    }
    return res;
}

template <typename T, typename U>
matrix_t<T> sub_matrix(matrix_t<T> a, matrix_t<U> b)
{
    matrix_t<T> res(a.get_row(), b.get_column());
    if (a.get_row() != b.get_row() || a.get_column() != b.get_column())
    {
        std::cout << "The two matrices cant be subtracted";
    }
    else
    {
        std::vector<T> col_vect;
        for(unsigned i = 0;i<b.get_column();i++)
        {
            col_vect.push_back(0);
        }
        for(unsigned i = 0;i<a.get_row();i++)
        {
            res.get_matrix().push_back(col_vect);
        }
        for (unsigned i = 0; i < a.get_row(); i++)
        {
            for (unsigned j = 0; j < b.get_column(); j++)
            {
                res.get_matrix()[i][j] = a.get_matrix()[i][j] - b.get_matrix()[i][j];
            }
        }
    }
    return res;
}

int main()
{
    matrix_t<int> a(2,2);
    matrix_t<float> b(2,2);
    std::vector<std::vector<int>> avec = {{10,20},{30,40}};
    std::vector<std::vector<float>> bvec = {{10.5,20.5},{30.5,40.5}};
    a.input_matrix(avec);
    b.input_matrix(bvec);
    add_matrix(b,a).show_matrix();
    std::cout<<std::endl;
    sub_matrix(b,a).show_matrix();
    return 0;
}