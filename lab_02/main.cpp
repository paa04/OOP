#include <iostream>
#include "list_node.h"
#include "vector"
#include "list.h"
#include "list_iterator.h"

using namespace std;


int main()
{
//    list_iterator<int> it;

    vector<int> v = {1, 2, 3};

    vector<int>::iterator it = v.begin();

    auto a = it += 2;

    cout << *a;

    return 0;
}
