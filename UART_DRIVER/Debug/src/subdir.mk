################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/App.c \
../src/DIO_Program.c \
../src/LED_Program.c \
../src/SSD_Program.c \
../src/UART_Program.c 

OBJS += \
./src/App.o \
./src/DIO_Program.o \
./src/LED_Program.o \
./src/SSD_Program.o \
./src/UART_Program.o 

C_DEPS += \
./src/App.d \
./src/DIO_Program.d \
./src/LED_Program.d \
./src/SSD_Program.d \
./src/UART_Program.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


