#ifndef PWM_H
#define PWM_H
	
	void pwmInit(void);
	void pwmBuzzer(unsigned int frequency);
	void pwmFrequency(unsigned int frequency);
	void pwmDutyCycle(float percentage);

#endif //PWM_H
