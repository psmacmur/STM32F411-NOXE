#include "defines.h"

// PID values in pid.c

// rate in deg/sec for acro mode
#define MAX_RATE 600
#define MAX_RATEYAW 600

// max angle for level mode
#define LEVEL_MAX_ANGLE 80

// max rate used by level pid (limit)
#define LEVEL_MAX_RATE 500

#define LOW_RATES_MULTI 0.5

// Change this factor to get a correct battery voltage.
#define ADC_SCALEFACTOR 11.111 // 11.0 for an ideal 10k/1k voltage divider

// Make sure to understand CELL_COUNT_UNSCALED in battery.c before enabling this.
#define BATTERY_CELL_COUNT_DETECTION

// Do not start software if battery is too low. Flashes 2 times repeatedly at startup.
// #define STOP_LOWBATTERY // If below 3.3 Volt

// If enabled, start LED blinking at low battery voltage
#define WARN_ON_LOW_BATTERY 3.6 // Volt

// Voltage hysteresis for WARN_ON_LOW_BATTERY
#define VOLTAGE_HYSTERESIS 0.10 // Volt

// compensation for battery voltage vs throttle drop
#define VDROP_FACTOR 0.7
// calculate above factor automatically
#define AUTO_VDROP_FACTOR

// lower throttle when battery below threshold
#define LVC_LOWER_THROTTLE
#define LVC_LOWER_THROTTLE_VOLTAGE 3.30
#define LVC_LOWER_THROTTLE_VOLTAGE_RAW 2.70
#define LVC_LOWER_THROTTLE_KP 3.0

// MPU-60x0 on-chip Gyro LPF filter frequency
// gyro filter 0: 256 Hz, delay 0.98 ms (use this to get 8k gyro update frequency)
// gyro filter 1: 188 Hz, delay 1.9 ms
// gyro filter 2: 98 Hz, delay 2.8 ms
// gyro filter 3: 42 Hz, delay 4.8 ms
#define GYRO_LOW_PASS_FILTER 0

// Gyro Notch Filters

// #define BIQUAD_NOTCH_A_HZ 260
// #define BIQUAD_NOTCH_A_Q 6

// #define BIQUAD_NOTCH_B_HZ 330
// #define BIQUAD_NOTCH_B_Q 6

// #define BIQUAD_NOTCH_C_HZ 380
// #define BIQUAD_NOTCH_C_Q 6

// Gyro first and second order LPFs

#define GYRO_LPF_1ST_HZ_BASE 120 // Filter frequency at zero throttle.
#define GYRO_LPF_1ST_HZ_MAX 120 // A higher filter frequency than loopfrequency/2.4 causes ripples.
#define GYRO_LPF_1ST_HZ_THROTTLE 0.25 // MAX reached at 1/4 throttle.

// #define GYRO_LPF_2ND_HZ_BASE 240 //* ( aux[ FN_INVERTED ] ? 0.75f : 1.0f )
// #define GYRO_LPF_2ND_HZ_MAX 240
// #define GYRO_LPF_2ND_HZ_THROTTLE 0.25

// Additional Gyro yaw first order LPF
//#define GYRO_YAW_LPF_1ST_HZ 60

// D-Term second order LPF (cannot be turned off)
#define DTERM_LPF_2ND_HZ_BASE 60 //* ( aux[ FN_INVERTED ] ? 0.75f : 1.0f )
#define DTERM_LPF_2ND_HZ_MAX 60
#define DTERM_LPF_2ND_HZ_THROTTLE 0.5

// Additional D-Term first order LPF
//#define DTERM_LPF_1ST_HZ 60

// Whether to use Bessel type filter for D-Term instead of PT2.
//#define DTERM_BESSEL_FILTER

// If enabled, the D-Term filter uses the filtered gyro signal from above. (Notch filters are always applied.)
//#define CASCADE_GYRO_AND_DTERM_FILTER

// Switch function selection
#define USE_MULTI
#define RATES MULTI_CHAN_8 // LOW_RATES_MULTI gets applied when RATES is 0.

#define LEVELMODE MULTI_CHAN_7 // Set this to CH_ON for level mode always on. Comment it out for just acro.

#define LEDS_ON MULTI_CHAN_9

// To stop the motors on ground a switch on the remote control is necessary.
#define THROTTLE_KILL_SWITCH MULTI_CHAN_10

// enable inverted (3D) flight code
// #define INVERTED_ENABLE // goes together with BIDIRECTIONAL in drv_dshot.c and drv_dshot_dma.c
#define FN_INVERTED MULTI_CHAN_9
// #define LEVEL_MODE_INVERTED_ENABLE // be careful when enabling this

// Two switchable channels via gestures: CH_AUX1 and CH_AUX2
// Channel CH_AUX1 changed via gestures LLU -> 1 and LLD -> 0
// Channel CH_AUX2 changed via gestures RRU -> 1 and RRD -> 0
// #define AUX1_START_ON // CH_AUX1 channel starts on if this is defined, otherwise off.
// #define AUX2_START_ON // CH_AUX2 channel starts on if this is defined, otherwise off.

// lost quad beeps using motors (60 sec timeout)
#define MOTOR_BEEPS
#define MOTOR_BEEPS_CHANNEL MULTI_CHAN_6

// Send maximum looptime in the telemetry data.
#define DISPLAY_MAX_USED_LOOP_TIME_INSTEAD_OF_RX_PACKETS
// Send PID values in the telemetry data.
#define DISPLAY_PID_VALUES

// Radio module and protocol selection (only Bayang protocol implemented)
// #define RX_NRF24_BAYANG_TELEMETRY // For nRF24L01+ radio module
#define RX_BAYANG_PROTOCOL_TELEMETRY // For XN297 radio module harvested from toy TX

#define RADIO_XN297 // also enable SOFTSPI_4WIRE in hardware.h
// #define RADIO_XN297L // also enable SOFTSPI_3WIRE in hardware.h

#define TX_POWER 3 // 0 .. 3 (try 1 when using an nRF24L01+PA+LNA module)

// led brightness 0 .. 15 (used for solid lights only)
#define LED_BRIGHTNESS 15

// Comment out to disable pid tuning gestures
#define PID_GESTURE_TUNING
#define COMBINE_PITCH_ROLL_PID_TUNING

// a filter which makes throttle feel faster (aka Throttle Boost) (not active in LOW_RATES or lowbatt)
#define THROTTLE_TRANSIENT_COMPENSATION_FACTOR 3.0

// For smoother motor reversing in 3D flight
#define THROTTLE_REVERSING_KICK 0.2f

// Continue stick movement with the current stick velocity in case of lost packets
#define RX_PREDICTOR
// Add linear interpolation between the otherwise 5 ms staircase steps of the RX signal
#define RX_SMOOTHING

// Betaflight like mix scaling (aka Airmode)
#define MIX_SCALING
// Mix increasing yields a more crisp response but also a more jumpy quad at low RPM
#define ALLOW_MIX_INCREASING
// A higher value means a shorter active increasing period (shorter bouncy period)
#define TRANSIENT_MIX_INCREASING_HZ 2.0

// Use a square root motor curve to counteract thrust ~ RPM^2
#define THRUST_LINEARIZATION 0.33f // 0.0f .. no compensation, 1.0f .. full square root curve

// A deadband can be used to eliminate stick center jitter and non-returning to exactly 0.
#define STICKS_DEADBAND 0.02f

// throttle direct to motors for thrust measure
// #define MOTORS_TO_THROTTLE

// throttle direct to motors for thrust measure as a flight mode
#define MOTORS_TO_THROTTLE_MODE CH_AUX1

// Compensate PID values for sagging battery voltage
#define PID_VOLTAGE_COMPENSATION

// Invert yaw pid. Necessary when spinning props outwards.
#define INVERT_YAW_PID

// Rotate I-term vector for a stable yaw axis (aka iTerm Rotation)
#define PID_ROTATE_ERRORS

// Removes roll and pitch bounce back after flips (aka iTerm Relax)
#define TRANSIENT_WINDUP_PROTECTION

// Feed fast roll/pitch-stick changes directly to the motors to give a snappier response
// 0.0f (or commented out) equates D-term on measurement, 1.0f equates D-term on error.
//#define FEED_FORWARD_STRENGTH 1.0f
//#define SMART_FF

// Loop time in us
#define LOOPTIME 125

// Failsafe time in us. Sets stick inputs to zero after FAILSAFETIME no RX signal. Keeps quad stabilized.
#define FAILSAFETIME 150000 // 0.15 seconds
// Motors failsafe time in us. Shuts motors down after additional MOTORS_FAILSAFETIME.
#define MOTORS_FAILSAFETIME 3000000 // 3 seconds

// Gyro orientation:
// The expected orientation is with the dot on the chip in the front-left corner.
// Specify by how much you have to rotate the board so that the dot is front left.
// The rotations are performed in order and cumulated.
// Note, the motors don't get rotated, so they have to be referenced to the new gyro position.
//#define SENSOR_ROTATE_45_CCW
//#define SENSOR_ROTATE_45_CW
#define SENSOR_ROTATE_90_CW
//#define SENSOR_ROTATE_90_CCW
//#define SENSOR_ROTATE_180
//#define SENSOR_INVERT // Necessary if the gyro is mounted upside down. For an inverted gyro,
// the expected orientation is with the dot on the chip in the front-right corner.

// Motor order
#define MOTOR_BL 3
#define MOTOR_FL 4
#define MOTOR_BR 2
#define MOTOR_FR 1

// Disable the check for known gyro that causes the 4 times LED flash.
#define GYRO_CHECK

// Disable the check for development without RX module (3 times LED flash).
#define RADIO_CHECK

// Logs various information to an externally connected OpenLager logger
//#define BLACKBOX_LOGGING
