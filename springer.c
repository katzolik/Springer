#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <signal.h>
int main() {
    clock_t begin = clock();
    int x;
    int y;
    int ex;
    int ey;
    int r;
    int count = 0;
    int counttemp = 0;
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
    int fork();
    int getpid();
    printf("Größe eingeben (5-9): ");
    scanf("%d",&size);
    if (size < 5)
    {
        printf("Zu klein.\n");
        main();
    }
    if (size > 9)
    {
        printf("Zu groß.\n");
        main();
    }
    printf("X eingaben (1-%d): ",size);
    scanf("%d",&ex);
    if (ex < 1)
    {
        printf("Zu klein.\n");
        main();
    }
    if (ex > size)
    {
        printf("Zu groß.\n");
        main();
    }
    printf("Y eingeben (1-%d): ",size);
    scanf("%d",&ey);
    if (ey < 1)
    {
        printf("Zu klein.\n");
        main();
    }
    if (ey > size)
    {
        printf("Zu groß.\n");
        main();
    }
    x = ex - 1;
    y = ey - 1;
    int siz = size - 1;
    int size1 = siz + 1;
    int arrsize = size1 * size1;
    int end = arrsize - 1;
    int sx = x;
    int sy = y;
    int cx[arrsize];
    int cy[arrsize];
    int board[size][size];
    for (size_t j = 0; j <= end; j++)
    {
        cx[j] = -1;
        cy[j] = -1;
    }
    cx[0] = x;
    cy[0] = y;
    void solve()
    {
        srandom(time(NULL) ^ (getpid()<<16));
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
                count = 0;
                counttemp = 0;
                i = 0;
                j = 0;
                for (size_t j = 0; j <= end; j++)
                    {
                        cx[j] = -1;
                        cy[j] = -1;
                    }
                cx[0] = x;
                cy[0] = y;
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
                        break;
                    }
                    else
                    {
                        t7 = 1;
                    }
                    break;
            }
        }
        // for (i = 0; i <= end; i++)
        // {   
        //     printf("sprung %d\n",i+1);
        //     printf("x = %d\n",cx[i]+1);
        //     printf("y = %d\n",cy[i]+1);
        //     printf("--------\n");
        // }
        for (i = 0; i <= end; i++)
        {
            board[cy[i]][cx[i]] = i+1;
        }
        printf("----------------------\n");
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                printf("%d,", board[i][j]);
            }
            printf("\n");
        }
        printf("----------------------\n");
        printf("YEAH BOIIIIIIIIIIIIIIIIIIIIIIIIIII!!\n\n");
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Rechenzeit = %f\n", time_spent);
        kill(0, SIGTERM);
        exit(1);
    }
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    solve();
}
