#include "io.h"
#include "ad.h"
#include "derivative.h"


void adInit(void) {
	// Habilita o clock para o conversor
	SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK;
	//configura o sistema de conversão: velocidade e modo de disparo
	ADC0_CFG1 = ADC_CFG1_ADIV(2) | ADC_CFG1_MODE(1) | ADC_CFG1_ADLSMP_MASK |  ADC_CFG1_ADICLK(1);
	//Configura terminal 8 da porta B como entrada analógica canal 11
	PORTB_BASE_PTR ->PCR[8] = (PORT_PCR_MUX(0) | PORT_PCR_DSE_MASK);
	bitSet(PTB_BASE_PTR ->PDDR, 8);
	//Configura terminal 9 da porta B como entrada analógica canal 10
	PORTB_BASE_PTR ->PCR[9] = (PORT_PCR_MUX(0) | PORT_PCR_DSE_MASK);
	bitSet(PTB_BASE_PTR ->PDDR, 9);
	//Configura terminal 8 da porta A como entrada analógica canal 3
	PORTA_BASE_PTR ->PCR[8] = (PORT_PCR_MUX(0) | PORT_PCR_DSE_MASK);
	bitSet(PTA_BASE_PTR ->PDDR, 8);
}
int adRead(int channel) {
	//Primeiro configura o canal correto
	//isso já inicializa a conversão.
	if (channel == 0) {
		ADC0_SC1A = 11;
	}
	if (channel == 1) {
		ADC0_SC1A = 10;
	}
	if (channel == 2) {
		ADC0_SC1A  = 3;
	}
	//aguarda a conversão
	while ((ADC0_SC1A & ADC_SC1_COCO_MASK) == 0);
	//retorna o valor convertido
	return ADC0_RA;
}
