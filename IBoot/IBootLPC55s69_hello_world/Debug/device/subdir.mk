################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../device/system_LPC55S69_cm33_core0.c 

OBJS += \
./device/system_LPC55S69_cm33_core0.o 

C_DEPS += \
./device/system_LPC55S69_cm33_core0.d 


# Each subdirectory must supply rules for building sources it contributes
device/%.o: ../device/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_LPC55S69JBD100 -DCPU_LPC55S69JBD100_cm33 -DCPU_LPC55S69JBD100_cm33_core0 -DMCUXPRESSO_SDK -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"E:\Ishwarya\IBootRepo\IBootLPC55s69_hello_world\board" -I"E:\Ishwarya\IBootRepo\IBootLPC55s69_hello_world\source" -I"E:\Ishwarya\IBootRepo\IBootLPC55s69_hello_world\utilities" -I"E:\Ishwarya\IBootRepo\IBootLPC55s69_hello_world\drivers" -I"E:\Ishwarya\IBootRepo\IBootLPC55s69_hello_world\LPC55S69\drivers" -I"E:\Ishwarya\IBootRepo\IBootLPC55s69_hello_world\device" -I"E:\Ishwarya\IBootRepo\IBootLPC55s69_hello_world\startup" -I"E:\Ishwarya\IBootRepo\IBootLPC55s69_hello_world\component\uart" -I"E:\Ishwarya\IBootRepo\IBootLPC55s69_hello_world\component\lists" -I"E:\Ishwarya\IBootRepo\IBootLPC55s69_hello_world\CMSIS" -O0 -fno-common -g3 -mcpu=cortex-m33 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


