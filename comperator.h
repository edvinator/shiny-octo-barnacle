#ifndef COMPERATOR_H
#define COMPERATOR_H
#include <numeric>
class comperator
{
public:
    bool operator()(float A, float B, float epsilon = 0.05f)
    {
        return (fabs(A - B) < epsilon);
    }
};

#endif // COMPERATOR_H
