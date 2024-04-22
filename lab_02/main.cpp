#include <iostream>
#include <map>

#include "const_iterator.hpp"
#include "list.hpp"

using namespace std;

int main()
{
    const_list_iterator<int> it;

    ++it;

    return 0;
}
