################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LCD_MA.c \
../main.c \
../timer2_normal.c \
../ultrasonic_HCSR04.c 

OBJS += \
./LCD_MA.o \
./main.o \
./timer2_normal.o \
./ultrasonic_HCSR04.o 

C_DEPS += \
./LCD_MA.d \
./main.d \
./timer2_normal.d \
./ultrasonic_HCSR04.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


