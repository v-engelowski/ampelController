/*
* Ampel_2020.cpp
*
* Created: 22.03.2020 14:56:59
* Author : Ralfw
*/


#include <avr/io.h>


#define  F_CPU 20000000UL
#include <util/delay.h>
#define AMPELDDR  DDRB
#define AMPELPORT PORTB
#define AMPELPIN  PINB


#define ROT_A    PORTB0
#define GELB_A    PORTB1
#define GRUEN_A PORTB2


#define ROT_F    PORTB3
#define GRUEN_F    PORTB4



#define TASTE_A PORTB5



int main(void)
{
    
    // Data Direction Register
    AMPELDDR=(1<<ROT_A)|(1<<GRUEN_A)|(1<<GELB_A)|(1<<GRUEN_F)|(1<<ROT_F);
    //internen Pullup einschalten
    AMPELPORT=(1<<TASTE_A);
    uint8_t i;
    i=0;
    /* Replace with your application code */
    while (1)
    {
        switch (i++)
        {


       case 0:        
        AMPELPORT =(1<<ROT_A)|(1<<ROT_F);
                    break;    
        case 1:        
        AMPELPORT =(1<<ROT_A)|(1<<GELB_A)|(1<<ROT_F);
                    break;
        case 2:        
        AMPELPORT =(1<<GRUEN_A)|(1<<ROT_F)|(1<<TASTE_A);
                    //Tastenabfrage
                    while (AMPELPIN & (1<<TASTE_A));
                    break;
        case 3:        
        AMPELPORT =(1<<GELB_A)|(1<<ROT_F);
                    break;
        case 4:        
        AMPELPORT =(1<<ROT_A)|(1<<ROT_F);
                    break;
        case 5:        
        AMPELPORT =(1<<ROT_A)|(1<<GRUEN_F) |(1<<TASTE_A);
                    i=0;
                    break;
                                
        default:    i=0;
        }
    _delay_ms(1000);    
    



    }
}
