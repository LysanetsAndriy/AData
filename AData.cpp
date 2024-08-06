#include "AData.hpp"

using namespace std;

namespace AData
{
DataSet::DataSet()
{
//    this->X = new double*[this->m];
//    this->y = new double*[this->m];
//    this->data = new double*[this->m];
//    for(int i = 0; i < this->m; i++)
//    {
//        this->X[i] = new double[this->features];
//        this->y[i] = new double[1];
//        this->data[i] = new double[this->n];
//    }
}

DataSet::~DataSet()
{
    for(int i = 0; i < this->m; i++)
    {
        delete[] this->data[i];
        delete[] this->X[i];
        delete[] this->y[i];
    }
    for(int i = 0; i < this->train_size; i++)
    {
        delete[] this->train_set_X[i];
        delete[] this->train_set_y[i];
    }
    for(int i = 0; i < this->test_size; i++)
    {
        delete[] this->test_set_X[i];
        delete[] this->test_set_y[i];
    }
    delete[] this->data;
    delete[] this->X;
    delete[] this->y;
    delete[] this->train_set_X;
    delete[] this->train_set_y;
    delete[] this->test_set_X;
    delete[] this->test_set_y;

}

//getters
double DataSet::get_X_element(int i, int j) {return this->X[i][j];}
double ** DataSet::get_X() {return this->X;}
double ** DataSet::get_y() {return this->y;}
double ** DataSet::get_data() {return this->data;}
double ** DataSet::get_train_set_X() {return this->train_set_X;}
double ** DataSet::get_train_set_y() {return this->train_set_y;}
double ** DataSet::get_test_set_X() {return this->test_set_X;}
double ** DataSet::get_test_set_y() {return this->test_set_y;}
int DataSet::get_m() {return this->m;}
int DataSet::get_n() {return this->n;}
int DataSet::get_features() {return this->features;}
int DataSet::get_train_size() {return this->train_size;}
int DataSet::get_test_size() {return this->test_size;}

double **DataSet::get_X_row(int row_pos)
{
    double **tmp = new double*[1];
    tmp[0] = new double[this->n];
    for(int i = 0; i < this->n; i++)
    {
        tmp[0][i] = this->X[row_pos][i];
    }
    return tmp;
}
double DataSet::get_y_row(int row)
{
    return this->y[row][0];
}
double **DataSet::get_row(int row_pos)
{
    double **tmp = new double*[1];
    tmp[0] = new double[this->n];
    for(int i = 0; i < this->n; i++)
    {
        tmp[0][i] = this->data[row_pos][i];
    }
    return tmp;
}

double **DataSet::get_rows(int from, int to)
{
    double **tmp = new double*[to-from+1];

    for(int i = from; i < to; i++)
    {
        tmp[i-from] = new double[this->n];
        for(int j = 0; j < this->n; j++)
        {
            tmp[i-from][j] = this->data[i][j];
        }
    }
    return tmp;
}

double **DataSet::get_column(int column_pos)
{
    double **tmp = new double*[this->m];
    for(int i = 0; i < this->m; i++)
    {
        tmp[i] = new double[1];
        tmp[i][0] = this->data[i][column_pos];
    }
    return tmp;
}

double **DataSet::get_columns(int from, int to)
{
    double **tmp = new double*[this->m];

    for(int i = 0; i < this->m; i++)
    {
        tmp[i] = new double[to-from+1];
        for(int j = from; j < to; j++)
        {
            tmp[i][j-from] = this->data[i][j];
        }
    }
    return tmp;
}

//setters
void DataSet::set_data(double **dt)
{
    this->data = new double*[this->m];
    for (int i = 0; i < this->m; i++)
    {
        this->data[i] = new double[this->n];
        for(int j = 0; j < this->n; j++)
        {
            this->data[i][j] = dt[i][j];
        }
    }
}

void DataSet::set_X_element(double x, int i, int j)
{
    this->X[i][j] = x;
}
void DataSet::set_X_row(double *x, int i)
{
    this->X[i] = x;
}
void DataSet::set_y_row(double y, int i)
{
    this->y[i][0] = y;
}
void DataSet::set_X(double **X)
{
    this->X = new double*[this->m];
    for (int i = 0; i < this->m; i++)
    {
        this->X[i] = new double[this->features];
        for(int j = 0; j < this->features; j++)
        {
            this->X[i][j] = X[i][j];
        }
    }
}
void DataSet::set_y(double **y)
{
    this->y = new double*[this->m];
    for (int i = 0; i < this->m; i++)
    {
        this->y[i] = new double[1];
        this->y[i][0] = y[i][0];
    }
}
void DataSet::set_m(int m)
{
    this->m = m;
}
void DataSet::set_n(int n)
{
    this->n = n;
}
void DataSet::set_features(int f)
{
    this->features = f;
}
void DataSet::set_train_size(int sz)
{
    this->train_size = sz;
}
void DataSet::set_test_size(int sz)
{
    this->test_size = sz;
}
void DataSet::set_train_set_X(double **X)
{
    this->train_set_X = new double*[this->train_size];
    for (int i = 0; i < this->train_size; i++)
    {
        this->train_set_X[i] = new double[this->features];
        for(int j = 0; j < this->features; j++)
        {
            this->train_set_X[i][j] = X[i][j];
        }
    }
}
void DataSet::set_test_set_X(double **X)
{
    this->test_set_X = new double*[this->test_size];
    for (int i = 0; i < this->test_size; i++)
    {
        this->test_set_X[i] = new double[this->features];
        for(int j = 0; j < this->features; j++)
        {
            this->test_set_X[i][j] = X[i][j];
        }
    }
}
void DataSet::set_train_set_y(double **y)
{
    this->train_set_y = new double*[this->train_size];
    for (int i = 0; i < this->train_size; i++)
    {
        this->train_set_y[i] = new double[1];
        this->train_set_y[i][0] = y[i][0];
    }
}
void DataSet::set_test_set_y(double **y)
{
    this->test_set_y = new double*[this->test_size];
    for (int i = 0; i < this->test_size; i++)
    {
        this->test_set_y[i] = new double[1];
        this->test_set_y[i][0] = y[i][0];
    }
}

double **DataSet::head_X()
{
    double ** tmp = new double*[5];
    for(int i = 0; i < 5; i++)
    {
        tmp[i] = new double[this->n];
        for(int j = 0; j < this->n; j++)
        {
            tmp[i][j] = this->X[i][j];
        }
    }
    return tmp;
}

double **DataSet::head_X(int num)
{
    double ** tmp = new double*[num];
    for(int i = 0; i < num; i++)
    {
        tmp[i] = new double[this->n];
        for(int j = 0; j < this->n; j++)
        {
            tmp[i][j] = this->X[i][j];
        }
    }
    return tmp;
}

double **DataSet::tail_X()
{
    double ** tmp = new double*[5];
    for(int i = 0; i < 5; i++)
    {
        tmp[5-i-1] = new double[this->n];
        for(int j = 0; j < this->n; j++)
        {
            tmp[5-i-1][j] = this->X[this->m-i-1][j];
        }
    }
    return tmp;
}

double **DataSet::tail_X(int num)
{
    double ** tmp = new double*[num];
    for(int i = 0; i < num; i++)
    {
        tmp[num-i-1] = new double[this->n];
        for(int j = 0; j < this->n; j++)
        {
            tmp[num-i-1][j] = this->X[this->m-i-1][j];
        }
    }
    return tmp;
}

double **DataSet::head_y()
{
    double ** tmp = new double*[5];
    for(int i = 0; i < 5; i++)
    {
        tmp[i] = new double[1];
        tmp[i][0] = this->y[i][0];
    }
    return tmp;
}

double **DataSet::head_y(int num)
{
    double ** tmp = new double*[num];
    for(int i = 0; i < num; i++)
    {
        tmp[i] = new double[1];
        tmp[i][0] = this->y[i][0];
    }
    return tmp;
}

double **DataSet::tail_y()
{
    double ** tmp = new double*[5];
    for(int i = 0; i < 5; i++)
    {
        tmp[5-i-1] = new double[1];
        tmp[5-i-1][0] = this->y[this->m-i-1][0];
    }
    return tmp;
}

double **DataSet::tail_y(int num)
{
    double ** tmp = new double*[num];
    for(int i = 0; i < num; i++)
    {
        tmp[num-i-1] = new double[1];
        tmp[num-i-1][0] = this->y[this->m-i-1][0];
    }
    return tmp;
}

double **DataSet::slice_X(int from, int to)
{
    double ** tmp = new double*[to-from+1];
    for(int i = from; i < to; i++)
    {
        tmp[i-from] = new double[this->features];
        for(int j = 0; j < this->features; j++)
        {
            tmp[i-from][j] = this->X[i][j];
        }
    }
    return tmp;
}

double **DataSet::slice_y(int from, int to)
{
    double ** tmp = new double*[to-from+1];
    for(int i = from; i < to; i++)
    {
        tmp[i-from] = new double[1];
        tmp[i-from][0] = this->y[i][0];
    }
    return tmp;
}

}





















