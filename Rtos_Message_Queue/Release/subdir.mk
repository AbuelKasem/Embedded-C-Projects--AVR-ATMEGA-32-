################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../UART_MA.c \
../main.c \
../usart_driver.c 

OBJS += \
./UART_MA.o \
./main.o \
./usart_driver.o 

C_DEPS += \
./UART_MA.d \
./main.d \
./usart_driver.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\dell\Documents\ECLIPSworks\Rtos_Message_Queue\FreeRTOS" -I"C:\Users\dell\Documents\ECLIPSworks\Rtos_Message_Queue\FreeRTOS\Inc" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


