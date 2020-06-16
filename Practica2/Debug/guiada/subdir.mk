################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../guiada/8led.c \
../guiada/keyboard.c \
../guiada/led.c \
../guiada/main.c \
../guiada/timer.c 

ASM_SRCS += \
../guiada/init.asm 

OBJS += \
./guiada/8led.o \
./guiada/init.o \
./guiada/keyboard.o \
./guiada/led.o \
./guiada/main.o \
./guiada/timer.o 

C_DEPS += \
./guiada/8led.d \
./guiada/keyboard.d \
./guiada/led.d \
./guiada/main.d \
./guiada/timer.d 

ASM_DEPS += \
./guiada/init.d 


# Each subdirectory must supply rules for building sources it contributes
guiada/%.o: ../guiada/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Sourcery Windows GCC C Compiler'
	arm-none-eabi-gcc -I"C:\Users\usuario_local\Downloads\Practica 2\Practica2\commonEclipse" -O0 -Wall -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -mapcs-frame -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=arm7tdmi -g3 -gdwarf-2 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

guiada/%.o: ../guiada/%.asm
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Sourcery Windows GCC Assembler'
	arm-none-eabi-gcc -x assembler-with-cpp -I"C:\Users\usuario_local\Downloads\Practica 2\Practica2\commonEclipse" -Wall -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=arm7tdmi -g3 -gdwarf-2 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


