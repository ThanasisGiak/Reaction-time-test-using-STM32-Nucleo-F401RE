## Reaction time test using STM32 Nucleo F401RE
For this **university project** the goal was to create a reaction time test using STM32 Nucleo F401RE.To achieve this puprose,board's LED(LD2) and User Button(B1) have been used.User must push the User Button whenever the LED change state.This expirement goes on for five times and finally the average reaction time is calculated.Note that between every expirement random time passes.Also,there are two kinds of tests,one that the LED starts turned on and user must push User Button whenever LED turns off and the exact opposite where user must push User Button whenever LED turns on.The choice between the two tests can be made in *main.c* file where is possible to define expirement *EX* as *Led_on* or *Led_off*.To measure reaction time, *cycles.c* and *cycles.h* have been created that use Data Watchpoint and Trace(DWT) Unit of ARM CORTEX M4.

## References
1. [Official Arm keil site](http://www.keil.com/)
2. [ARM M4 Instructions per Cycle (IPC) counters-stackoverflow](https://stackoverflow.com/questions/32610019/arm-m4-instructions-per-cycle-ipc-counters)
3. [STM32 Nucleo-64 boards User Manual](https://www.st.com/resource/en/user_manual/dm00105823-stm32-nucleo64-boards-mb1136-stmicroelectronics.pdf)


### For this project ARM Keil MDK and ARM University Program Libraries have been used.
