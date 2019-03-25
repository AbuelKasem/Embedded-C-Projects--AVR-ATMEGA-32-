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
stepper.lss \

FLASH_IMAGE += \
stepper.hex \

EEPROM_IMAGE += \
stepper.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: stepper.elf secondary-outputs

# Tool invocations
stepper.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,stepper.map -mmcu=atmega32 -o "stepper.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

stepper.lss: stepper.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S stepper.elf  >"stepper.lss"
	@echo 'Finished building: $@'
	@echo ' '

stepper.hex: stepper.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex stepper.elf  "stepper.hex"
	@echo 'Finished building: $@'
	@echo ' '

stepper.eep: stepper.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex stepper.elf  "stepper.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: stepper.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 stepper.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) stepper.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
