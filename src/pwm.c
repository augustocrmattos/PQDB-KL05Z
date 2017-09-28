#include "pwm.h"
#include "io.h"
#include "derivative.h"
//liga o buzzer com uma frequência de som
//duty cycle configurado em 50%
void pwmBuzzer(unsigned int frequency){
	int period;
	//para prescaler = 1/1 (sem prescaler)
	if ((frequency>0) && (frequency < 40000)){
		period = 24000000/frequency;
		TPM0_MOD = period;
		TPM0_C0V = (period/2);
	}
}
//define uma frequência de trabalho
void pwmFrequency(unsigned int frequency){
	//para prescaler = 1/1 (sem prescaler)
	if ((frequency>0) && (frequency < 40000)){
		TPM0_MOD = 24000000/frequency;
	}
}
//configura a saída como um valor de 0 à 100%
void pwmDutyCycle(float percentage){
	if ((percentage>=0) && (percentage <= 100)){
		TPM0_MOD = (unsigned int)((percentage*TPM0_MOD)/100);
	}
}
void pwmInit(void){
	//Habilita as saídas dos terminais
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTA_MASK;
	//Habilita o clock para o periférico do PWM
	SIM_SCGC6|=( SIM_SCGC6_TPM0_MASK | SIM_SCGC6_TPM1_MASK);   
	//escolhe a fonte de clock do periférico como o oscilador principal do sistema
	SIM_SOPT2 |= SIM_SOPT2_TPMSRC(1); //
	//configura o terminal D9 (portb 11) como uma saída do tipo PWM
	PORTB_PCR11  = (0|PORT_PCR_MUX(2));
	//configura o valor máximo para o contador de tempo
	TPM0_MOD  = 1000;
	//Configura timer para acioanr o PWM, ligando quando a compararção for verdadeira e desligando quando resetar o contador
	TPM0_C0SC = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSA_MASK; 
	//configura o registro de contador para aumentar a cada incremento do timer, sem prescaler(1/1)
	TPM0_SC   = TPM_SC_CMOD(1) | TPM_SC_PS(0);
}
