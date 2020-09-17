#include "Date.h"
#include <iostream>

using namespace std;
int main()
{
    Date date(2020,3,1);
    Date date2 = date;
    date + 365*100;
    cout << date - date2 << endl;
    return 0;
}
