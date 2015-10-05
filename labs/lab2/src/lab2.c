/**
 * @file  lab2.c
 * @brief Starter code for lab 2.
 * 
 * @details Modify this file to implement the power meter
 * for lab 2
 * 
 * @author Ned Danyliw
 * @date  09.2015
 */

#include "lab2.h"


// calibration parameters
float volts_per_div;
float amps_per_div;

bool v_cal_already;
bool c_cal_already;
bool reaches_callback = 1;

uint16_t zero_volts;
uint16_t zero_amps;

//current readings
__IO uint16_t voltage_reading;
__IO uint16_t current_reading;


/**
 * @brief Calibrate out the 0V and 0A offsets
 * @details Reads the ADC value at 0V and 0A and records
 * their offsets in the EEPROM
 */
void calibrate_offset() {
  zero_volts = voltage_reading;
  zero_amps = current_reading;

  //Store values in EEPROM
}


/**
 * @brief Updates calibration for the standard voltage
 * @details Calculates the calibration value read from the ADC
 * and stores the result in the EEPROM
 */
void calibrate_voltage() {

  //ideally 
  //Code to calculate volts_per_div
  //we have the information that 0V maps to some ADC value
  //we read that 10V (or some known value) maps to some other ADC value
  //calculate slope
  //Store values in EEPROM

  v_cal_already = true;
}


/**
 * @brief Updates calibration for the standard current
 * @details Calculates the calibration value read from the ADC
 * and stores the result in the EEPROM
 */
void calibrate_current() {
  //Code to calculate amps_per_div
  //ideally 
  //we have the information that 0V maps to some ADC value
  //we read that 3A (or some known value) maps to some other ADC value
  //calculate slope
  //Store values in EEPROM

  c_cal_already = true;
}


/**
 * @brief Initialize the energy meter
 * @details Reads the calibration values from the EEPROM
 */
void meter_init() {
  c_cal_already = false;
  v_cal_already = false;
  //Read in calibration constants from EEPROM

  //This'll be empty until Ned sets this up
  
}


/**
 * @brief Displays energy meter data
 * @details Replace with code to update the display with
 * your own
 */
void meter_display() {

  if(!v_cal_already) {
    //use defaults
    volts_per_div = 120/4096;

  }

  if(!c_cal_already) {
    amps_per_div = 20/4096;
  }

  float measured_voltage = volts_per_div * voltage_reading;
  float measured_current = amps_per_div * current_reading;
  float measured_power = measured_current * measured_voltage;

  //throw on the LCD
  
  char v_string[15];
  char c_string[15];
  char p_string[15];
  char test[1];

  if (reaches_callback == 1){
    test[0] = 'y';
  }
  else{
    test[0] = 'n';
  }

  sprintf(v_string, "Voltage: %.3f", measured_voltage);
  sprintf(c_string, "Current: %.3f", measured_current);
  sprintf(p_string, "Power: %.3f",measured_power);

  lcd_goto(0,0);
  lcd_puts(v_string);

  lcd_goto(0,1);
  lcd_puts(c_string);

  lcd_goto(0,2);
  lcd_puts(p_string);

  lcd_goto(0,3);
  lcd_puts(test);
}


/**
 * @brief Callback at end of ADC conversion
 * @details Called at the end of the ADC conversions
 */
void my_adc_callback(uint32_t data) {
  voltage_reading = (uint16_t) (data & 0x0000ffff); //some number between 0 and 4095
  current_reading = (uint16_t) (data >> 16); //some # 0-4095
  reaches_callback = !reaches_callback;
}
