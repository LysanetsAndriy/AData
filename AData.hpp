#ifndef ADATA_HPP_INCLUDED
#define ADATA_HPP_INCLUDED

#include <vector>
#include <fstream>

namespace AData
{
    class DataSet
    {
    private:
        int features;
        int m, n;
        int train_size;
        int test_size;
        double **X;
        double **y;
        double **data;
        double **train_set_X;
        double **train_set_y;
        double **test_set_X;
        double **test_set_y;

    public:
        DataSet();
        ~DataSet();
        // getters:
        double get_X_element(int i, int j);
        double **get_X_row(int row);
        double get_y_row(int row);
        double **get_X();
        double **get_y();
        double **get_train_set_X();
        double **get_train_set_y();
        double **get_test_set_X();
        double **get_test_set_y();
        double **get_data();
        int get_m();
        int get_n();
        int get_features();
        int get_train_size();
        int get_test_size();
        double **get_row(int row_pos);
        double **get_rows(int from, int to);
        double **get_column(int column_pos);
        double **get_columns(int from, int to);

        //setters:
        void set_data(double **dt);
        void set_X_element(double x, int i, int j);
        void set_X_row(double *x, int i);
        void set_y_row(double y, int i);
        void set_X(double **X);
        void set_y(double **y);
        void set_m(int m);
        void set_n(int n);
        void set_features(int f);
        void set_train_size(int sz);
        void set_test_size(int sz);
        void set_train_set_X(double **X);
        void set_test_set_X(double **X);
        void set_train_set_y(double **y);
        void set_test_set_y(double **y);

        double **head_X();
        double **head_X(int n);
        double **tail_X();
        double **tail_X(int n);
        double **slice_X(int from, int to);

        double **head_y();
        double **head_y(int n);
        double **tail_y();
        double **tail_y(int n);
        double **slice_y(int from, int to);
    };
}



#endif
