#ifndef FILEREADER_HPP_INCLUDED
#define FILEREADER_HPP_INCLUDED

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <float.h>

#include "AData.hpp"

namespace AData
{
class FileReader
{
private:
    std::string file;
    DataSet* data_set;

public:
    FileReader(std::string file, DataSet *data);
    void read_data();
    void print_raw_data();
    void print_raw_data(int n);

};
}
#endif // FILEREADER_HPP_INCLUDED
