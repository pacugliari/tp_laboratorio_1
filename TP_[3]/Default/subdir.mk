################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Controller.c \
../Passenger.c \
../main.c \
../parser.c 

C_DEPS += \
./Controller.d \
./Passenger.d \
./main.d \
./parser.d 

OBJS += \
./Controller.o \
./Passenger.o \
./main.o \
./parser.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./Controller.d ./Controller.o ./Passenger.d ./Passenger.o ./main.d ./main.o ./parser.d ./parser.o

.PHONY: clean--2e-

