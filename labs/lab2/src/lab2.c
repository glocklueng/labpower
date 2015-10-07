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
float prev_volt;
float prev_curr;

//enemies, got alotta enemies
//got alotta people tryna drain me of this energy
float energy;

uint16_t zero_volts;
uint16_t zero_amps;

uint16_t cal_volt_reading;
uint16_t cal_curr_reading;
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

  eeprom_write(ZERO_V_ADDR, zero_volts);
  eeprom_write(ZERO_I_ADDR, zero_amps);
}


/**
 * @brief Updates calibration for the standard voltage
 * @details Calculates the calibration value read from the ADC
 * and stores the result in the EEPROM
 */
void calibrate_voltage() {

  cal_volt_reading = voltage_reading;
  eeprom_write(CAL_VOLT_ADDR, cal_volt_reading);

  float delta_voltage = CAL_VOLTS;
  uint16_t divisions = cal_volt_reading - zero_volts;

  volts_per_div = delta_voltage/(float) divisions;
}

/**
 * @brief Updates calibration for the standard current
 * @details Calculates the calibration value read from the ADC
 * and stores the result in the EEPROM
 */
void calibrate_current() {

  cal_curr_reading = current_reading;
  eeprom_write(CAL_CURR_ADDR, cal_curr_reading);

  float delta_current = CAL_CURR;
  uint16_t divisions = cal_curr_reading - zero_amps;

  amps_per_div = delta_current/ (float) divisions;
}


/**
 * @brief Initialize the energy meter
 * @details Reads the calibration values from the EEPROM
 */
void meter_init() {

  //use defaults initially
  //these bools get set true in the calibrate functions
  eeprom_init();

  energy = 0;

  prev_volt = 0.0;
  prev_curr = 0.0;
  
  eeprom_read(ZERO_V_ADDR, &zero_volts);
  eeprom_read(ZERO_I_ADDR, &zero_amps);

  eeprom_read(CAL_VOLT_ADDR, &cal_volt_reading);
  eeprom_read(CAL_CURR_ADDR, &cal_curr_reading);

  volts_per_div = CAL_VOLTS/ ( (float) (cal_volt_reading - zero_volts));
  amps_per_div = CAL_CURR/ ( (float) (cal_curr_reading - zero_amps));
}


/**
 * @brief Displays energy meter data
 * @details Replace with code to update the display with
 * your own
 */
void meter_display() {

  /*float measured_voltage = volts_per_div * (voltage_reading-zero_volts);
  float measured_current = amps_per_div * (current_reading-zero_amps);
  float measured_power = measured_current * measured_voltage;*/

  //filtering (might need to do something with the normalization if it doesnt work)
  float measured_voltage = (alpha*prev_volt + beta*(volts_per_div*(voltage_reading-zero_volts)))*(.25);
  float measured_current = (alpha*prev_curr + beta*(amps_per_div*(current_reading-zero_amps)))*(.25);
  float measured_power = measured_current * measured_voltage;
  energy += power*PRD;

  //produce unity gain
  prev_volt = measured_voltage;
  prev_curr = measured_current;
  

  //throw on the LCD
  
  char v_string[20];
  char c_string[20];
  char p_string[20];
  char e_string[20];

  sprintf(v_string, "Voltage: %.3f V ", measured_voltage);
  sprintf(c_string, "Current: %.3f A ", measured_current);
  sprintf(p_string, "Power: %.3f W ", measured_power);
  sprintf(e_string, "Energy: %.3f J ", energy);

  lcd_goto(0,0);
  lcd_puts(v_string);

  lcd_goto(0,1);
  lcd_puts(c_string);

  lcd_goto(0,2);
  lcd_puts(p_string);

  lcd_goto(0,3);
  lcd_puts(e_string);
}


/**
 * @brief Callback at end of ADC conversion
 * @details Called at the end of the ADC conversions
 */
void my_adc_callback(uint32_t data) {
  voltage_reading = (uint16_t) (data & 0x0000ffff); //some number between 0 and 4095
  current_reading = (uint16_t) (data >> 16); //some # 0-4095
}
