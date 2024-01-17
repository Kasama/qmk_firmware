#include "leader.h"
#include "keycodes.h"

__attribute__((weak)) void leader_start_kasama(void) {}

void leader_start_user(void) {
    leader_start_kasama();
}

__attribute__((weak)) void leader_end_kasama(void) {}

void leader_end_user(void) {
    leader_end_kasama();
}
