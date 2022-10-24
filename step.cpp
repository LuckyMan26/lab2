#include "step.h"
template <typename T>
Step<T>::Step()
{

}
template <typename T>
void Step<T>::SetFunction(std::function<void ()> fun){
    this->fn=fun;
}
