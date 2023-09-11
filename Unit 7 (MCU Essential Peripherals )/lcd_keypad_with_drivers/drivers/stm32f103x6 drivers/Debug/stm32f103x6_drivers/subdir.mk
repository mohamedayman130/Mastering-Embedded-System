################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32f103x6_drivers/keypad.c \
../stm32f103x6_drivers/lcd.c \
../stm32f103x6_drivers/stm32f103x6_gpio_driver.c 

OBJS += \
./stm32f103x6_drivers/keypad.o \
./stm32f103x6_drivers/lcd.o \
./stm32f103x6_drivers/stm32f103x6_gpio_driver.o 

C_DEPS += \
./stm32f103x6_drivers/keypad.d \
./stm32f103x6_drivers/lcd.d \
./stm32f103x6_drivers/stm32f103x6_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
stm32f103x6_drivers/keypad.o: ../stm32f103x6_drivers/keypad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/user/Desktop/drivers/stm32f103x6 drivers/stm32f103x6_drivers/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103x6_drivers/keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103x6_drivers/lcd.o: ../stm32f103x6_drivers/lcd.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/user/Desktop/drivers/stm32f103x6 drivers/stm32f103x6_drivers/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103x6_drivers/lcd.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103x6_drivers/stm32f103x6_gpio_driver.o: ../stm32f103x6_drivers/stm32f103x6_gpio_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/user/Desktop/drivers/stm32f103x6 drivers/stm32f103x6_drivers/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103x6_drivers/stm32f103x6_gpio_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

