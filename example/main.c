#include "stm32f4xx_hal.h"
#include "pwm.h"
#include "logger.h"

TIM_HandleTypeDef htim3; // Example timer handle (must be initialized in your project)

int main(void) {
    HAL_Init();
    SystemClock_Config(); // Provided elsewhere in your project
    MX_TIM3_Init();       // Provided elsewhere in your project

    Logger_init();

    PwmChannel_t pwm;
    Pwm_init(&pwm, &htim3, TIM_CHANNEL_1);

    Pwm_start(&pwm);

    while (1) {
        for (uint8_t duty = 0; duty <= 100; duty += 10) {
            Pwm_setDuty(&pwm, duty);
            HAL_Delay(500);
        }
    }
}

// Provide your TIM3 init function and SystemClock_Config as appropriate
