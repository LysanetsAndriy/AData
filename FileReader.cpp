#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <float.h>

#include "FileReader.hpp"

using namespace std;

namespace AData
{
FileReader::FileReader(string file, DataSet* data)
{
    this->file = file;
    this->data_set = data;
}

void FileReader::read_data()
{
    ifstream infile(this->file);
    ios_base::sync_with_stdio(0);
    infile.tie(0);

    vector<vector <double> > vdata;

    vector<double> v;
//    string f = "";
//    getline(infile, f);
    int i = 0;
    string s;

    while(infile)
    {
        string s;

        if (!getline( infile, s )) break;
        v.clear();
        istringstream ss( s );
        while (ss)
        {
            string s;

            if (!getline( ss, s, ',' )) break;
            v.push_back(stod(s));
        }
        vdata.push_back(v);
        i++;
    }
    (*data_set).set_m(vdata.size());
    (*data_set).set_n(vdata[0].size());
    double **data = new double*[vdata.size()];
    for(int i = 0; i < vdata.size(); i++)
    {
        data[i] = new double[vdata[i].size()];
        for(int j = 0; j < vdata[i].size(); j++)
        {
            data[i][j] = vdata[i][j];
        }
    }
    (*data_set).set_data(data);
    for(int i = 0; i < (*data_set).get_m(); i++)
    {
        delete[] data[i];
    }

    delete [] data;
}

void FileReader::print_raw_data()
{
    ifstream infile(this->file);
    ios_base::sync_with_stdio(0);
    infile.tie(0);

    int i = 0;
    string s;
    while(infile)
    {
        string s;

        if (!getline( infile, s )) break;
        cout << s << '\n';
        i++;
    }
}

void FileReader::print_raw_data(int n)
{
    ifstream infile(this->file);
    ios_base::sync_with_stdio(0);
    infile.tie(0);

    int i = 0;
    string s;
    while(infile && i < n)
    {
        string s;

        if (!getline( infile, s )) break;
        cout << s << '\n';
        i++;
    }
}
}

//void FileReader::read_data(bool letter_label)
//{
//    ifstream infile(this->file);
//    ios_base::sync_with_stdio(0);
//    infile.tie(0);
//
//    vector<vector <double> > vX;
//    vector<vector <double> > vy;
//
//    vector<double> v;
//
//    int i = 0;
//    string s;
//    while(infile)
//    {
//        string s;
//
//        if (!getline( infile, s )) break;
//        v.clear();
//        istringstream ss( s );
//        while (ss)
//        {
//            string s;
//
//            if (!getline( ss, s, ',' )) break;
//            if (letter_label && s[0] >= 'a' && s[0] <= 'z' )
//            {
//                vy.push_back({(double)((int)s[0] - 97)});
//            }
//            else
//            {
//                v.push_back(stod(s));
//            }
//        }
//        if(!letter_label)
//        {
//            vy.push_back({v.back()});
//            v.pop_back();
//        }
//        vX.push_back(v);
//        i++;
//    }
//    DataSet::m = vX.size();
//    DataSet::n = vX[0].size();
//    DataSet::X = new double*[vX.size()];
//    DataSet::y = new double*[vy.size()];
//    for(int i = 0; i < vX.size(); i++)
//    {
//        DataSet::X[i] = new double[vX[i].size()];
//        DataSet::y[i] = new double[1];
//        for(int j = 0; j < vX[i].size(); j++)
//        {
//            DataSet::X[i][j] = vX[i][j];
//        }
//        DataSet::y[i][0] = vy[i][0];
//    }
//}
