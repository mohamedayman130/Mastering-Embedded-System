################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
modes_and_states_trial.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
modes_and_states_trial.list \

OBJCOPY_HEX += \
modes_and_states_trial.hex \

OBJCOPY_BIN += \
modes_and_states_trial.bin \


# All Target
all: modes_and_states_trial.elf secondary-outputs

# Tool invocations
modes_and_states_trial.elf: $(OBJS) $(USER_OBJS) C:\Users\user\Desktop\arm\modes_and_states_trial\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "modes_and_states_trial.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\user\Desktop\arm\modes_and_states_trial\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="modes_and_states_trial.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

modes_and_states_trial.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "modes_and_states_trial.list"
	@echo 'Finished building: $@'
	@echo ' '

modes_and_states_trial.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "modes_and_states_trial.hex"
	@echo 'Finished building: $@'
	@echo ' '

modes_and_states_trial.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "modes_and_states_trial.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
