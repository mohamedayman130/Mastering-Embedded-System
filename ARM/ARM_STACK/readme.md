# The system ticker is represented by exti, and this code simulates how to run several jobs quickly, much like an operating system. 
# at first system will run in main_os stack then interrupt will happen and take it to psp(process stack pointer) and excute task a then interrupt will happen again then will go to task b and so on.

## First, set the processor to run in non-privilege mode and set the PSP reg to equal the task address.

![Screenshot 2024-03-05 193818](https://github.com/mohamedayman130/Mastering-Embedded-System/assets/117905345/c08ab6d5-ca38-475b-913d-37b63abf1e01)


## Make sp point to psp as the next step.

![sp to psp](https://github.com/mohamedayman130/Mastering-Embedded-System/assets/117905345/27c96e0c-786b-4f03-af78-e8293f8c3465)


## Third step: an external interrupt will occur following task execution, putting the processor in privilege mode so it can write to registers.

![exceptional_interrupt_to ret priv](https://github.com/mohamedayman130/Mastering-Embedded-System/assets/117905345/84fe7ac4-1a9d-48f7-871c-e53aa0210b72)


## Make a sp point to msp as the fourth step.

![set sp by msp](https://github.com/mohamedayman130/Mastering-Embedded-System/assets/117905345/619816e9-7534-4990-88d7-de092d8ab091)
