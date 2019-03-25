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
pd7_uln2003_test.lss \

FLASH_IMAGE += \
pd7_uln2003_test.hex \

EEPROM_IMAGE += \
pd7_uln2003_test.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: pd7_uln2003_test.elf secondary-outputs

# Tool invocations
pd7_uln2003_test.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,pd7_uln2003_test.map -mmcu=atmega32 -o "pd7_uln2003_test.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

pd7_uln2003_test.lss: pd7_uln2003_test.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S pd7_uln2003_test.elf  >"pd7_uln2003_test.lss"
	@echo 'Finished building: $@'
	@echo ' '

pd7_uln2003_test.hex: pd7_uln2003_test.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex pd7_uln2003_test.elf  "pd7_uln2003_test.hex"
	@echo 'Finished building: $@'
	@echo ' '

pd7_uln2003_test.eep: pd7_uln2003_test.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex pd7_uln2003_test.elf  "pd7_uln2003_test.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: pd7_uln2003_test.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 pd7_uln2003_test.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) pd7_uln2003_test.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
