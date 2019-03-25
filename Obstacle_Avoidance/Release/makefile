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
Obstacle_Avoidance.lss \

FLASH_IMAGE += \
Obstacle_Avoidance.hex \

EEPROM_IMAGE += \
Obstacle_Avoidance.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Obstacle_Avoidance.elf secondary-outputs

# Tool invocations
Obstacle_Avoidance.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Obstacle_Avoidance.map -mmcu=atmega32 -o "Obstacle_Avoidance.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Obstacle_Avoidance.lss: Obstacle_Avoidance.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Obstacle_Avoidance.elf  >"Obstacle_Avoidance.lss"
	@echo 'Finished building: $@'
	@echo ' '

Obstacle_Avoidance.hex: Obstacle_Avoidance.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Obstacle_Avoidance.elf  "Obstacle_Avoidance.hex"
	@echo 'Finished building: $@'
	@echo ' '

Obstacle_Avoidance.eep: Obstacle_Avoidance.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Obstacle_Avoidance.elf  "Obstacle_Avoidance.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Obstacle_Avoidance.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Obstacle_Avoidance.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Obstacle_Avoidance.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
