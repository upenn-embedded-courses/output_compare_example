
#include <avr/io.h>
#include <avr/interrupt.h>

void Initialize()
{
  // Disable global interrupts
  cli();  

  // GPIO Pins Setup
  DDRB |= (1<<DDB1);      // Set PB1(OC1A) to be output pin

  // Timer Setup
  // Set Timer 1 clock to be internal div by 1
  // System Clock is 16MHz, Timer1 clock is 16M/1 = 16MHz
  TCCR1B |= (1<<CS10);

  // Set Timer 1 to CTC (clear the counter)
  TCCR1B |= (1<<WGM12);

  // Toggle OC1A on compare match
  TCCR1A |= (1<<COM1A0); 
  OCR1A = 800;  // 1Hz square wave with 50% duty cycle

  // Enable global interrupts
  sei();  
}


int main(void)
{
  Initialize();
  while(1); 
}


