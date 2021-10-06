#pragma once
// Obins stock firmware has something similar to this already enabled, but disabled by default in QMK
//#define PERMISSIVE_HOLD
// Tap layer wait time
#undef TAPPING_TERM
#define TAPPING_TERM 200

#define SLEEP_TIME_AMOUNT (120 * 1000)