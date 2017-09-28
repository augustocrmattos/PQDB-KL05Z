#include "io.h"
#include "derivative.h"

#define PORTA_PDDR (PTA_BASE_PTR ->PDDR)
#define PORTA_PDOR (PTA_BASE_PTR ->PDOR)
#define PORTA_PDIR (PTA_BASE_PTR ->PDIR)

#define PORTB_PDDR (PTB_BASE_PTR ->PDDR)
#define PORTB_PDOR (PTB_BASE_PTR ->PDOR)
#define PORTB_PDIR (PTB_BASE_PTR ->PDIR)

#define PRC_V (PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK)

void systemInit(void) {
	//init clock das portas
	SIM_SCGC5 |= (SIM_SCGC5_PORTA_MASK | SIM_SCGC5_PORTB_MASK);
	//configura para usar clock interno em 24MHz
	MCG_BASE_PTR ->C4 |= 0x80;
	//portb 5, remover o NMI
	PORTB_PCR(5) = PRC_V;

	//PORTA_PCR(0)  = PRC_V;
	//TSI0_GENCS &= ~(1<<7);
	//TSI0_GENCS &= ~(1<<6);
	//pinMode(9,OUTPUT);

}
void pinMode(int pin, int type) {
	if (type == OUTPUT) {
		switch (pin) {
		case 0: PORTB_PCR(2)  = PRC_V; bitSet(PORTB_PDDR, 2);  break;
		case 1: PORTB_PCR(1)  = PRC_V; bitSet(PORTB_PDDR, 1);  break;
		case 2: PORTA_PCR(11) = PRC_V; bitSet(PORTA_PDDR, 11); break;
		case 3: PORTB_PCR(5)  = PRC_V; bitSet(PORTB_PDDR, 5);  break;
		case 4: PORTA_PCR(10) = PRC_V; bitSet(PORTA_PDDR, 10); break;
		case 5: PORTA_PCR(12) = PRC_V; bitSet(PORTA_PDDR, 12); break;
		case 6: PORTB_PCR(6)  = PRC_V; bitSet(PORTB_PDDR, 6);  break;
		case 7: PORTB_PCR(7)  = PRC_V; bitSet(PORTB_PDDR, 7);  break;
		case 8: PORTB_PCR(10) = PRC_V; bitSet(PORTB_PDDR, 10); break;
		case 9: PORTA_PCR(11) = PRC_V; bitSet(PORTA_PDDR, 11); break;
		case 10: PORTA_PCR(5) = PRC_V; bitSet(PORTA_PDDR, 5);  break;
		case 11: PORTA_PCR(7) = PRC_V; bitSet(PORTA_PDDR, 7);  break;
		case 12: PORTA_PCR(6) = PRC_V; bitSet(PORTA_PDDR, 6);  break;
		case 13: PORTB_PCR(0) = PRC_V; bitSet(PORTB_PDDR, 0);  break;
			
		case 18: PORTA_PCR(9) = PRC_V; bitSet(PORTA_PDDR, 9);  break;
		case 19: PORTB_PCR(13)= PRC_V; bitSet(PORTB_PDDR, 13); break;
		default: break;
		}
	}
	if (type == INPUT) {
		switch (pin) {
		case 12: PORTA_PCR(6)  = PRC_V; bitClr(PORTA_PDDR, 6);  break;
		case 13: PORTB_PCR(0)  = PRC_V; bitClr(PORTB_PDDR, 0);  break;
		case 18: PORTA_PCR(9)  = PRC_V; bitClr(PORTA_PDDR, 9);  break;
		case 19: PORTB_PCR(13) = PRC_V; bitClr(PORTB_PDDR, 13); break;
		default:  break;
		}
	}
}
void digitalWrite(int pin, int value) {
	if (value) {
		switch (pin) {
		case 0:bitSet(PORTB_PDOR, 2);break;
		case 1:bitSet(PORTB_PDOR, 1);break;
		case 2:bitSet(PORTA_PDOR, 11);break;
		case 3:bitSet(PORTB_PDOR, 5);break;
		case 4:bitSet(PORTA_PDOR, 10);break;
		case 5:bitSet(PORTA_PDOR, 12);break;
		case 6:bitSet(PORTB_PDOR, 6);break;
		case 7:bitSet(PORTB_PDOR, 7);break;
		case 8:bitSet(PORTB_PDOR, 10);break;
		case 9:bitSet(PORTB_PDOR, 11);break;
		case 10:bitSet(PORTA_PDOR, 5);break;
		case 11:bitSet(PORTA_PDOR, 7);break;
		case 12:bitSet(PORTA_PDOR, 6);break;
		case 13:bitSet(PORTB_PDOR, 0);break;
		
		case 18:bitSet(PORTA_PDOR, 9);break;
		case 19:bitSet(PORTB_PDOR, 13);break;
		default:break;
		}
	} else {
		switch (pin) {
		case 0:bitClr(PORTB_PDOR, 2);break;
		case 1:bitClr(PORTB_PDOR, 1);break;
		case 2:bitClr(PORTA_PDOR, 11);break;
		case 3:bitClr(PORTB_PDOR, 5);break;
		case 4:bitClr(PORTA_PDOR, 10);break;
		case 5:bitClr(PORTA_PDOR, 12);break;
		case 6:bitClr(PORTB_PDOR, 6);break;
		case 7:bitClr(PORTB_PDOR, 7);break;
		case 8:bitClr(PORTB_PDOR, 10);break;
		case 9:bitClr(PORTB_PDOR, 11);break;
		case 10:bitClr(PORTA_PDOR, 5);break;
		case 11:bitClr(PORTA_PDOR, 7);break;
		case 12:bitClr(PORTA_PDOR, 6);break;
		case 13:bitClr(PORTB_PDOR, 0);break;

		case 18:bitClr(PORTA_PDOR, 9);break;
		case 19:bitClr(PORTB_PDOR, 13);break;
		default:break;
		}
	}
}
int digitalRead(int pin) {
	switch (pin) {
	case 0:return bitTst(PORTB_PDIR, 2);
	case 1:return bitTst(PORTB_PDIR, 1);
	case 2:return bitTst(PORTA_PDIR, 11);
	case 3:return bitTst(PORTB_PDIR, 5);
	case 4:return bitTst(PORTA_PDIR, 10);
	case 5:return bitTst(PORTA_PDIR, 12);
	case 6:return bitTst(PORTB_PDIR, 6);
	case 7:return bitTst(PORTB_PDIR, 7);
	case 8:return bitTst(PORTB_PDIR, 10);
	case 9:return bitTst(PORTB_PDIR, 11);
	case 10:return bitTst(PORTA_PDIR, 5);
	case 11:return bitTst(PORTA_PDIR, 7);
	case 12:return bitTst(PORTA_PDIR, 6);
	case 13:return bitTst(PORTB_PDIR, 0);

	case 18:return bitTst(PORTA_PDIR, 9);
	case 19:return bitTst(PORTB_PDIR, 13);
	default:break;
	}
	return -1;
}
