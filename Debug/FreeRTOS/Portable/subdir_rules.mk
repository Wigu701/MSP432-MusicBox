################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/Portable/%.obj: ../FreeRTOS/Portable/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/Program Files/ti/ccs1110/ccs/tools/compiler/ti-cgt-arm_20.2.5.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/Program Files/ti/ccs1110/ccs/ccs_base/arm/include" --include_path="D:/Program Files/ti/ccs1110/ccs/ccs_base/arm/include/CMSIS" --include_path="D:/Program Files/ti/ccs1110/ccs/tools/compiler/ti-cgt-arm_20.2.5.LTS/include" --include_path="C:/Users/wigu7/Projects/CS 353/FreeRTOS/MusicBox/FreeRTOS" --include_path="C:/Users/wigu7/Projects/CS 353/FreeRTOS/MusicBox/FreeRTOS/Include" --include_path="C:/Users/wigu7/Projects/CS 353/FreeRTOS/MusicBox/FreeRTOS/Portable" --include_path="C:/Users/wigu7/Projects/CS 353/FreeRTOS/MusicBox" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="FreeRTOS/Portable/$(basename $(<F)).d_raw" --obj_directory="FreeRTOS/Portable" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

FreeRTOS/Portable/%.obj: ../FreeRTOS/Portable/%.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/Program Files/ti/ccs1110/ccs/tools/compiler/ti-cgt-arm_20.2.5.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/Program Files/ti/ccs1110/ccs/ccs_base/arm/include" --include_path="D:/Program Files/ti/ccs1110/ccs/ccs_base/arm/include/CMSIS" --include_path="D:/Program Files/ti/ccs1110/ccs/tools/compiler/ti-cgt-arm_20.2.5.LTS/include" --include_path="C:/Users/wigu7/Projects/CS 353/FreeRTOS/MusicBox/FreeRTOS" --include_path="C:/Users/wigu7/Projects/CS 353/FreeRTOS/MusicBox/FreeRTOS/Include" --include_path="C:/Users/wigu7/Projects/CS 353/FreeRTOS/MusicBox/FreeRTOS/Portable" --include_path="C:/Users/wigu7/Projects/CS 353/FreeRTOS/MusicBox" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="FreeRTOS/Portable/$(basename $(<F)).d_raw" --obj_directory="FreeRTOS/Portable" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


