################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ATmega16_Master_I2C.c \
../I2C_Master_C_file.c \
../LCD_16x2_C_file.c \
../LCD_MA.c 

OBJS += \
./ATmega16_Master_I2C.o \
./I2C_Master_C_file.o \
./LCD_16x2_C_file.o \
./LCD_MA.o 

C_DEPS += \
./ATmega16_Master_I2C.d \
./I2C_Master_C_file.d \
./LCD_16x2_C_file.d \
./LCD_MA.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


