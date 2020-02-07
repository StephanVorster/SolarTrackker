/*
 * File:   IO_Ports.c
 * Author: User-PC
 *
 * Created on 06 February 2020, 4:39 PM
 */
#pragma config FOSC = INTIO67   // Oscillator Selection bits (Internal oscillator block)
#pragma config WDTEN = OFF  
#define _XTAL_FREQ 8000000 
#include <xc.h>
#include <stdio.h>    // starndard I/O like prinftf
#include <stdlib.h>
//#include <pic18F45K22.h>

void main(void) {
    //ANSELA = 0;
    //OSCCON=0x76;
    //OSCCON=0x6D;
    OSCCON=0x5B;
    
    TRISA =0;
    TRISB = 0;
    
    unsigned char prev;
    
   
    while(1){
         //LATA = 0xFF;
        prev = LATA;
        if(LATA == 0xFF)
        {
            PORTA = 0x00;
        }
        else{
         PORTA = 0xFF;   
        }
        
        PORTB = prev;
        __delay_ms(1000); //Generate 1 second delay
         
    };
    return;
}
