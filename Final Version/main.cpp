#include <bits/stdc++.h>
#include "lru.h"
using namespace std;
int main()
{
    auto Cache= LRU<int>(4);
    Cache.insert("b",2);
    Cache.insert("a",4);
    Cache.insert("c",3);

    Cache.getValuefrom("a");
    Cache.insert("b",20);
    cout<<Cache.getMostRecent()->key<<endl;
    Cache.getValuefrom("a");
    cout<<Cache.getMostRecent()->key<<endl;
    Cache.insert("d",4);
    Cache.insert("a",10);
    Cache.insert("e",6);
    Cache.insert("f",7);
    Cache.insert("g",7);
    Cache.insert("e",20);
    Cache.getValuefrom("d");
    Cache.getValuefrom("h");
    Cache.getValuefrom("b");
    Cache.getValuefrom("a");
    Cache.imprimir();
    cout<<endl;
    Cache.imprimir_inverso();
}

