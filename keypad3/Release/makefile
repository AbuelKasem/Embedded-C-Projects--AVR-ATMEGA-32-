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
keypad3.lss \

FLASH_IMAGE += \
keypad3.hex \

EEPROM_IMAGE += \
keypad3.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: keypad3.elf secondary-outputs

# Tool invocations
keypad3.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,keypad3.map -mmcu=atmega32 -o "keypad3.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

keypad3.lss: keypad3.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S keypad3.elf  >"keypad3.lss"
	@echo 'Finished building: $@'
	@echo ' '

keypad3.hex: keypad3.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex keypad3.elf  "keypad3.hex"
	@echo 'Finished building: $@'
	@echo ' '

keypad3.eep: keypad3.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex keypad3.elf  "keypad3.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: keypad3.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 keypad3.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) keypad3.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
