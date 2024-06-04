#include "timer_info.h"

void print_timer_info(nanosecond_type elapsed) {
    cout << elapsed/1000000000 << " segundo(s) e " << (elapsed%1000000000)/1000000 << " milissegundo(s)" << endl;
}