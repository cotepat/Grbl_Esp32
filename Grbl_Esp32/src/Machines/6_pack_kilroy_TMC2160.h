#pragma once
// clang-format off

#define MACHINE_NAME            "Kilroy CNC - (RatRig KillerBee 1075)"
#define N_AXIS 3

// === Special Features

// I2S (steppers & other output-only pins)
#define USE_I2S_OUT
#define USE_I2S_STEPS
//#define DEFAULT_STEPPER ST_I2S_STATIC

//#define USE_STEPSTICK   // makes sure MS1,2,3 !reset and !sleep are set

#define I2S_OUT_BCK             GPIO_NUM_22
#define I2S_OUT_WS              GPIO_NUM_17
#define I2S_OUT_DATA            GPIO_NUM_21
#define STEPPER_RESET           GPIO_NUM_19
#define STEPPER_MS1             GPIO_NUM_23 // MOSI
#define STEPPER_MS2             GPIO_NUM_18 // SCK

// Motor Socket #1
#define X_DISABLE_PIN           I2SO(0)
#define X_DIRECTION_PIN         I2SO(1)
#define X_STEP_PIN              I2SO(2)

// Motor Socket #2
#define Y_DIRECTION_PIN         I2SO(4)
#define Y_STEP_PIN              I2SO(5)
#define Y_DISABLE_PIN           I2SO(7)

// Motor Socket #3
#define Y2_DIRECTION_PIN         I2SO(9)
#define Y2_STEP_PIN              I2SO(10)
#define Y2_DISABLE_PIN           I2SO(8)

// Motor Socket #4
#define Z_DIRECTION_PIN         I2SO(12)
#define Z_STEP_PIN              I2SO(13)
#define Z_DISABLE_PIN           I2SO(15)

/*
    Socket I/O reference
    The list of modules is here...
    https://github.com/bdring/6-Pack_CNC_Controller/wiki/CNC-I-O-Module-List
    Click on each module to get example for using the modules in the sockets
Socket #1
#1 GPIO_NUM_33 
#2 GPIO_NUM_32
#3 GPIO_NUM_35 (input only)
#4 GPIO_NUM_34 (input only)
Socket #2
#1 GPIO_NUM_2
#2 GPIO_NUM_25
#3 GPIO_NUM_39 (input only)
#4 GPIO_NUM_36 (input only)
Socket #3
#1 GPIO_NUM_26
#2 GPIO_NUM_4
#3 GPIO_NUM_16
#4 GPIO_NUM_27
Socket #4
#1 GPIO_NUM_14
#2 GPIO_NUM_13
#3 GPIO_NUM_15
#4 GPIO_NUM_12
Socket #5
#1 I2SO(24)  (output only)
#2 I2SO(25)  (output only)
#3 I2SO26)  (output only)
*/

// 4x Input Module in Socket #1
// https://github.com/bdring/6-Pack_CNC_Controller/wiki/4x-Switch-Input-module
#define X_LIMIT_PIN             GPIO_NUM_32
#define Y_LIMIT_PIN             GPIO_NUM_33
#define Y2_LIMIT_PIN            GPIO_NUM_35
#define Z_LIMIT_PIN             GPIO_NUM_34

#define DEFAULT_INVERT_LIMIT_PINS       0  // Sets the default for N.O. switches

// 4x Switch Input module  in socket #2
// // https://github.com/bdring/6-Pack_CNC_Controller/wiki/4x-Switch-Input-module
#define CONTROL_FEED_HOLD_PIN   GPIO_NUM_2   // labeled Hold
#define MACRO_BUTTON_0_PIN		GPIO_NUM_25
#define MACRO_BUTTON_1_PIN		GPIO_NUM_39
#define MACRO_BUTTON_2_PIN		GPIO_NUM_36

// 0-10V Outpur Module used in socket #3
// https://github.com/bdring/6-Pack_CNC_Controller/wiki/0-10V-Output-Module
#define SPINDLE_OUTPUT_PIN      GPIO_NUM_26

// Other inputs (Wired directly... No module)
#define PROBE_PIN                   GPIO_NUM_13
#define CONTROL_RESET_PIN           GPIO_NUM_15  // labeled Stop
#define CONTROL_CYCLE_START_PIN     GPIO_NUM_12  // labeled Start

// ======== DEFAULT SETTINGS ============
#    define DEFAULT_STEP_PULSE_MICROSECONDS 5  // $0
#    define DEFAULT_STEPPER_IDLE_LOCK_TIME  255 // $1 msec (0-254, 255 keeps steppers enabled)
#    define DEFAULT_DIRECTION_INVERT_MASK   2  // $3 uint8_
#    define DEFAULT_INVERT_LIMIT_PINS       0  // $5 boolean
#    define DEFAULT_INVERT_PROBE_PIN        1  // $6 boolean
#    define DEFAULT_STATUS_REPORT_MASK      3  // $10
#    define DEFAULT_SOFT_LIMIT_ENABLE       0  // $20
#    define DEFAULT_HARD_LIMIT_ENABLE       1  // $21
#    define DEFAULT_HOMING_ENABLE           1  // $22
#    define DEFAULT_HOMING_DIR_MASK         0  // $23 move positive dir Z, negative X,Y
#    define DEFAULT_HOMING_FEED_RATE        100.0  // $24 mm/min
#    define DEFAULT_HOMING_SEEK_RATE        2000.0  // $25 mm/min
#    define DEFAULT_HOMING_DEBOUNCE_DELAY   350  // $26 msec (0-65k)
#    define DEFAULT_HOMING_PULLOFF          2.0  // $27 mm
#    define DEFAULT_HOMING_SQUARED_AXES     bit(Y_AXIS)
#    define DEFAULT_HOMING_CYCLE_0          bit(Z_AXIS)
#    define DEFAULT_HOMING_CYCLE_1          bit(X_AXIS)
#    define DEFAULT_HOMING_CYCLE_2          bit(Y_AXIS)

// ========== SPINDLE STUFF ====================
#    define SPINDLE_TYPE SpindleType::_10V
#    define DEFAULT_SPINDLE_RPM_MIN 3500.0  // $31 rpm
#    define DEFAULT_SPINDLE_RPM_MAX 25000.0  // $30 rpm
#    define DEFAULT_SPINDLE_MIN_VALUE 0.0  // $35 Percent of full period (extended set)
#    define DEFAULT_SPINDLE_MAX_VALUE 90.0  // $36 Percent of full period (extended set)
#    define DEFAULT_SPINDLE_DELAY_SPINUP 1
#    define DEFAULT_SPINDLE_DELAY_SPINDOWN 1
#    define DEFAULT_SPINDLE_ENABLE_OFF_WITH_ZERO_SPEED 1

// =========== 	AXIS RESOLUTION =========
#    define DEFAULT_X_STEPS_PER_MM 400.35 
#    define DEFAULT_Y_STEPS_PER_MM 400
#    define DEFAULT_Z_STEPS_PER_MM 400

// ============ AXIS MAX SPEED =========
#    define DEFAULT_X_MAX_RATE		7000
#    define DEFAULT_Y_MAX_RATE		6000
#    define DEFAULT_Z_MAX_RATE		4000

// ============ AXIS ACCELERATION ======
#    define DEFAULT_X_ACCELERATION 	400
#    define DEFAULT_Y_ACCELERATION 	400
#    define DEFAULT_Z_ACCELERATION 	400

// ========= AXIS MAX TRAVEL ============
#    define DEFAULT_X_MAX_TRAVEL 	531
#    define DEFAULT_Y_MAX_TRAVEL 	786
#    define DEFAULT_Z_MAX_TRAVEL 	100
#    define DEFAULT_X_HOMING_MPOS   2.0
#    define DEFAULT_Y_HOMING_MPOS   2.0
#    define DEFAULT_Z_HOMING_MPOS   2.0

// ================ User Analog I/O ==============================
#    define DEFAULT_USER_MACRO0 "$H"
#    define DEFAULT_USER_MACRO1 ""
#    define DEFAULT_USER_MACRO2 ""
#    define DEFAULT_USER_MACRO3 "$MD"

// ================ MISCELANEOUS =================================
#ifdef INVERT_CONTROL_PIN_MASK
    #undef INVERT_CONTROL_PIN_MASK
    #define INVERT_CONTROL_PIN_MASK B00001000
#endif

#undef HOMING_INIT_LOCK

#define LIMITS_TWO_SWITCHES_ON_AXES 1
