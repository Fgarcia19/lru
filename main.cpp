#include <bits/stdc++.h>
#include "lru.h"
using namespace std;
int main()
{
    auto Cache= LRU<int>(3);
    Cache.insert("b",2);
    Cache.insert("a",1);
    Cache.insert("c",3);

    cout<<Cache.getMostRecent()->key;
    cout<<endl;

    cout<<Cache.getValuefrom("a");
    cout<<endl;
    cout<<Cache.getMostRecent()->key;


    //    Cache.imprimir();
//    cout<<endl;
//    Cache.imprimir_inverso();

}
