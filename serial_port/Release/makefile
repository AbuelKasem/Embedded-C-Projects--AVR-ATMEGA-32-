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
serial_port.lss \

FLASH_IMAGE += \
serial_port.hex \

EEPROM_IMAGE += \
serial_port.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: serial_port.elf secondary-outputs

# Tool invocations
serial_port.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,serial_port.map -mmcu=atmega32 -o "serial_port.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

serial_port.lss: serial_port.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S serial_port.elf  >"serial_port.lss"
	@echo 'Finished building: $@'
	@echo ' '

serial_port.hex: serial_port.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex serial_port.elf  "serial_port.hex"
	@echo 'Finished building: $@'
	@echo ' '

serial_port.eep: serial_port.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex serial_port.elf  "serial_port.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: serial_port.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 serial_port.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) serial_port.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
