################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
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
KEYPAD_Driver_Mazen.lss \

FLASH_IMAGE += \
KEYPAD_Driver_Mazen.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: KEYPAD_Driver_Mazen.elf secondary-outputs

# Tool invocations
KEYPAD_Driver_Mazen.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,KEYPAD_Driver_Mazen.map -mmcu=atmega32 -o "KEYPAD_Driver_Mazen.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

KEYPAD_Driver_Mazen.lss: KEYPAD_Driver_Mazen.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S KEYPAD_Driver_Mazen.elf  >"KEYPAD_Driver_Mazen.lss"
	@echo 'Finished building: $@'
	@echo ' '

KEYPAD_Driver_Mazen.hex: KEYPAD_Driver_Mazen.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex KEYPAD_Driver_Mazen.elf  "KEYPAD_Driver_Mazen.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: KEYPAD_Driver_Mazen.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 KEYPAD_Driver_Mazen.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) KEYPAD_Driver_Mazen.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
