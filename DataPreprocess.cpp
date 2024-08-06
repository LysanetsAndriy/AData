#include <iostream>
#include <random>
#include <float.h>

#include "DataPreprocess.hpp"

using namespace std;

namespace AData
{

DataPreprocess::DataPreprocess(DataSet* data)
{
    this->data_set = data;
}

double DataPreprocess::random(double from, double to)
{
    return (double)(rand()) / RAND_MAX * (to - from) + from;
}

void DataPreprocess::shuffle()
{
    int j;
    double *tmp_x;
    double tmp_y;
    for(int i = 0; i < (*data_set).get_m(); i++)
    {
        j = (int)random(0, (*data_set).get_m()-1);
        tmp_x = (*data_set).get_X_row(i)[0];
        (*data_set).set_X_row((*data_set).get_X_row(j)[0], i);
        (*data_set).set_X_row(tmp_x, j);

        tmp_y = (*data_set).get_y_row(i);
        (*data_set).set_y_row((*data_set).get_y_row(j), i);
        (*data_set).set_y_row(tmp_y, j);
    }
}

void DataPreprocess::split(double d)
{
    if (d > 1 || d < 0)
    {
        cout << "Vrong value of d. d must be 0 <= d <= 1\n";
    }
    else
    {
        int train_size = (*data_set).get_m() * d;
        int test_size = (*data_set).get_m() - train_size;
        (*data_set).set_train_size(train_size);
        (*data_set).set_test_size(test_size);
        double **train_set_X = new double*[train_size];
        double **test_set_X = new double*[test_size];
        double **train_set_y = new double*[train_size];
        double **test_set_y = new double*[test_size];
        for (int i = 0; i < train_size; i++)
        {
            train_set_X[i] = new double[(*data_set).get_features()];
            train_set_y[i] = new double[1];
            for(int j = 0; j < (*data_set).get_features(); j++)
            {
                train_set_X[i][j] = (*data_set).get_X()[i][j];
                train_set_y[i][0] = (*data_set).get_y()[i][0];
            }
        }
        for (int i = train_size, j = 0; i < (*data_set).get_m(); i++, j++)
        {
            test_set_X[j] = new double[(*data_set).get_features()];
            test_set_y[j] = new double[1];
            for(int k = 0; k < (*data_set).get_features(); k++)
            {
                test_set_X[j][k] = (*data_set).get_X()[i][k];
                test_set_y[j][0] = (*data_set).get_y()[i][0];
            }
        }
        (*data_set).set_train_set_X(train_set_X);
        (*data_set).set_test_set_X(test_set_X);
        (*data_set).set_train_set_y(train_set_y);
        (*data_set).set_test_set_y(test_set_y);
        for(int i = 0; i < (*data_set).get_train_size(); i++)
        {
            delete[] train_set_X[i];
            delete[] train_set_y[i];
        }

        delete [] train_set_X;
        delete [] train_set_y;

        for(int i = 0; i < (*data_set).get_test_size(); i++)
        {
            delete[] test_set_X[i];
            delete[] test_set_y[i];
        }

        delete [] test_set_X;
        delete [] test_set_y;


    }
}

void DataPreprocess::normalize()
{
    double mx = DBL_MIN;
    double mn = DBL_MAX;
    double **X = (*data_set).get_X();
    for (int i = 0; i < (*data_set).get_features(); i++)
    {
        mx = DBL_MIN;
        mn = DBL_MAX;
        for (int j = 0; j < (*data_set).get_m(); j++)
        {
            mx = max(mx, X[j][i]);
            mn = min(mn, X[j][i]);
        }
        for (int j = 0; j < (*data_set).get_m(); j++)
        {
            X[j][i] = (X[j][i] - mn) / (mx - mn);
        }
    }
    (*data_set).set_X(X);
    for(int i = 0; i < (*data_set).get_m(); i++)
    {
        delete[] X[i];
    }

    delete [] X;
}


}
