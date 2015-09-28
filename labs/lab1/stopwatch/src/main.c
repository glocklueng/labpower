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
#include "common.h"

#define START GE_PBTN4
#define STOP GE_PBTN3
#define RESET GE_PBTN2
#define MAX_MIN 99
#define MAX_SEC 59
#define MAX_MIL 999

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

/**
  * @brief  Main program.
  * @param  None 
  * @retval None
  */
bool stopwatchOn = 0;
int minutes, seconds, millisec;

void stopwatch(void) {
  uint8_t start_on = gpio_read_pin(START);
  uint8_t stop_on = gpio_read_pin(STOP);
  uint8_t reset_on = gpio_read_pin(RESET);

  if (start_on == 0) {
    stopwatchOn = 1;

  } else if (stop_on == 0 && stopwatchOn) {
    stopwatchOn = 0;
  } else if (reset_on == 0) {
    stopwatchOn = 0;
    minutes = 0;
    seconds = 0;
    millisec = 0;
  } else {

  }
  if (stopwatchOn) {
    millisec += 1;
    if (millisec > MAX_MIL) {
      seconds += 1;
      millisec = 0;
    } else if (seconds > MAX_SEC) {
      minutes += 1;
      seconds = 0;
    } else {

    }

  }
  }
int main(void)
{  
  //Initialize library
  ge_init();

  //Initialize GPIO
  gpio_init();
  lcd_init();
  setup_led_gpio();
  lcd_clear();
  lcd_goto(0, 0);
  lcd_puts("00:00.000");


  //Initialize the USER button as an input
  gpio_setup_pin(DISC_PBTN, GPIO_INPUT, false, false);
  gpio_setup_pin(START, GPIO_INPUT, false, false); //start
  gpio_setup_pin(STOP, GPIO_INPUT, false, false); //stop
  gpio_setup_pin(RESET, GPIO_INPUT, false, false); //reset


  //Initialize LC


  // //Print Hello World
  timer_init();
  timer_id_t watch_timer = timer_register(1, &stopwatch, GE_PERIODIC);
  timer_start(watch_timer);

  //Initialize VCOM
  // vcom_init();
  // vcom_send("Hello, World!\n");

  while (1) {  
  lcd_clear();
  lcd_goto(0, 0);
  char disp[9];
  sprintf(disp, "%i:%i.%i", minutes, seconds, millisec);
  lcd_puts(disp); 
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
