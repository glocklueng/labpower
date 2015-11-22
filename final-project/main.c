

//FSM Variables
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


void init_libraries() {
	meter_init();
	ge_init();
	gpio_init();
	lcd_init();

	timer_init();
	pwm_init();
	adc_init();
}

void init_timers(){

	//FSM timer
	timer_id_t FSM_timer = timer_register(50, &change_state, GE_PERIODIC);
  	timer_start(FSM_timer);

  	//output_handler timer
  	//timer_id_t output_timer = timer_register(NUM, CALLBACK, GE_PERIODIC);
  	//timer_start(output_timer);
}

void init_PWMs() {
	//ENABLE CHANNELS and FREQUENCY
	pwm_enable_chan(1);
	pwm_freq(100000); //original was 100000
}

void init_ADCs() {
	//SET FREQUENCY
	//ENABLE CHANNELS
	//INITIALIZE CALLBACK
	//START ADC

	adc_set_fs(FREQ);  //adjust this 
  	adc_enable_channel(3);
 	adc_callback(3, &my_adc_callback);
  	adc_start();
}

void init_all() {
	init_libraries();
	init_timers();
	init_PWMs();
	init_ADCs();
}

int main() {
	init_all();

	return 0;
}



 