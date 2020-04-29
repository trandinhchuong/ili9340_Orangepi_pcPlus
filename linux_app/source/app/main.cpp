//cc -o demo_basic demo_basic.c fontx.c ili9340.c -lwiringPi -lm -lpthread -DSPI -DWPI


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include "ILI9341_GFX.h"
#include "ILI9341_STM32_Driver.h"



int main()
{
    ILI9341_Init();


    ILI9341_Fill_Screen(BLACK);
    ILI9341_Set_Rotation(SCREEN_HORIZONTAL_2);
    ILI9341_Draw_Text("FPS TEST, 40 loop 2 screens", 10, 10, BLACK, 1, WHITE);
    HAL_Delay(2000);
    ILI9341_Fill_Screen(BLACK);

    while(1)

    {

        for(uint16_t i = 0; i < 10; i++)
            {
                ILI9341_Fill_Screen(WHITE);
                ILI9341_Fill_Screen(BLACK);
            }

        HAL_Delay(100);
    }
}
