/*
 * Blinky Led Prgram
 * Ho Viet Cuong
 * University of Technology
 * Embedded Sofware C/C++
 * Solution:
 *
 */
#include <stdint.h>
#include <stdbool.h>
#include <inc/hw_types.h>
#include <inc/hw_memmap.h>
#include <driverlib/sysctl.h>
#include <driverlib/gpio.h>

//Main Program
int main(void)
{
    //uint8_t ui8Led=2;
    SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);     //freq = 200/2.5 = 80Mhz
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1);
    while(1)
    {
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);
        SysCtlDelay(13333333);         //delay 1s --> ham delay co thoi gian 3 chu ky may, tdelay = ((1/80Mhz) * 3)* value

        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0);
        SysCtlDelay(13333333);
    }

}
