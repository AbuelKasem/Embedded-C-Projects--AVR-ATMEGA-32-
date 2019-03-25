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
Rtos_binarySemaphore_event.lss \

FLASH_IMAGE += \
Rtos_binarySemaphore_event.hex \

EEPROM_IMAGE += \
Rtos_binarySemaphore_event.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Rtos_binarySemaphore_event.elf secondary-outputs

# Tool invocations
Rtos_binarySemaphore_event.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Rtos_binarySemaphore_event.map -mmcu=atmega32 -o "Rtos_binarySemaphore_event.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Rtos_binarySemaphore_event.lss: Rtos_binarySemaphore_event.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Rtos_binarySemaphore_event.elf  >"Rtos_binarySemaphore_event.lss"
	@echo 'Finished building: $@'
	@echo ' '

Rtos_binarySemaphore_event.hex: Rtos_binarySemaphore_event.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Rtos_binarySemaphore_event.elf  "Rtos_binarySemaphore_event.hex"
	@echo 'Finished building: $@'
	@echo ' '

Rtos_binarySemaphore_event.eep: Rtos_binarySemaphore_event.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Rtos_binarySemaphore_event.elf  "Rtos_binarySemaphore_event.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Rtos_binarySemaphore_event.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Rtos_binarySemaphore_event.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Rtos_binarySemaphore_event.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
