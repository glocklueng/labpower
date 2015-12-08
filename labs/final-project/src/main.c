/**
*Seeing if motor works
 */

#include "output_handler.h"

int sample1 = 0;
int sample2 = 666;
int sample3 = 1332;

int increment = 12;
float df_1 = .50;
float df_2 = .85;
float df_3 = .15;


void change_df() {
  sample1 += increment;
  sample2 += increment;
  sample3 += increment;

  int index1 = sample1 % NUM_SAMPLES;
  int index2 = sample2 % NUM_SAMPLES;
  int index3 = sample3 % NUM_SAMPLES;

  df_1 = .5 + get_duty_cycle(index1)/(2.0/0.8);
  df_2 = .5 + get_duty_cycle(index2)/(2.0/0.8);
  df_3 = .5 + get_duty_cycle(index3)/(2.0/0.8);
}

int main() {

  //set up a timer
  timer_init();
  timer_id_t sine_timer = timer_register(1, &change_df, GE_PERIODIC);
  timer_set_period(7200);
  timer_start(sine_timer);

  //set up PWM
  pwm_init();
  pwm_enable_chan(2);
  pwm_enable_chan(3);
  pwm_enable_chan(1);
  pwm_freq(20000); //original was 100000



  while(1) {
    pwm_set(2, df_1); // initial value for duty factor
    pwm_set(3, df_2);
    pwm_set(1, df_3);
  }


  return 0;
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
