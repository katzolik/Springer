#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    clock_t begin = clock();
    srandom(time(NULL));
    // int x = random() % 8;
    // int y = random() % 8;
    int r = random() % 8;
    int x = 0;
    int y = 0;
    int count = 0;
    int counttemp = 0;
    int cx[64];
    int cy[64];
    int i = 0;
    int j = 0;
    int t0 = 0;
    int t1 = 0;
    int t2 = 0;
    int t3 = 0;
    int t4 = 0;
    int t5 = 0;
    int t6 = 0;
    int t7 = 0;
    int w = 0;
    int size;
    printf("Größe eingeben (5-8): ");
    scanf("%d",&size);
    printf("X eingaben (1-%d): ",size);
    scanf("%d",&x+1);
    printf("Y eingeben (1-%d): ",size);
    scanf("%d",&y+1);
    int siz = size - 1;
    int size1 = siz + 1;
    int end = size1 * size1 - 1;
    int sx = x;
    int sy = y;
    // printf("end = %d\n",end);
    // int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 }; 
    // int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 }; 
    for (size_t j = 0; j < 64; j++)
    {
        cx[j] = -1;
        cy[j] = -1;
    }
    cx[0] = x;
    cy[0] = y;
    // printf("x = %d\ny = %d\ncount = %d\ncx = %d\ncy =  %d ",x,y,count,cx[count],cy[count]);
    
    int solve()
    {
        while (count < end)
        {
            if (count != counttemp)
            {
                t0 = 0;
                t1 = 0;
                t2 = 0;
                t3 = 0;
                t4 = 0;
                t5 = 0;
                t6 = 0;
                t7 = 0;
                counttemp = count;
            }
            
            if (t0 == 1 && t1 == 1 && t2 == 1 && t3 == 1 && t4 == 1 && t5 == 1 & t6 == 1 && t7 ==1)
            {
                x = sx;
                y = sy;
                t0 = 0;
                t1 = 0;
                t2 = 0;
                t3 = 0;
                t4 = 0;
                t5 = 0;
                t6 = 0;
                t7 = 0;
                w = 0;
                count = 0;
                counttemp = 0;
                i = 0;
                j = 0;
                for (size_t j = 0; j < end; j++)
                    {
                        cx[j] = -1;
                        cy[j] = -1;
                    }
                cx[0] = x;
                cy[0] = y;
                // printf("x = %d\ny = %d\ncount = %d\ncx = %d\ncy =  %d ",x,y,count,cx[count],cy[count]);
            }

            r = random() % 8;
            w = 0;
            switch (r)
            {
                case 0:
                    w = 0;
                    for (i = 0; i <= end; i++)
                    {
                        if (x+2 == cx[i] && y+1 == cy[i])
                        {
                            w = 1;
                        }
                    }
                    if (x+2 >= 0 && x+2 <= siz && y+1 >= 0 && y+1 <= siz && w == 0)
                    {
                        x = x+2;
                        y = y+1;
                        count++;
                        cx[count] = x;
                        cy[count] = y;
                        // printf("\n---------\n");
                        // printf("x = %d\ny = %d\ncount = %d\ncx = %d\ncy =  %d ",x,y,count,cx[count],cy[count]); 
                        // printf("\n---------\n");
                        break;
                    }
                    else
                    {
                        t0 = 1;
                    }
                    
                    break;
                    
                case 1:
                    w = 0;
                    for (i = 0; i <= end; i++)
                    {
                        if (x+1 == cx[i] && y+2 == cy[i])
                        {
                            w = 1;
                        }
                    }
                    if (x+1 >= 0 && x+1 <= siz && y+2 >= 0 && y+2 <= siz && w == 0)
                    {
                        x = x+1;
                        y = y+2;
                        count++;
                        cx[count] = x;
                        cy[count] = y;
                        // printf("\n---------\n");
                        // printf("x = %d\ny = %d\ncount = %d\ncx = %d\ncy =  %d ",x,y,count,cx[count],cy[count]); 
                        // printf("\n---------\n");
                        break;
                    }
                    else
                    {
                        t1 = 1;
                    }
                    
                    break;
                
                case 2:
                    w = 0;
                    for (i = 0; i <= end; i++)
                    {
                        if (x-1 == cx[i] && y+2 == cy[i])
                        {
                            w = 1;
                        }
                    }
                    if (x-1 >= 0 && x-1 <= siz && y+2 >= 0 && y+2 <= siz && w == 0)
                    {
                        x = x-1;
                        y = y+2;
                        count++;
                        cx[count] = x;
                        cy[count] = y;
                        // printf("\n---------\n");
                        // printf("x = %d\ny = %d\ncount = %d\ncx = %d\ncy =  %d ",x,y,count,cx[count],cy[count]); 
                        // printf("\n---------\n");
                        break;
                    }
                    else
                    {
                        t2 = 1;
                    }
                    
                    break;

                case 3:
                    w = 0;
                    for (i = 0; i <= end; i++)
                    {
                        if (x-2 == cx[i] && y+1 == cy[i])
                        {
                            w = 1;
                        }
                    }
                    if (x-2 >= 0 && x-2 <= siz && y+1 >= 0 && y+1 <= siz && w == 0)
                    {
                        x = x-2;
                        y = y+1;
                        count++;
                        cx[count] = x;
                        cy[count] = y;
                        // printf("\n---------\n");
                        // printf("x = %d\ny = %d\ncount = %d\ncx = %d\ncy =  %d ",x,y,count,cx[count],cy[count]); 
                        // printf("\n---------\n");
                        break;
                    }
                    else
                    {
                        t3 = 1;
                    }
                    
                    break;
       
                case 4:
                    w = 0;
                    for (i = 0; i <= end; i++)
                    {
                        if (x-2 == cx[i] && y-1 == cy[i])
                        {
                            w = 1;
                        }
                    }
                    if (x-2 >= 0 && x-2 <= siz && y-1 >= 0 && y-1 <= siz && w == 0)
                    {
                        x = x-2;
                        y = y-1;
                        count++;
                        cx[count] = x;
                        cy[count] = y;
                        // printf("\n---------\n");
                        // printf("x = %d\ny = %d\ncount = %d\ncx = %d\ncy =  %d ",x,y,count,cx[count],cy[count]); 
                        // printf("\n---------\n");
                        break;
                    }
                    else
                    {
                        t4 = 1;
                    }
                    
                    break;

                case 5:
                    w = 0;
                    for (i = 0; i <= end; i++)
                    {
                        if (x-1 == cx[i] && y-2 == cy[i])
                        {
                            w = 1;
                        }
                    }
                    if (x-1 >= 0 && x-1 <= siz && y-2 >= 0 && y-2 <= siz && w == 0)
                    {
                        x = x-1;
                        y = y-2;
                        count++;
                        cx[count] = x;
                        cy[count] = y;
                        // printf("\n---------\n");
                        // printf("x = %d\ny = %d\ncount = %d\ncx = %d\ncy =  %d ",x,y,count,cx[count],cy[count]); 
                        // printf("\n---------\n");
                        break;   
                    }
                    else
                    {
                        t5 = 1;
                    }
                    
                    break;

                case 6:
                    w = 0;
                    for (i = 0; i <= end; i++)
                    {
                        if (x+1 == cx[i] && y-2 == cy[i])
                        {
                            w = 1;
                        }
                    }
                    if (x+1 >= 0 && x+1 <= siz && y-2 >= 0 && y-2 <= siz && w == 0)
                    {
                        x = x+1;
                        y = y-2;
                        count++;
                        cx[count] = x;
                        cy[count] = y;
                        // printf("\n---------\n");
                        // printf("x = %d\ny = %d\ncount = %d\ncx = %d\ncy =  %d ",x,y,count,cx[count],cy[count]); 
                        // printf("\n---------\n");
                        break;
                    }
                    else
                    {
                        t6 = 1;
                    }
                    
                    break;

                case 7:
                    w = 0;
                    for (i = 0; i <= end; i++)
                    {
                        if (x+2 == cx[i] && y-1 == cy[i])
                        {
                            w = 1;
                        }
                    }
                    if (x+2 >= 0 && x+2 <= siz && y-1 >= 0 && y-1 <= siz && w == 0)
                    {
                        x = x+2;
                        y = y-1;
                        count++;
                        cx[count] = x;
                        cy[count] = y;
                        t7 = 1;
                        // printf("\n---------\n");
                        // printf("x = %d\ny = %d\ncount = %d\ncx = %d\ncy =  %d ",x,y,count,cx[count],cy[count]); 
                        // printf("\n---------\n");
                        break;
                    }
                    else
                    {
                        t7 = 1;
                    }
                    
                    break;
            }
        }
        for (i = 0; i <= end; i++)
        {   
            printf("sprung %d\n",i+1);
            printf("x = %d\n",cx[i]+1);
            printf("y = %d\n",cy[i]+1);
            printf("--------\n");
        }
        printf("YEAH BOIIIIIIIIIIIIIIIIIIIIIIIIIII!!\n\n");
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Rechenzeit = %f\n", time_spent);
        exit(1);
    }
    solve();
}
