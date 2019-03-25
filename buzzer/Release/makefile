################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
buzzer.lss \

FLASH_IMAGE += \
buzzer.hex \

EEPROM_IMAGE += \
buzzer.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: buzzer.elf secondary-outputs

# Tool invocations
buzzer.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,buzzer.map -mmcu=atmega32 -o "buzzer.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

buzzer.lss: buzzer.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S buzzer.elf  >"buzzer.lss"
	@echo 'Finished building: $@'
	@echo ' '

buzzer.hex: buzzer.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex buzzer.elf  "buzzer.hex"
	@echo 'Finished building: $@'
	@echo ' '

buzzer.eep: buzzer.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex buzzer.elf  "buzzer.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: buzzer.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 buzzer.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) buzzer.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
