################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include FreeRTOS/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Rtos_Message_Queue.lss \

FLASH_IMAGE += \
Rtos_Message_Queue.hex \

EEPROM_IMAGE += \
Rtos_Message_Queue.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Rtos_Message_Queue.elf secondary-outputs

# Tool invocations
Rtos_Message_Queue.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Rtos_Message_Queue.map -mmcu=atmega32 -o "Rtos_Message_Queue.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Rtos_Message_Queue.lss: Rtos_Message_Queue.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Rtos_Message_Queue.elf  >"Rtos_Message_Queue.lss"
	@echo 'Finished building: $@'
	@echo ' '

Rtos_Message_Queue.hex: Rtos_Message_Queue.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Rtos_Message_Queue.elf  "Rtos_Message_Queue.hex"
	@echo 'Finished building: $@'
	@echo ' '

Rtos_Message_Queue.eep: Rtos_Message_Queue.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Rtos_Message_Queue.elf  "Rtos_Message_Queue.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Rtos_Message_Queue.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Rtos_Message_Queue.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Rtos_Message_Queue.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
