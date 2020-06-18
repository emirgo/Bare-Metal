# Bare-Metal
 ARM Cortex-M4 Bare Metal

## Documentation
 I am highly aware putting my code only isn't going to cut it to demonstrate my work. I will be documenting how I figured out each project as I go along and all will be summed up in this README file. So that if you are a non-technical person you can still review my problem solving skills in a way. Even if you are an engineer you might find this document more pleasing than browsing files.

### Blink
Exploration begins with a blink project. It is the hello world here. After reviewing the documentation belonging to STM32F446RET6 I found out that GPIOA is connected to AHB1 bus. So I enable the clock for AHB1 and write to MODE REGISTER of GPIOA. 
Finally, I can blink! Inside the infinite while loop I write to ODR's 6th bit and then run a pseudo delay function and finally write low to ODR's 6th bit and end the loop with the delay again. 

### Blink with BSRR
I enable the clock for AHB1 and write to MODE REGISTER of GPIOA. However, difference from previous one is that I write to BSRR to enable disable the output of PA5. In this case 6th bit of BSRR is enable and 22nd bit is disable for PA5.
In the loop I first enable, delay, disable and delay again. Same pseudo delay function is utilized here.

### GPIO Input (Push Button)
Push button on my board is connected to PC13 according to ST's schematics. PC13 (button) and PA5 (LED) are on AHB1 bus. So enable them separately for readability. After that I set PA5 as output via the MODER. 
Inside the looop if I read PC13 as high I set the BSRR for PA5 and if I don't detect PC13 as high I will disable it.
This way LED is giving some feedback regarding if button is pushed or not.

### UART
Here, fun begins. But this is currently in-development since it is my exam time it may take a while :)
