#include <iostream>
#include "list_item.hpp"

using namespace std;

int main()
{
    int a = 10;

    ListItem<int> item(a);

    cout << item.get_value();

    return 0;
}
