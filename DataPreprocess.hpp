#ifndef DATAPREPROCESS_HPP_INCLUDED
#define DATAPREPROCESS_HPP_INCLUDED

#include "AData.hpp"

namespace AData
{

class DataPreprocess
{
private:
    DataSet* data_set;
    double random(double from, double to);

public:
    DataPreprocess(DataSet* data);
    void shuffle();
    void split(double d);
    void normalize();

};

}
#endif // DATAPREPROCESS_HPP_INCLUDED
