/**
 * @file  lab3.c
 * @brief Starter code for lab 3.
 * 
 * @details Modify this file to implement the power meter
 * for lab 3
 * 
 * @author Ned Danyliw
 * @date  09.2015
 */

#include "lab3.h"
#include "ge_libs.h"


// calibration parameters
float volts_per_div;
float amps_per_div;
float prev_volt;
float prev_curr;

//values that we need for maxppt
float init_df = 0.3;
float old_df;
float df = 0.0;
float ddf = 0.05;
float switch_period = .00001; //100 kHz switch freq for adc
float measured_power;
float samp_power;
float old_power2;
int randomizer = 0; //used so that we
int indexer = 0;
float pre_duty[8] = {0.65, 0.1, 0.3, 0.45, 0.25, 0.5, 0.15, 0.35};

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
  //gpio_write_pin(PC12, GPIO_HIGH);
  /*float measured_voltage = volts_per_div * (voltage_reading-zero_volts);
  float measured_current = amps_per_div * (current_reading-zero_amps);
  float measured_power = measured_current * measured_voltage;*/

  //filtering (might need to do something with the normalization if it doesnt work)
  //float measured_voltage = (prev_volt*.75 + (.25*volts_per_div*(voltage_reading-zero_volts)));
  //float measured_current = (prev_curr*.75 + (.25*amps_per_div*(current_reading-zero_amps)));
  
  //float measured_voltage = volts_per_div*(voltage_reading-zero_volts);
  //float measured_current = amps_per_div*(current_reading-zero_amps);
  
  //measured_power = measured_current * measured_voltage;
  //energy += measured_power*(.333333333333); 

  //produce unity gain
  //prev_volt = measured_voltage;
  //prev_curr = measured_current;
  

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
  gpio_write_pin(PC12, GPIO_LOW);
}


/**
 * @brief Callback at end of ADC conversion
 * @details Called at the end of the ADC conversions
 */
void my_adc_callback(uint32_t data) {
  voltage_reading = (uint16_t) (data & 0x0000ffff); //some number between 0 and 4095
  current_reading = (uint16_t) (data >> 16); //some # 0-4095
  float measured_voltage = (prev_volt*.75 + (.25*volts_per_div*(voltage_reading-zero_volts)));
  float measured_current = (prev_curr*.75 + (.25*amps_per_div*(current_reading-zero_amps)));

  measured_power = measured_current * measured_voltage;
  energy += measured_power*(.0002); 

  //produce unity gain
  prev_volt = measured_voltage;
  prev_curr = measured_current;
}

/**
 * @brief Calculates gate drive for max power point
 * @details From the current power point, searches for a new max power point
 * by changing the duty cycle
 */
 void max_ppt() {
  // Optimization algorithm
  // for hill-climbing, compare current power to previous power
  // take a step in the same direction if current power is better or vice versa
  // if you reverse direction, take smaller steps
  // if you go the same direction a couple times, take a bigger step
  // every once in a while, seed another random location
  // if you settle into another maximum that's worse than the previous max, revert

  // or do simulated annealing, idk
  
  // Calculate new duty cycle

  // set PWM for driver pins

  //run_until_stable, so we can say after like 8 milliseconds, taken care of by timer
  samp_power = measured_power;

  if (samp_power > old_power2) {
    old_power2 = samp_power;
    old_df = df;
  } else {
    df = old_df;
    ddf = -ddf;
  }

  df = df + ddf;
  if (randomizer == 1250) {

    //every 2 seconds the duty factor jumps to a random point to make sure not in local max
    df = pre_duty[indexer];
    indexer = indexer+1;
    if (indexer > 8) {
      indexer = 0;
    }
    
  }

  pwm_set(1, df);                  
}