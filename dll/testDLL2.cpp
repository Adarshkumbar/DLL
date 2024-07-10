// MultiplicationDLL.cpp
#include <iostream>

extern "C" __declspec(dllexport) bool NotGate(bool x)
{
    return !x;
}
