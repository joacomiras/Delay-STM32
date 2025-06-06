#include "delay.h"
#include "stm32f103xb.h"

int main(void) {
    /* Habilito CLK PC */
    RCC-> APB2ENR |= RCC_APB2ENR_IOPCEN;
    /* Configuro como salida push-pull a velocidad minima PC13*/
    GPIOC -> CRH &=~(0xF<<(13%8)*4);
    GPIOC -> CRH |=(1<<(13%8)*4); 
    while (1) {
        /* Hago que cambie de estado el led interno cada 500ms*/
        GPIOC->ODR ^= (1 << 13);  
        delay_ms(500);           
    }
    return 0;
}