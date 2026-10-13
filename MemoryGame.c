#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void pinakes(int size);
void emf(int size, int pin1[][size]);


int main(void)
{
    int tr = 0, ch, lvl = 4;

    for(;;)
    {
        printf("\n\nMEMORY GAME MENU\n\
        \r-------------------------------------------\n\
        \r1. Play  2. Level  3. Statistics  4. Exit\n\n\
        \rEnter Choice: ");

        scanf("%d", &ch);
        if(ch != 1 && ch != 2 && ch != 3 && ch != 4)
        {
            do
            {
                printf("Please choose between [1,4]\n");
                scanf("%d", &ch);
            } while (ch != 1 && ch != 2 && ch != 3 && ch != 4);     
        }

        switch(ch)
        {
            case 1:
                pinakes(lvl);
            break;
        
            case 2:
                printf("\n\nLEVEL MENU\n\
                \r--------------------------------------------\n\
                \r1. Easy (2x2) 2. Medium (4x4) 3. Hard (6x6)\n\
                \rEnter Level: ");

                scanf("%d", &lvl);
                if(lvl != 1 && lvl != 2 && lvl != 3)
                {
                    do
                    {
                        printf("Please choose between [1,3]\n");
                        scanf("%d", &ch);
                    } while (lvl != 1 && lvl != 2 && lvl != 3);     
                }
                lvl *= 2;
            break;
            
            case 3:
                printf("\n\nLevel: %d\n", lvl);
                if(!tr)
                    printf("No score available!!!\n");
                else
                    printf("CONGRATS!!! You've done it after %d tries!!\n", tr);
            break;
            
            case 4:
                return 0;
        }
    }
}

void pinakes(int size)
{
    int i, j, k, n, pin1[size][size], pin2[size][size], counter;

    srand(time(NULL));

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            pin2[i][j] = '*';
            pin1[i][j] = 1 + rand()% ((size*size)/2);
            counter = 0;
            for(k = i; k > 0; k--)
            {
                for(n = j; n > 0; n--)
                {
                    if(pin1[k][n] == pin1[i][j])
                        counter++;
                    printf("C: %d and num: %d with num: %d\n", counter, pin1[i][j], pin1[k][n]);
                    if(counter == 2)
                    {
                        pin1[i][j] = 1 + rand()% ((size*size)/2);
                        n = j;
                        k = i;
                        counter = 0;
                    }
                }
            }
        }
    }

    emf(size, pin1);
}

void emf(int size, int pin1[][size])
{
    int i, j;

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            printf("%3d", pin1[i][j]);
        }
        printf("\n");
    }
}