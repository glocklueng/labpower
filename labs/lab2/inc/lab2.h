/**
 * @file  lab2.h
 * @brief Lab 2 starter code.
 * 
 * @author Ned Danyliw
 * @date  09.2015
 */

#include "ge_libs.h"

//Calibration Voltage in volts (Adjust to your values)
#define CAL_VOLTS 10.0
#define CAL_CURR  3.0

//Default values for ranges of voltage and current readings
#define DEFAULT_V_RANGE 120.0
#define DEFAULT_I_RANGE 20.0
#define NUM_DIV 4096.0
#define FREQ 5000.0
#define PRD 0.0002

//Addresses for data - eeprom
#define ZERO_V_ADDR 2
#define ZERO_I_ADDR 6
#define CAL_VOLT_ADDR 10
#define CAL_CURR_ADDR 14

#define alpha .75
#define beta 1.0

//Initialize the energy meter
void meter_init();

//Display energy meter data
void meter_display();

//Update calibration for 0V and 0A
void calibrate_offset();

//Update calibration for the standard voltage
void calibrate_voltage();

//Update calibration for the standard current
void calibrate_current();

//ADC callback function
void my_adc_callback(uint32_t data);