/**
 * @file  main.c
 * @brief Starter code for Lab 5
 * 
 * @details Measures the frequency of the signal on PD12 and prints it
 * to the LCD
 * 
 * @date  10.2015
 */
#include "ge_libs.h"
#include "motor_controller.h"

#define MAX_SETPOINT 150.0 //CHANGE LATER


// UI Variables
float setpoint;
float step_setpoint; //another button to be used to jump the setpoint immediately to this value
float dset; // step size for the setpoint
float current_speed;

float old_err;
float old_err_int;



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
  pwm_init();
  pwm_enable_chan(1);
  pwm_freq(100000);

  // timer_init();
  // timer_id_t print_tim = timer_register(50, &print_to_screen, GE_PERIODIC);
  // timer_start(print_tim);

  //initialize ic
  ic_init();


  // enable pin PD12 as an input capture with a minimum frequency
  // of 1 Hz
  ic_enable_pin(PD14, 1.0);


  setpoint = 30.0;
   step_setpoint = 25.0; //another button to be used to jump the setpoint immediately to this value
   dset = 5.0; // step size for the setpoint
   current_speed = 0.0;

   old_err = 0.0;
   old_err_int = 0.0;

    char speed_display[20];
    char setpoint_display[20];
    char update[20];


   while (1) {

    //clear update
    sprintf(update,"                    ");


    // float good_values[20] = {0.0};
    // float sum = 0.0;
    // float avg = 0.0;
    // int counter = 0;
    // int i;
    // for (i=0; i<20; i++) {

    //     if(counter > 50) break;

    //     float sample = .5*ic_read_freq(PD14);
    //     if(sample > 2.0*MAX_SETPOINT) {
    //       i--;
    //     } else {
    //       good_values[i] = sample;
    //       sum+=sample;
    //       delay_ms(1);
    //     }
    //     counter++;
    // }

    // if(i==0) i=1;
    // avg = sum/((float) i);

    // sum = 0.0;
    // for(int j=0; j<20; j++) {
    //   if(good_values[j] > avg*1.15 || good_values[j] < .85*avg) good_values[j] = avg;

    //   sum += good_values[j];
    // }


    // // for (int i = 0; i<10; i++){
      
    // //   if(counter>100) break;

    // //   float sample = .5*ic_read_freq(PD14);
    // //   float curr_avg = sum/ ((float)i);

    // //   // if(sample < .5*curr_avg) {
    // //   //   i--;
    // //   // } else if (sample > 1.5*curr_avg) {
    // //   //   i--;
    // //   // } else {
    // //   //   sum += sample;
    // //   // }

    // //   if(sample > 2.0*MAX_SETPOINT) {
    // //     i--;
    // //   } else {
    // //     sum += sample;
    // //   }
    // //   counter++;
    // //   delay_ms(5);

    // // }


    // current_speed = sum/20.0;

  current_speed = 3.14*ic_read_freq(PD14);


    sprintf(speed_display, "w: %.3f rad/s   ", current_speed);
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
      // setpoint = MAX_SETPOINT;
      // sprintf(update, "Stepped to max val");
      // change_err_der(0.0);
      // change_err_int(0.0);
      pwm_set(1, .3);
      delay_ms(20);
    }

    if(!gpio_read_pin(GE_PBTN4)) {
      setpoint = 0.0;
      sprintf(update, "Stepped down to 0.0");
      change_err_der(0.0);
      change_err_int(0.0);
    }


    float PWM_factor = motor_controller(current_speed, setpoint);
    pwm_set(1,PWM_factor);
    char df[20];
    sprintf(df, "      df: %.3f", PWM_factor);

    
    lcd_goto(0,2);
    lcd_puts(speed_display);
    lcd_goto(0,3);
    lcd_puts(setpoint_display);
    lcd_goto(0,0);
     lcd_puts(df);

    // for (int i=0; i < 1000; i+=5) {
    //   float duty = ((float)i)/1000.0;
    //   pwm_set(1, duty);
    //   delay_ms(250);
    // }

    //pwm_set(1,.8);

    delay_ms(10);
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
