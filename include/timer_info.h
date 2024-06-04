#ifndef TIMER_INFO
#define TIMER_INFO

#include <boost/multiprecision/gmp.hpp>
#include <boost/timer/timer.hpp>

using namespace std;
using namespace boost::multiprecision;
using namespace boost::timer;

void print_timer_info(nanosecond_type elapsed);

#endif
