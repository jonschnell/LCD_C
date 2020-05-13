/// Simple 'Hello, world' program
/**
 * This program prints "Hello, world" to the LCD screen
 * @author Jon Schnell
 * @date 01/10/2020
 *
 * updated: phjones 9/3/2019
 * Description: Added timer_init call, and including Timer.h
 */

#include "Timer.h"
#include "lcd.h"

void printBanner(char text[])
{
    char display[20];
    //max string length is 80 characters
    char space[100] = "                    ";
    int counter = 0;
    int i = 0;
    int j = 0;


    // To iterate First String from Start to end
    for (i = 0; space[i]!='\0'; i++);

    // Concatenating Str2 into Str1
    for (j = 0; text[j]!='\0'; j++, i++)
    {
        space[i] = text[j];
    }
    //space is the new concatonated string
    space[i] = '\0';


    //loops infinitely
    while (true){
        //populate the display array to be displayed every 300 ms
        for (i = 0; i < 19; i++){
            display[i] = space[i+counter];
        }

        lcd_printf(display);

        //resets once message has passed
        counter++;
        if(counter == 20 + strlen(text)){
            counter = 0;

        }
        timer_waitMillis(300);
    }

}


int main (void) {

    char test[] = "some more text";

    //char banner[] = "                   Microcontrollers are lots of fun!";
    //char display[20];
    //int counter = 0;
    //int i;

	timer_init(); // Initialize Timer, needed before any LCD screen functions can be called 
	              // and enables time functions (e.g. timer_waitMillis)

	lcd_init();   // Initialize the LCD screen.  This also clears the screen. 


	printBanner(test); //prints scrolling banner right to left.

/*
	while (true){
	    for (i = 0; i < 19; i++){
	        display[i] = banner[i+counter];
	    }

	    lcd_printf(display);

	    counter++;
	    if(counter == 53){
	        counter = 0;
	    }
	    timer_waitMillis(300);
	}
*/


	//lcd_puts("Hello, world"); // Replace lcd_printf with lcd_puts
        // step through in debug mode and explain to TA how it works
    
	// NOTE: It is recommended that you use only lcd_init(), lcd_printf(), lcd_putc, and lcd_puts from lcd.h.
       // NOTE: For time functions, see Timer.h

	//return 0;
}
