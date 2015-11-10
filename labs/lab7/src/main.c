/**
 * @file  main.c
 * @brief Power supply controller
 * 
 * @details Regulates a 5V supply
 * 
 * @author Team SCV
 * @date  10.2015
 */

#include "ge_libs.h"
#include "motor_controller.h"


float setpoint;
float step_setpoint; //another button to be used to jump the setpoint immediately to this value
float dset; // step size for the setpoint
float current_vol;

float old_err;
float old_err_int;


int main(void) {  
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
  pwm_freq(100000);



  char voltage_display[20];
  char setpoint_display[20];
  char update[20];


  dset = .1;

   while (1) {

    //clear update
    sprintf(update,"                    ");

    sprintf(voltage_display, "w: %.3f rad/s   ", current_vol);
    sprintf(setpoint_display, "SP: %.3f rad/s   ", setpoint);

    if(!gpio_read_pin(GE_PBTN1)) {
      setpoint += dset;

      if(setpoint > MAX_SETPOINT) {
        setpoint = MAX_SETPOINT;
        sprintf(update, "SP at max");
      } else {
        sprintf(update, "Upped SP by 1.0");
        change_err_der(0.0);
        change_err_int(0.0);
      }
    }


    if(!gpio_read_pin(GE_PBTN2)) {
      setpoint -= dset;
      if(setpoint < 0.0) {
        setpoint = 0.0;
        sprintf(update, "Setpoint at min");
      }
      else {
        sprintf(update, "Downed SP by 1.0");
        change_err_der(0.0);
        change_err_int(0.0);
      }
    }

    if(!gpio_read_pin(GE_PBTN3)) {
      setpoint = MAX_SETPOINT;
      sprintf(update, "Stepped to max val");
      change_err_der(0.0);
      change_err_int(0.0);
    }

    if(!gpio_read_pin(GE_PBTN4)) {
      setpoint = 0.0;
      sprintf(update, "Stepped down to 0.0");
      change_err_der(0.0);
      change_err_int(0.0);
    }
    
    lcd_goto(0,2);
    lcd_puts(speed_display);
    lcd_goto(0,3);
    lcd_puts(setpoint_display);
    lcd_goto(0,0);
    lcd_puts(update);

    float PWM_factor = supply_controller(current_voltage, setpoint);
    pwm_set(1,1.0-PWM_factor);
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
