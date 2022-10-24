#ifndef STEP_H
#define STEP_H
#include <vector>
#include "vector.h"
#include "linkedlist.h""
#include <functional>
template<typename T>
class Step
{
    std::vector<T> steps;
   std::function<void ()> fn;
public:
    Step();
    void SetFunction(std::function<void ()> fun);
};

#endif // STEP_H
