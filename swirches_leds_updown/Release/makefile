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
swirches_leds_updown.lss \

FLASH_IMAGE += \
swirches_leds_updown.hex \

EEPROM_IMAGE += \
swirches_leds_updown.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: swirches_leds_updown.elf secondary-outputs

# Tool invocations
swirches_leds_updown.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,swirches_leds_updown.map -mmcu=atmega32 -o "swirches_leds_updown.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

swirches_leds_updown.lss: swirches_leds_updown.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S swirches_leds_updown.elf  >"swirches_leds_updown.lss"
	@echo 'Finished building: $@'
	@echo ' '

swirches_leds_updown.hex: swirches_leds_updown.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex swirches_leds_updown.elf  "swirches_leds_updown.hex"
	@echo 'Finished building: $@'
	@echo ' '

swirches_leds_updown.eep: swirches_leds_updown.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex swirches_leds_updown.elf  "swirches_leds_updown.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: swirches_leds_updown.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 swirches_leds_updown.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) swirches_leds_updown.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
