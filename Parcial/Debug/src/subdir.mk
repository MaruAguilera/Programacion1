################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Parcial.c \
../src/cliente.c \
../src/pedido.c \
../src/utn.c 

OBJS += \
./src/Parcial.o \
./src/cliente.o \
./src/pedido.o \
./src/utn.o 

C_DEPS += \
./src/Parcial.d \
./src/cliente.d \
./src/pedido.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


