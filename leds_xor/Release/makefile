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
leds_xor.lss \

FLASH_IMAGE += \
leds_xor.hex \

EEPROM_IMAGE += \
leds_xor.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: leds_xor.elf secondary-outputs

# Tool invocations
leds_xor.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,leds_xor.map -mmcu=atmega32 -o "leds_xor.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

leds_xor.lss: leds_xor.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S leds_xor.elf  >"leds_xor.lss"
	@echo 'Finished building: $@'
	@echo ' '

leds_xor.hex: leds_xor.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex leds_xor.elf  "leds_xor.hex"
	@echo 'Finished building: $@'
	@echo ' '

leds_xor.eep: leds_xor.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex leds_xor.elf  "leds_xor.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: leds_xor.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 leds_xor.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) leds_xor.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
