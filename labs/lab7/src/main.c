/*
 * @file  main.c
 * @brief Power supply controller
 * 
 * @details Regulates a 5V supply
 * 
 * @author Team SCV
 * @date  10.2015
 */

#include "ge_libs.h"
#include "supply_controller.h"


#define VAL(x) #x
#define STR(x) VAL(x)

#define SETPOINT 5.0
#define FREQ 20000
#define CAL_VOLTS 5.0

//Addresses for data - eeprom
#define ZERO_V_ADDR 2
#define ZERO_I_ADDR 6
#define CAL_VOLT_ADDR 10
#define CAL_CURR_ADDR 14

uint16_t zero_volts;
uint16_t cal_volt_reading;
float actual_div_ratio;
float PWM_factor;

float measured_voltage;
uint16_t voltage_reading;

//Define operating states
enum DISP_STATES {DISP_MAIN, DISP_OFF, DISP_CALV};

uint8_t state = DISP_MAIN;
bool btn_pressed = false;

void change_state() {
  if (gpio_read_pin(GE_PBTN1)) {
    if (!btn_pressed) {
      state++;
      if (state > DISP_CALV) state = DISP_MAIN;
    }
    btn_pressed = true;
  } else {
    btn_pressed = false;
  }
}


void calibrate_offset() {
  zero_volts = voltage_reading;
  eeprom_write(ZERO_V_ADDR, zero_volts);

  actual_div_ratio = CAL_VOLTS/(cal_volt_reading - zero_volts);  
}


/**
 * @brief Updates calibration for the standard voltage
 * @details Calculates the calibration value read from the ADC
 * and stores the result in the EEPROM
 */
void calibrate_voltage() {

  cal_volt_reading = voltage_reading;
  eeprom_write(CAL_VOLT_ADDR, cal_volt_reading);

  actual_div_ratio = CAL_VOLTS/(cal_volt_reading - zero_volts);
}

/**
 * @brief Initialize the energy meter
 * @details Reads the calibration values from the EEPROM
 */
void meter_init() {

  //use defaults initially
  //these bools get set true in the calibrate functions
  eeprom_init();
  
  eeprom_read(ZERO_V_ADDR, &zero_volts);
  eeprom_read(CAL_VOLT_ADDR, &cal_volt_reading);

  actual_div_ratio = CAL_VOLTS/(cal_volt_reading - zero_volts);
}

/**
 * @brief Displays energy meter data
 * @details Replace with code to update the display with
 * your own
 */
void meter_display() {
  char v_string[20];
  char adc_string[20];
  char pwm_fac[20];
  sprintf(pwm_fac, "       PWM: %.3f", PWM_factor);
  sprintf(adc_string, " ADC: %d ", voltage_reading);
  sprintf(v_string, "Voltage: %.3f V ", measured_voltage); //hope this is close to 5V

    lcd_goto(0,1);
  lcd_puts(pwm_fac);

  lcd_goto(0,2);
  lcd_puts(v_string);

  lcd_goto(0,3);
  lcd_puts(adc_string);
}

/**
 * @brief Callback at end of ADC conversion
 * @details Called at the end of the ADC conversions
 */
void my_adc_callback(uint32_t data) {
  voltage_reading = (uint16_t) (data & 0x0000ffff); //some number between 0 and 4095
  measured_voltage = actual_div_ratio*(voltage_reading-zero_volts);

  PWM_factor = supply_controller(measured_voltage, SETPOINT);
  pwm_set(1,PWM_factor);
  //pwm_set(1, 0.5);
}


int main(void) {  

  timer_init();
  timer_id_t state_tim = timer_register(50, &change_state, GE_PERIODIC);
  timer_start(state_tim);

  //initialize power meter
  meter_init();
  //Initialize library
    ge_init();

  //Initialize GPIO
    gpio_init();

  //Initialize LCD
    lcd_init();

  //Initialize the USER button as an input
  gpio_setup_pin(DISC_PBTN, GPIO_INPUT, false, false);
  gpio_setup_pin(GE_PBTN1, GPIO_INPUT, false, false); // raise the setpoint button
  gpio_setup_pin(GE_PBTN2, GPIO_INPUT, false, false); // lower the setpoint button
  gpio_setup_pin(GE_PBTN3, GPIO_INPUT, false, false); // go to max
  gpio_setup_pin(GE_PBTN4, GPIO_INPUT, false, false); // down to 0 

  //Initialize PWM pin
  pwm_init();
  pwm_enable_chan(1);
  pwm_freq(100000); //original was 100000

  //Initialize ADC
  adc_init();
  adc_set_fs(FREQ);  //adjust this 
  adc_enable_channel(3);
  adc_callback(3, &my_adc_callback);
  adc_start();


  char voltage_display[20];
  char setpoint_display[20];
  char update[20];

  uint8_t last_state = 255;
  while (1) {

    if (state != last_state) {
      lcd_clear();
      last_state = state;
    }

    switch(state) {
      case DISP_MAIN:
        meter_display();
        break;
      case DISP_OFF:
        lcd_goto(0, 0);
        lcd_puts("Calibration: offsets");
        lcd_goto(0, 2);
        lcd_puts("Apply 0V");
        lcd_goto(0, 3);
        lcd_puts("2 - OK");

        if (!gpio_read_pin(GE_PBTN2)) {
          calibrate_offset();
          lcd_goto(0, 3);
          lcd_puts("Stored");
        }
        break;
      case DISP_CALV:
        lcd_goto(0, 0);
        lcd_puts("Calibration: voltage");
        lcd_goto(0, 2);
        lcd_puts("Apply " STR(CAL_VOLTS) "V");
        lcd_goto(0, 3);
        lcd_puts("2 - OK");

        if (!gpio_read_pin(GE_PBTN2)) {
          calibrate_voltage();
          lcd_goto(0, 3);
          lcd_puts("Stored");
        }
        break;
      
      default:
        state = DISP_MAIN;
        break;
    }
  delay_ms(5);  
  }

}



#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
  void assert_failed(uint8_t* file, uint32_t line)
  { 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
    while (1)
    {
    }
  }
#endif
