################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Agenda.cpp \
../Cliente.cpp \
../Cliente_test.cpp \
../GestorDBFichero.cpp \
../GestorDBInterfaz.cpp 

CC_SRCS += \
../Agenda-ppal.cc 

OBJS += \
./Agenda-ppal.o \
./Agenda.o \
./Cliente.o \
./Cliente_test.o \
./GestorDBFichero.o \
./GestorDBInterfaz.o 

CC_DEPS += \
./Agenda-ppal.d 

CPP_DEPS += \
./Agenda.d \
./Cliente.d \
./Cliente_test.d \
./GestorDBFichero.d \
./GestorDBInterfaz.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


