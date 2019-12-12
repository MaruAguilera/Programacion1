################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Computer.c \
../src/ControllerComputer.c \
../src/LinkedList.c \
../src/parser.c \
../src/segundoParcialRecu.c \
../src/utn.c 

OBJS += \
./src/Computer.o \
./src/ControllerComputer.o \
./src/LinkedList.o \
./src/parser.o \
./src/segundoParcialRecu.o \
./src/utn.o 

C_DEPS += \
./src/Computer.d \
./src/ControllerComputer.d \
./src/LinkedList.d \
./src/parser.d \
./src/segundoParcialRecu.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


