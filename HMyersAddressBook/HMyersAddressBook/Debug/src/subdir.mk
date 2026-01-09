################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/HMyersAddressBook.c \
../src/main.c 

C_DEPS += \
./src/HMyersAddressBook.d \
./src/main.d 

OBJS += \
./src/HMyersAddressBook.o \
./src/main.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/HMyersAddressBook.d ./src/HMyersAddressBook.o ./src/main.d ./src/main.o

.PHONY: clean-src

