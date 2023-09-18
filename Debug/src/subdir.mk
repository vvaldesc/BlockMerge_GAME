################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BlockMergeBase.cpp \
../src/Juego.cpp \
../src/Pruebas_Casillas.cpp \
../src/Pruebas_Tablero.cpp \
../src/TAD_Casilla.cpp \
../src/TAD_Tablero.cpp \
../src/entorno.cpp 

OBJS += \
./src/BlockMergeBase.o \
./src/Juego.o \
./src/Pruebas_Casillas.o \
./src/Pruebas_Tablero.o \
./src/TAD_Casilla.o \
./src/TAD_Tablero.o \
./src/entorno.o 

CPP_DEPS += \
./src/BlockMergeBase.d \
./src/Juego.d \
./src/Pruebas_Casillas.d \
./src/Pruebas_Tablero.d \
./src/TAD_Casilla.d \
./src/TAD_Tablero.d \
./src/entorno.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


