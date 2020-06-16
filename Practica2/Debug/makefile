################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := cs-rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include commonEclipse/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
Practica2.hex \

SECONDARY_LIST += \
Practica2.lst \

SECONDARY_SIZE += \
Practica2.siz \


# All Target
all: Practica2.elf secondary-outputs

# Tool invocations
Practica2.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM Sourcery Windows GCC C Linker'
	arm-none-eabi-gcc -T"C:\Users\usuario_local\Downloads\Practica 2\Practica2\commonEclipse\ram_ice.ld" -nostartfiles -Wl,-Map,Practica2.map -mcpu=arm7tdmi -g3 -gdwarf-2 -o "Practica2.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Practica2.hex: Practica2.elf
	@echo 'Invoking: ARM Sourcery Windows GNU Create Flash Image'
	arm-none-eabi-objcopy -O binary Practica2.elf  "Practica2.hex"
	@echo 'Finished building: $@'
	@echo ' '

Practica2.lst: Practica2.elf
	@echo 'Invoking: ARM Sourcery Windows GNU Create Listing'
	arm-none-eabi-objdump -h -S Practica2.elf > "Practica2.lst"
	@echo 'Finished building: $@'
	@echo ' '

Practica2.siz: Practica2.elf
	@echo 'Invoking: ARM Sourcery Windows GNU Print Size'
	arm-none-eabi-size  --format=berkeley Practica2.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(SECONDARY_SIZE)$(OBJS)$(C_DEPS)$(ASM_DEPS)$(SECONDARY_FLASH)$(EXECUTABLES)$(SECONDARY_LIST)$(S_UPPER_DEPS) Practica2.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
