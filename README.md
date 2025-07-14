# STM32 PWM Module

A lightweight, reusable STM32 HAL-based PWM control module written in C.

## Features
- General-purpose PWM abstraction for STM32
- Configurable timer, channel, duty cycle
- Simple API: `init()`, `start()`, `stop()`, `setDuty()`
- Suitable for LED dimming, motor control, etc.
- Optional logger integration for debugging

## Structure
- `pwm.h`: Module interface
- `pwm.c`: Implementation
- `pwm_version.h`: Version macros
- `main.c`: Example usage

## Usage
Include `pwm.h` and link with STM32 HAL libraries.
Example:
```c
PwmChannel_t pwm;
Pwm_init(&pwm, &htim3, TIM_CHANNEL_1);
Pwm_start(&pwm);
Pwm_setDuty(&pwm, 50); // 50% duty cycle
```
