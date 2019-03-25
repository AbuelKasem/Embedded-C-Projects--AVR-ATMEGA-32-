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
ultrasonic_timer2.lss \

FLASH_IMAGE += \
ultrasonic_timer2.hex \

EEPROM_IMAGE += \
ultrasonic_timer2.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: ultrasonic_timer2.elf secondary-outputs

# Tool invocations
ultrasonic_timer2.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ultrasonic_timer2.map -mmcu=atmega32 -o "ultrasonic_timer2.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ultrasonic_timer2.lss: ultrasonic_timer2.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ultrasonic_timer2.elf  >"ultrasonic_timer2.lss"
	@echo 'Finished building: $@'
	@echo ' '

ultrasonic_timer2.hex: ultrasonic_timer2.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ultrasonic_timer2.elf  "ultrasonic_timer2.hex"
	@echo 'Finished building: $@'
	@echo ' '

ultrasonic_timer2.eep: ultrasonic_timer2.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex ultrasonic_timer2.elf  "ultrasonic_timer2.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ultrasonic_timer2.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ultrasonic_timer2.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ultrasonic_timer2.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
