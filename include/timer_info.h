#ifndef TIMER_INFO
#define TIMER_INFO

#include <boost/multiprecision/gmp.hpp>
#include <boost/timer/timer.hpp>

using namespace std;
using namespace boost::multiprecision;
using namespace boost::timer;

// Imprime o tempo armazendado em um temporizador em segundos e milissegundos
void print_timer_info(nanosecond_type elapsed);

#endif
