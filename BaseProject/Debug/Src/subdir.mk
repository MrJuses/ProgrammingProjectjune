################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/30010_io.c \
../Src/Exercises.c \
../Src/ansi.c \
../Src/charset.c \
../Src/main.c \
../Src/menu.c \
../Src/random.c \
../Src/sin.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/system_stm32f30x.c \
../Src/visuals.c 

OBJS += \
./Src/30010_io.o \
./Src/Exercises.o \
./Src/ansi.o \
./Src/charset.o \
./Src/main.o \
./Src/menu.o \
./Src/random.o \
./Src/sin.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/system_stm32f30x.o \
./Src/visuals.o 

C_DEPS += \
./Src/30010_io.d \
./Src/Exercises.d \
./Src/ansi.d \
./Src/charset.d \
./Src/main.d \
./Src/menu.d \
./Src/random.d \
./Src/sin.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/system_stm32f30x.d \
./Src/visuals.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F302R8Tx -DSTM32F3 -DNUCLEO_F302R8 -DDEBUG -DUSE_STDPERIPH_DRIVER=1 -c -I"C:/Users/emilm/eclipse-workspace/June Project/JuneProgProject/ProgrammingProjectjune/BaseProject/SPL/inc" -I"C:/Users/emilm/eclipse-workspace/June Project/JuneProgProject/ProgrammingProjectjune/BaseProject/Inc" -I"C:/Users/emilm/eclipse-workspace/June Project/JuneProgProject/ProgrammingProjectjune/BaseProject/cmsis" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/30010_io.d ./Src/30010_io.o ./Src/30010_io.su ./Src/Exercises.d ./Src/Exercises.o ./Src/Exercises.su ./Src/ansi.d ./Src/ansi.o ./Src/ansi.su ./Src/charset.d ./Src/charset.o ./Src/charset.su ./Src/main.d ./Src/main.o ./Src/main.su ./Src/menu.d ./Src/menu.o ./Src/menu.su ./Src/random.d ./Src/random.o ./Src/random.su ./Src/sin.d ./Src/sin.o ./Src/sin.su ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/system_stm32f30x.d ./Src/system_stm32f30x.o ./Src/system_stm32f30x.su ./Src/visuals.d ./Src/visuals.o ./Src/visuals.su

.PHONY: clean-Src

