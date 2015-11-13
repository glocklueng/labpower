/**
 * @file  supply_controller.c
 * @brief Power supply controller
 * 
 * @details Regulates a 5V supply
 * 
 * @author Team SCV
 * @date  10.2015
 */


 //PID Constants
 #define kp -0.01
 #define kd .000001
 #define ki .0001

 #define time_step (1.0/20000.0)

//globals
 float old_err = 0;
 float old_ierr = 0;
 float df = 0;

// setpoint is with reference to the ADC input (with the )
 float supply_controller(float current_voltage, float setpoint){

 	float p_err = current_voltage - setpoint;
 	float d_err =  (p_err - old_err)/time_step;
 	float i_err = old_ierr + p_err*time_step;

 	float ddf = p_err*kp + d_err*kd +i_err*ki;

 	//float ff_df = power_supply_model(old_df, setpoint);

 	df += ddf;

 	if(df>1) df = 1;
 	else if (df<0) df = 0;
 	
 	old_err = p_err;
 	old_ierr = i_err;

 	return df;
 }


 // float power_supply_model(float old, float setpoint){
 // 	float r_load = 10;
 // 	float r_parasitic = 1.6*old^2 - 2.79*old + 1.95; //CARSON DID THIS
 // 	float r1 = 13300;
 // 	float r2 = 10000;

 // 	float r_eff = (1/r_load + 1/(r1+r2))^(-1);

 // 	float df = (setpoint*(1 + r_parasitic/r_eff))/v_supply;
 // 	return df;
 // }