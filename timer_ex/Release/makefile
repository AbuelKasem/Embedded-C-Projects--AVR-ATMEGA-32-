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
timer_ex.lss \

FLASH_IMAGE += \
timer_ex.hex \

EEPROM_IMAGE += \
timer_ex.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: timer_ex.elf secondary-outputs

# Tool invocations
timer_ex.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,timer_ex.map -mmcu=atmega32 -o "timer_ex.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

timer_ex.lss: timer_ex.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S timer_ex.elf  >"timer_ex.lss"
	@echo 'Finished building: $@'
	@echo ' '

timer_ex.hex: timer_ex.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex timer_ex.elf  "timer_ex.hex"
	@echo 'Finished building: $@'
	@echo ' '

timer_ex.eep: timer_ex.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex timer_ex.elf  "timer_ex.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: timer_ex.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 timer_ex.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) timer_ex.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
