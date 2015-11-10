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
 #define kp -100
 #define kd .00001
 #define ki .0001


// setpoint is with reference to the ADC input (with the )
 float supply_controller(float current_voltage, float setpoint, float v_supply){

 	p_err = current_voltage - setpoint;
 	d_err =  (p_err - old_err)/(update_ratio*dt);
 	i_err = old_ierr + p_err*update_ratio*dt;

 	ddf = p_err*kp + d_err*kd +i_err*ki;

 	ff_df = power_supply_model(v_supply, old_df, setpoint);

 	df = ff_df + ddf;

 	if(df>1){
 		df = 1;
 	}
 	else if (df<0){
 		df = 0;
 	}
 	

 	return df;
 }


 float power_supply_model(float v_supply, float old_df, float setpoint){
 	float r_load = 10;
 	float r_parasitic = 1.6*old_df^2 - 2.79*old_df + 1.95;
 	float r1 = 13300;
 	float r2 = 10000;

 	float r_eff = (1/r_load + 1/(r1+r2))^-1;

 	float df = (setpoint*(1 + r_parasitic/r_eff))/v_supply;
 	return df;
 }