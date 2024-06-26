#include <iostream>

#include "list.h"
#include <vector>

using namespace std;

void print_list(list<int> &list)
{
    std::cout << list;
}

int main(void)
{
    setbuf(stdout, NULL);

    // Тест кострукторов

    cout << "Universal constructor test: ";

    vector<int> v = {1, 2, 3, 4, 5};
    list<int> list0(v.begin(), v.end());
    print_list(list0);

    std::cout << "\nConstructor 1 test: ";
    list<int> list1;

    std::cout << "\nConstructor 2 test: ";
    list<int> list2;

    std::cout << "\nConstructor 3 test: ";
    int arr[] = {5, 4, 3, 2, 1};
    list<int> list3(arr, 5);
    print_list(list3);

    std::cout << "\nConstructor 4 test: ";
    list<int> list4(list3);
    print_list(list4);

    std::cout << "\nConstructor 5 test: ";
    list<int> list5 = {5, 4, 3, 2, 1};
    print_list(list5);

    std::cout << "\nConstructor 6 test: ";
    auto fst = list3.begin();
    auto end = list3.begin() + 4;
    std::vector<int> vec228 = {1, 2, 3, 4};

    list<int> list6(fst, end);
    print_list(list6);

    // Тест виртуальных методов
    std::cout << "\nIs empty method: ";
    std::cout << "Is empty (list6): " << list6.is_empty();

    std::cout << "\nAfter clear method: ";
    list6.clear();
    std::cout << "Is empty (list6): " << list6.is_empty();


    // Тест push_front методов
    std::cout << "\nPush front by value: ";
    auto iterator = list6.push_front(6);

    while (iterator != list6.end())
    {
        std::cout << " " << (*iterator);
        iterator++;
    }

    print_list(list6);

    std::cout << "\nPush front by list (list3): ";
    list6.push_front(list3);
    print_list(list6);

    // Тест insert методов
    list<int> list7 = {1, 2, 3};

    std::cout << "\nInsert value to 1st pos: ";
    list7.insert(list7.begin() + 1, 4);
    print_list(list7);

    std::cout << "\nInsert list (list3) to 2nd pos: ";
    list7.insert(list7.begin() + 2, list3);
    print_list(list7);

    // Test push_back методов
    list<int> list8 = {1, 2, 3};
    std::cout << "\nPush back by value: ";
    list8.push_back(4);
    print_list(list8);

    std::cout << "\nPush back by list (list3): ";
    list8.push_back(list3);
    print_list(list8);

    // Тест pop методов
    std::cout << "\nPop front (list8): ";
    list8.pop_front();
    print_list(list8);

    std::cout << "\nPop back (list8): ";
    list8.pop_back();
    print_list(list8);

    // Тест reverse
    std::cout << "\nReverse list (list3): ";
    list3.reverse();
    print_list(list3);

    // Тест операторов

    list<int> list9 = {1, 2, 3};
    list<int> list10 = {1, 2, 3};

    std::cout << "\nTest == operator: ";
    if (list9 == list10)
    {
        std::cout << "done";
    } else
    {
        std::cout << "failed";
    }

    list9.pop_back();

    std::cout << "\nTest != operator: ";
    if (list9 != list10)
    {
        std::cout << "done";
    } else
    {
        std::cout << "failed";
    }

    std::cout << "\nTest = operator: ";
    list9 = list10;
    print_list(list9);

    std::cout << "\nTest += operator: ";
    list9 += list10;
    list9 += 25;
    print_list(list9);

    std::cout << "\nTest + operator: ";
    list9 = list10 + list8 + list9;
    list9 += 777;
    print_list(list9);

    // Тест итераторов
    std::cout << "\nTest iterators: ";
    auto iterator1 = list9.begin();
    //*iterator1 = 500;
    //*(++iterator1 + 1) = 400;
    print_list(list9);

    std::cout << "\nTest constant iterators: ";
    auto iterator2 = list9.cbegin();
    // *iterator2 = 522; - не должно работать
    ++iterator2++;
    auto iterator3 = list9.cend();

    while (++iterator2 != iterator3)
    {
        std::cout << (*iterator2) << " ";
    }

    list<int> list11 = {1, 2, 3};
    list<int> list12 = {4, 5, 6};

    // Тест merge метода
    std::cout << "\nMerge test: ";
    list12.merge(list11);
    list12.merge(505);
    print_list(list12);

    list<int> list14{1, 2, 3};

    cout << "\nException test #2";

    try
    {
        list14.insert(list14.begin() + 7, 12);
    } catch (iterator_error &)
    {
        cout << "\nException test #2 succeed";
    }

    // Тест bool оператора
    std::cout << "\nBool operators test (not constant): ";
    if (list11.begin())
    {
        std::cout << "test1 done ";
    } else
    {
        std::cout << "test1 fail ";
    }

    if (list11.end())
    {
        std::cout << "test2 fail";
    } else
    {
        std::cout << "test2 done";
    }

    std::cout << "\nBool operators test (constant): ";
    if (list11.cbegin())
    {
        std::cout << "test1 done ";
    } else
    {
        std::cout << "test1 fail ";
    }

    if (list11.cend())
    {
        std::cout << "test2 fail";
    } else
    {
        std::cout << "test2 done";
    }

    cout << "\nSublist test";

    list<int> list15 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    list<int> sublist = list15.sublist(list15.cbegin() + 3, list15.cend());

    cout << endl << sublist;

    list15.remove(list15.begin() + 3, list15.begin() + 6);

    cout << endl << list15;

    vector<double> lol = {1, 2, 3};

    list15 += lol;

    cout << endl << list15;

    list<int> list16 = list15 + lol;

    cout << endl << list16;

    list15.insert(list15.begin() + 1, lol);

    cout << endl << list15;

    list15.push_front(lol);

    cout << endl << list15;

    return 0;
}
