#define PLOOPY_DRAGSCROLL_INVERT
#define PLOOPY_DRAGSCROLL_DIVISOR_H 32.0 // lower values = more sensitive
#define PLOOPY_DRAGSCROLL_DIVISOR_V 32.0
#define PLOOPY_DPI_OPTIONS { 1200, 1400, 2400 } // greater values = more sensitve
#define PLOOPY_DPI_DEFAULT 1
#define PLOOPY_DRAGSCROLL_MOMENTARY

#define COMBO_COUNT 7

#define OS_DETECTION_KEYBOARD_RESET

// For reference:
// https://github.com/drashna/qmk_modules/tree/main/pointing_device_accel
// #define POINTING_DEVICE_ACCEL_TAKEOFF 2.0      // lower/higher value = curve takes off more smoothly/abruptly
// #define POINTING_DEVICE_ACCEL_GROWTH_RATE 0.25 // lower/higher value = curve reaches its upper limit slower/faster
// #define POINTING_DEVICE_ACCEL_OFFSET 2.2       // lower/higher value = acceleration kicks in earlier/later
// #define POINTING_DEVICE_ACCEL_LIMIT 0.1        // lower limit of accel curve (minimum acceleration factor)
