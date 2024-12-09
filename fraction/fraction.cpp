#include <iostream>
#include <assert.h>
#include "fraction.h"
using namespace std;

int main()
{

    fraction omg(15, 20);
    fraction tysm;
    fraction omfg(3, 3);

    //проверка операций +,-,*,/,==, NOD
    // +
    tysm = omg + omg;
    assert(tysm.get_frac() == 1.5);
    tysm = omg + omfg;
    assert(tysm.get_frac() == 1.75);
    tysm = omfg + omfg;
    assert(tysm.get_frac() == 2);
    // -
    tysm = omg - omg;
    assert(tysm.get_frac() == 0);
    tysm = omg - omfg;
    assert(tysm.get_frac() == -0.25);
    tysm = tysm - omfg;
    assert(tysm.get_frac() == -1.25);
    // *
    tysm = omg * omg;
    assert(tysm.get_frac() == 0.5625);
    tysm = omg * omfg;
    assert(tysm.get_frac() == 0.75);
    tysm = omfg * omfg;
    assert(tysm.get_frac() == 1);
    // /
    tysm = omg / omg;
    assert(tysm.get_frac() == 1);
    tysm = omg / omfg;
    assert(tysm.get_frac() == 0.75);
    tysm = omfg / omfg;
    assert(tysm.get_frac() == 1);
    // ==
    assert((omg == omfg) == 0);
    assert((omfg == omfg) == 1);
    assert((tysm == omfg) == 1);
    // NOD
    assert(NOD(15, 20) == 5);
    assert(NOD(45, 30) == 15);
    assert(NOD(13, 20) == 1);


    // ПРИМЕРЫ
    // динамический объект
    int x, y;
    cin >> x >> y;
    fraction gosh(x, y);
    cout << gosh.get_frac() << endl;

    //динамический массив из объектов
    fraction* iwms;
    int n;
    cin >> n;
    iwms = new fraction[n];
    for (int i = 0; i < n; i++)
        iwms[i] = fraction(i + 1, i + 2);

    // for (int i = 0; i < n; i++)
    //     cout << iwms[i]->*get_frac();

}
