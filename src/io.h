#ifndef IO_H_
#define IO_H_

#define bitSet(arg,bit) ((arg) |= (1<<bit))
#define bitClr(arg,bit) ((arg) &= ~(1<<bit)) 
#define bitFlp(arg,bit) ((arg) ^= (1<<bit)) 
#define bitTst(arg,bit) ((arg) & (1<<bit)) 

#define OUTPUT 0
#define INPUT  1
#define LOW 0
#define HIGH 1

//definição das funções dos terminais físicos
#define SCL_PIN      19
#define SDA_PIN      18
#define keyb1        13
#define keyb2        12
#define SO_CLK_PIN   11
#define SO_EN_PIN    10
#define PWM           9
#define SO_DATA_PIN   8
#define LCD_RS_PIN    7
#define LCD_EN_PIN    6
#define DISP4_PIN     5
#define DISP3_PIN     4 
#define DISP2_PIN     3
#define DISP1_PIN     2
#define TX            1
#define RX            0
//Os led compartilham os terminais dos displays
#define LED_R_PIN DISP1_PIN
#define LED_G_PIN DISP2_PIN
#define LED_B_PIN DISP3_PIN

	void pinMode(int pin, int type);
	void digitalWrite(int pin, int value);
	int digitalRead(int pin);
	void systemInit(void);
#endif /* IO_H_ */
