
#define MAX_SETPOINT 100
float setpoint;
float observed_speed;

float phase1_curr;
float phase1_emf;
float phase2_curr;
float phase2_emf;
float phase3_curr;
float phase3_emf;
float total_curr;

//FSM Variables
enum DISP_STATES {DISP_MAIN, DISP_INFO};
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

void init_buttons() {
	gpio_setup_pin(DISC_PBTN, GPIO_INPUT, false, false);
  gpio_setup_pin(GE_PBTN1, GPIO_INPUT, false, false); // raise the setpoint button
  gpio_setup_pin(GE_PBTN2, GPIO_INPUT, false, false); // lower the setpoint button
  gpio_setup_pin(GE_PBTN3, GPIO_INPUT, false, false); // go to max
  gpio_setup_pin(GE_PBTN4, GPIO_INPUT, false, false); // down to 0 
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
	init_buttons();
	init_timers();
	init_PWMs();
	init_ADCs();
}

void speed_display() {
	char current_speed[20];
	char setpt[20];

	sprintf(current_speed, "Speed: %.3f", observed_speed);
	sprintf(setpt, "Setpoint : %.3f", setpoint);
}

void info_display() {
	char phase1[20];
	char phase2[20];
	char phase3[20];
	char total[20];

	sprintf(phase1, "%.3f I, %.3f V", phase1_curr, phase1_emf);	
	sprintf(phase2, "%.3f I, %.3f V", phase2_curr, phase2_emf);
	sprintf(phase3, "%.3f I, %.3f V", phase3_curr, phase3_emf);
	sprintf(total, "Total: %.3f I", total_curr)
}


int main() {
	init_all();

	uint8_t last_state = 255;
	while (1) {

		if (state != last_state) {
			lcd_clear();
			last_state = state;
		}

		switch(state) {

			case DISP_MAIN:
			if(!gpio_read_pin(GE_PBTN3)) {
				setpoint += dset;
				if(setpoint > MAX_SETPOINT) setpoint = MAX_SETPOINT;		
			}

			if(!gpio_read_pin(GE_PBTN4)) {
				setpoint -= dset;
				if(setpoint < 0.0) setpoint = 0.0;
			}

			speed_display();
			break;

			case DISP_INFO:
			info_display();
			break;

			default:
			state = DISP_MAIN;
			break;
		}
	}
	return 0;
}



