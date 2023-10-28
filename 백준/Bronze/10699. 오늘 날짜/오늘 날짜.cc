#include <iostream>
#include <ctime>
using namespace std;

int main() {
    time_t timer;
    struct tm* t;
    timer = time(NULL) + (9*3600);
    t = localtime(&timer);

    cout << t->tm_year + 1900 << "-" << t->tm_mon+1 << "-" << t->tm_mday;
}