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
Input_switch.lss \

FLASH_IMAGE += \
Input_switch.hex \

EEPROM_IMAGE += \
Input_switch.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Input_switch.elf secondary-outputs

# Tool invocations
Input_switch.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Input_switch.map -mmcu=atmega32 -o "Input_switch.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Input_switch.lss: Input_switch.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Input_switch.elf  >"Input_switch.lss"
	@echo 'Finished building: $@'
	@echo ' '

Input_switch.hex: Input_switch.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Input_switch.elf  "Input_switch.hex"
	@echo 'Finished building: $@'
	@echo ' '

Input_switch.eep: Input_switch.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Input_switch.elf  "Input_switch.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Input_switch.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Input_switch.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Input_switch.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
