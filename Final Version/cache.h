

#include <bits/stdc++.h>
#include "linkedlist.h"
template <typename T1,typename T2>
struct Cache{
    unordered_map<T1,Node<T1,T2>*> table;
    linkedlist<T1,T2> nodes;
    void (*funcion)(Cache*,T1,T2);
    int size;
    Cache(int s,void (*f)(Cache*,T1,T2)):size(s),funcion(f){};
    void insert(T1 key, T2 value);
    Node<T1,T2>* getMostRecent();
    void getValuefrom(T1 key);
    void ver();



};