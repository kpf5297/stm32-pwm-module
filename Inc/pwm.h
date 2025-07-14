#ifndef PWM_H
#define PWM_H

#include "stm32f4xx_hal.h"
#include <stdint.h>
#include "logger.h"

/**
 * @brief General-purpose PWM channel abstraction.
 */
typedef struct {
    TIM_HandleTypeDef* htim;  /**< Timer handle */
    uint32_t channel;         /**< Timer channel (e.g., TIM_CHANNEL_1) */
    uint32_t period;          /**< Auto-reload register (ARR) value */
    uint8_t duty_percent;     /**< Last duty cycle (0–100%) */
} PwmChannel_t;

void Pwm_init(PwmChannel_t* pwm, TIM_HandleTypeDef* htim, uint32_t channel);
void Pwm_start(PwmChannel_t* pwm);
void Pwm_stop(PwmChannel_t* pwm);
void Pwm_setDuty(PwmChannel_t* pwm, uint8_t duty_percent);

#endif // PWM_H
