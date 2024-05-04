#include <iostream>
#include "list_node.h"
#include "vector"
#include "list.h"
#include "list_iterator.h"
#include <forward_list>
#include "const_list_iterator.h"

using namespace std;


int main()
{

    setbuf(stdout, NULL);

    list<int> list1;

    list1.push_back(5);
    list1.push_back(4);
    list1.push_back(3);

    list<int> list2(list1);

    for(auto it : list2)
        cout << it.get_value();

    return 0;
}
