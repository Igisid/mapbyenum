#include "mapbyenum.h"

enum class Method
{
    Registration = 0,
    SignIn,
    Weather,
    Location,
    Choice,
    Error
};

int main()
{
    MapByEnum<Method> mbe;

    auto s = mbe[Method::Registration];

    auto v = mbe.index("Error");

    return int(v.value());
}
