/**
 * @file  main.c
 * @brief Starter code for Lab 5
 * 
 * @details Measures the frequency of the signal on PD12 and prints it
 * to the LCD
 * 
 * @author Ned Danyliw
 * @date  10.2015
 */
#include "ge_libs.h"
#include "motor_controller.h"

#define MAX_SETPOINT 100.0 //CHANGE LATER


// UI Variables
 float user_setpoint = 0.0;
float step_setpoint = 25.0; //another button to be used to jump the setpoint immediately to this value
float dset = 1.0; // step size for the setpoint
float current_speed = 0;

float old_err = 0.0
float old_err_int = 0.0

/**
  * @brief  Main program.
  * @param  None 
  * @retval None
  */
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

  //Initialize button inputs


  //initialize ic
  ic_init();


  // enable pin PD12 as an input capture with a minimum frequency
  // of 1 Hz
  ic_enable_pin(PD12, 1.0);


  /* Infinite loop */
  /**
   * Flashes the ring of LEDs. If the user button is
   * depressed, it will switch to pulsing the buttons with
   * PWM.
   */
   char speed_display[20];
   char setpoint_display[20];
   char update[20];
   while (1) {

    //clear update
    sprintf(update,"                    ");
    current_speed = .5*ic_read_freq(PD12);

    sprintf(speed_display, "Current speed: %.3f rad/s", current_speed);
    sprintf(setpoint_display, "Setpoint is at: %.3f rad/s", user_setpoint);

    if(!gpio_read_pin(GE_PBTN1)) {
      setpoint += dset;

      if(setpoint > MAX_SETPOINT) {
        setpoint = MAX_SETPOINT;
        sprintf(update, "Setpoint at maximum");
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
        sprintf(update, "Setpoint at minimum");
      }
      else {
        sprintf(update, "Downed SP by 1.0");
        change_err_der(0.0);
        change_err_int(0.0);
      }
    }

    if(!gpio_read_pin(GE_PBTN3)) {
      setpoint = MAX_SETPOINT;
      sprintf(update, "Stepped to max value!");
      change_err_der(0.0);
      change_err_int(0.0);
    }

    if(!gpio_read_pin(GE_PBTN4)) {
      setpoint = 0.0;
      sprintf(update, "Stepped down to 0.0");
      change_err_der(0.0);
      change_err_int(0.0);
    }

    lcd_goto(0,0);
    lcd_puts(speed_display);
    lcd_goto(0,1);
    lcd_puts(setpoint_display);
    lcd_goto(0,3);
    lcd_puts(update);
    
    float PWM_factor = motor_controller(current_speed, setpoint);
    pwm_set(1,PWM_factor);


    delay_ms(200);

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
