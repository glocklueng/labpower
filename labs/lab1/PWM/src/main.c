/**
 * @file  main.c
 * @brief Hello World demo for the Green Electronics libraries.
 * 
 * @details Prints "Hello World" on the LCD and blinks the onboard
 * LEDs
 * 
 * @author Ned Danyliw
 * @date  09.2015
 */
#include "ge_libs.h"

#define PWM_FREQUENCY 5.0
#define FREQ_UP GE_PBTN3
#define FREQ_DN GE_PBTN2

float duty = .5;


void setup_led_gpio() {
  //Initialize LED pins and set as outputs
  gpio_setup_pin(DISC_LD3, GPIO_OUTPUT, false, false);
  gpio_setup_pin(DISC_LD4, GPIO_OUTPUT, false, false);
  gpio_setup_pin(DISC_LD5, GPIO_OUTPUT, false, false);
  gpio_setup_pin(DISC_LD6, GPIO_OUTPUT, false, false);
  gpio_setup_pin(DISC_LD7, GPIO_OUTPUT, false, false);
  gpio_setup_pin(DISC_LD8, GPIO_OUTPUT, false, false);
  gpio_setup_pin(DISC_LD9, GPIO_OUTPUT, false, false);
  gpio_setup_pin(DISC_LD10, GPIO_OUTPUT, false, false);
}

void led_off() {
  gpio_write_pin(DISC_LD3, GPIO_LOW);
  gpio_write_pin(DISC_LD4, GPIO_LOW);
  gpio_write_pin(DISC_LD5, GPIO_LOW);
  gpio_write_pin(DISC_LD6, GPIO_LOW);
  gpio_write_pin(DISC_LD7, GPIO_LOW);
  gpio_write_pin(DISC_LD8, GPIO_LOW);
  gpio_write_pin(DISC_LD9, GPIO_LOW);
  gpio_write_pin(DISC_LD10, GPIO_LOW);
}

void led_on() {
  gpio_write_pin(DISC_LD3, GPIO_HIGH);
  gpio_write_pin(DISC_LD4, GPIO_HIGH);
  gpio_write_pin(DISC_LD5, GPIO_HIGH);
  gpio_write_pin(DISC_LD6, GPIO_HIGH);
  gpio_write_pin(DISC_LD7, GPIO_HIGH);
  gpio_write_pin(DISC_LD8, GPIO_HIGH);
  gpio_write_pin(DISC_LD9, GPIO_HIGH);
  gpio_write_pin(DISC_LD10, GPIO_HIGH);
}

void button_logic(void){
  uint8_t increase_freq = gpio_read_pin(FREQ_UP);
  uint8_t decrease_freq = gpio_read_pin(FREQ_DN);

  if(increase_freq == 0 && duty <= .95){
    duty += .05;
  }
  else if(decrease_freq == 0 && duty >= .05){
    duty -= .05;
  }
  else{

  }



}


/**
  * @brief  Main program.
  * @param  None 
  * @retval None
  */
int main(void)
{  
  //Initialize library
  ge_init();

  //Initialize GPIO
  gpio_init();

  setup_led_gpio();

  //Initialize the USER button as an input
  gpio_setup_pin(DISC_PBTN, GPIO_INPUT, false, false);
  gpio_setup_pin(FREQ_UP, GPIO_INPUT, false, false); //start
  gpio_setup_pin(FREQ_DN, GPIO_INPUT, false, false); //stop

  //Initialize LCD
  lcd_init();

  // //Print Hello World
  lcd_clear();
  lcd_goto(0, 0);
  lcd_puts("PWM");

  pwm_init();
  pwm_enable_chan(1);
  pwm_freq(PWM_FREQUENCY);
  pwm_set(1, duty);

  timer_init();
  timer_id_t button_timer = timer_register(1, &button_logic, GE_PERIODIC);
  timer_start(button_timer);
  


  // timer_init();

  //Initialize VCOM
  // vcom_init();
  // vcom_send("Hello, World!\n");

  /* Infinite loop */
  /**
   * Flashes the ring of LEDs. If the user button is
   * depressed, it will switch to pulsing the buttons with
   * PWM.
   */
  while (1) {
      //lcd_clear();  
      lcd_goto(0, 0);
      char disp[9];
      sprintf(disp, "Duty: .%02f", duty);
      lcd_puts(disp); 
      pwm_set(1, duty);
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
