################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/subdir.mk
-include APPLICATION/subdir.mk
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
Counter_2Seg.lss \

FLASH_IMAGE += \
Counter_2Seg.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Counter_2Seg.elf secondary-outputs

# Tool invocations
Counter_2Seg.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Counter_2Seg.map -mmcu=atmega32 -o "Counter_2Seg.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Counter_2Seg.lss: Counter_2Seg.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Counter_2Seg.elf  >"Counter_2Seg.lss"
	@echo 'Finished building: $@'
	@echo ' '

Counter_2Seg.hex: Counter_2Seg.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Counter_2Seg.elf  "Counter_2Seg.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Counter_2Seg.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Counter_2Seg.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Counter_2Seg.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
