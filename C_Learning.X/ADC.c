/*
 * File:   ADC.c
 * Author: User-PC
 *
 * Created on 07 February 2020, 7:26 PM
 */


#pragma config FOSC = INTIO67   // Oscillator Selection bits (Internal oscillator block)
#pragma config WDTEN = OFF  
#define _XTAL_FREQ 4000000 
#include <xc.h>
#include <stdio.h>    // starndard I/O like prinftf
#include <stdlib.h>
#include <pic18F45K22.h>

void main(void) {
    //Setup starts here/////////////////////////////////////////////////////////
    
    OSCCONbits.IRCF0 = 1;
    OSCCONbits.IRCF1 = 0;
    OSCCONbits.IRCF2 = 1;
    
    
    TXSTA1 = 0x00;
    RCSTA1= 0x00;
    TXREG1 = 0x00;
    RCREG1=0x00;
    
    TXSTA1bits.TX9 = 0;
    TXSTA1bits.SYNC = 0;
    TXSTA1bits.BRGH = 1;
    TXSTA1bits.TXEN = 1;
    
    BAUDCONbits.BRG16 = 0;
    BAUDCONbits.DTRXP = 1;
    BAUDCONbits.CKTXP = 1;
    
    SPBRG1 = 12;
    SPBRGH1 = 0x00;
    
    PORTC = 0x00;
    LATC = 0x00;
    ANSELC = 0x00;
    TRISC = 0b11000000;
    
    RCSTA1bits.SPEN = 1;
    RCSTA1bits.CREN = 1;
    RCSTA1bits.SPEN = 1;
    
    
    
    //Setup ends here///////////////////////////////////////////////////////////
    
    
    
    
    return;
}
