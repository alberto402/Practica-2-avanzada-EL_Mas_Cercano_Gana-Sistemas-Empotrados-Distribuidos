################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../8led.c \
../button.c \
../keyboard.c \
../led.c \
../main.c \
../timer.c 

ASM_SRCS += \
../init.asm 

OBJS += \
./8led.o \
./button.o \
./init.o \
./keyboard.o \
./led.o \
./main.o \
./timer.o 

C_DEPS += \
./8led.d \
./button.d \
./keyboard.d \
./led.d \
./main.d \
./timer.d 

ASM_DEPS += \
./init.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Sourcery Windows GCC C Compiler'
	arm-none-eabi-gcc -I"C:\Users\usuario_local\Downloads\Practica 2\Practica2\commonEclipse" -O0 -Wall -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -mapcs-frame -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=arm7tdmi -g3 -gdwarf-2 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.asm
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Sourcery Windows GCC Assembler'
	arm-none-eabi-gcc -x assembler-with-cpp -I"C:\Users\usuario_local\Downloads\Practica 2\Practica2\commonEclipse" -Wall -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=arm7tdmi -g3 -gdwarf-2 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


