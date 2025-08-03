#include "stm32f4xx_hal.h"
#include "pwm.h"

/*
 * Minimal example demonstrating the PWM module. The HAL initialization
 * routines are assumed to be provided by the user project.
 */

/* Example timer handle used by the demo. Must be configured elsewhere
 * with period and prescaler values suitable for your application. */
TIM_HandleTypeDef htim3;

int main(void) {
    HAL_Init();
    SystemClock_Config(); // Provided elsewhere in your project
    MX_TIM3_Init();       // Provided elsewhere in your project

    /* Optionally query driver version */
    const char* version = Pwm_getVersion();
    (void)version;

    PwmChannel_t pwm;
    Pwm_init(&pwm, &htim3, TIM_CHANNEL_1);

    Pwm_start(&pwm);

    /* Sweep duty cycle from 0 to 100% in 10% increments */
    while (1) {
        for (uint8_t duty = 0; duty <= 100; duty += 10) {
            Pwm_setDuty(&pwm, duty);
            HAL_Delay(500);
        }
    }
}

// Provide your TIM3 init function and SystemClock_Config as appropriate
