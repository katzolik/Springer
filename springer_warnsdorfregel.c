#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
int main()
{
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
  int pre = 0;
  int end0 = 0;
  int end1 = 0;
  int end2 = 0;
  int end3 = 0;
  int end4 = 0;
  int end5 = 0;
  int end6 = 0;
  int end7 = 0;
  int w = 0;
  int size;
  int fork();
  int getpid();
  int xTemp = 0;
  int yTemp = 0;
  printf("board size? (5-9): ");
  scanf("%d", &size);
  if (size < 5)
  {
    printf("Too small.\n");
    main();
  }
  if (size > 9)
  {
    printf("Too big.\n");
    main();
  }
  printf("X start point (1-%d): ", size);
  scanf("%d", &ex);
  if (ex < 1)
  {
    printf("Too small.\n");
    main();
  }
  if (ex > size)
  {
    printf("Too big.\n");
    main();
  }
  printf("Y start point (1-%d): ", size);
  scanf("%d", &ey);
  if (ey < 1)
  {
    printf("Too small.\n");
    main();
  }
  if (ey > size)
  {
    printf("Too big.\n");
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
  int movecount()
  //counts the possible moves forward
  {
    pre = 0;
    w = 0;
    for (i = 0; i <= end; i++)
    {
      if (xTemp + 2 == cx[i] && yTemp + 1 == cy[i])
      {
        w = 1;
      }
    }
    if (xTemp + 2 >= 0 && xTemp + 2 <= siz && yTemp + 1 >= 0 && yTemp + 1 <= siz && w == 0)
    {
      pre++;
    }
    w = 0;
    for (i = 0; i <= end; i++)
    {
      if (xTemp + 1 == cx[i] && yTemp + 2 == cy[i])
      {
        w = 1;
      }
    }
    if (xTemp + 1 >= 0 && xTemp + 1 <= siz && yTemp + 2 >= 0 && yTemp + 2 <= siz && w == 0)
    {
      pre++;
    }
    w = 0;
    for (i = 0; i <= end; i++)
    {
      if (xTemp - 1 == cx[i] && yTemp + 2 == cy[i])
      {
        w = 1;
      }
    }
    if (xTemp - 1 >= 0 && xTemp - 1 <= siz && yTemp + 2 >= 0 && yTemp + 2 <= siz && w == 0)
    {
      pre++;
    }
    w = 0;
    for (i = 0; i <= end; i++)
    {
      if (xTemp - 2 == cx[i] && yTemp + 1 == cy[i])
      {
        w = 1;
      }
    }
    if (xTemp - 2 >= 0 && xTemp - 2 <= siz && yTemp + 1 >= 0 && yTemp + 1 <= siz && w == 0)
    {
      pre++;
    }
    w = 0;
    for (i = 0; i <= end; i++)
    {
      if (xTemp - 2 == cx[i] && yTemp - 1 == cy[i])
      {
        w = 1;
      }
    }
    if (xTemp - 2 >= 0 && xTemp - 2 <= siz && yTemp - 1 >= 0 && yTemp - 1 <= siz && w == 0)
    {
      pre++;
    }
    w = 0;
    for (i = 0; i <= end; i++)
    {
      if (xTemp - 1 == cx[i] && yTemp - 2 == cy[i])
      {
        w = 1;
      }
    }
    if (xTemp - 1 >= 0 && xTemp - 1 <= siz && yTemp - 2 >= 0 && yTemp - 2 <= siz && w == 0)
    {
      pre++;
    }
    w = 0;
    for (i = 0; i <= end; i++)
    {
      if (xTemp + 1 == cx[i] && yTemp - 2 == cy[i])
      {
        w = 1;
      }
    }
    if (xTemp + 1 >= 0 && xTemp + 1 <= siz && yTemp - 2 >= 0 && yTemp - 2 <= siz && w == 0)
    {
      pre++;
    }
    w = 0;
    for (i = 0; i <= end; i++)
    {
      if (xTemp + 2 == cx[i] && yTemp - 1 == cy[i])
      {
        w = 1;
      }
    }
    if (xTemp + 2 >= 0 && xTemp + 2 <= siz && yTemp - 1 >= 0 && yTemp - 1 <= siz && w == 0)
    {
      pre++;
    }
    if (pre == 0)
    {
      pre = 11;
    }
    return pre;
  }
  int checkifmove()
  //checks if move is inside the board an if the square has been visited before
  {
    end0 = 0;
    end1 = 0;
    end2 = 0;
    end3 = 0;
    end4 = 0;
    end5 = 0;
    end6 = 0;
    end7 = 0;
    w = 0;
    if (x + 2 >= 0 && x + 2 <= siz && y + 1 >= 0 && y + 1 <= siz)
    {
      for (i = 0; i <= end; i++)
      {
        if (x + 2 == cx[i] && y + 1 == cy[i])
        {
          w = 1;
        }
      }
      if (w == 0)
      {
        xTemp = x + 2;
        yTemp = y + 1;
        movecount();
        t0 = movecount();
      }
      else
      {
        end0 = 1;
        t0 = 11;
      }
    }
    w = 0;
    if (x + 1 >= 0 && x + 1 <= siz && y + 2 >= 0 && y + 2 <= siz)
    {
      for (i = 0; i <= end; i++)
      {
        if (x + 1 == cx[i] && y + 2 == cy[i])
        {
          w = 1;
        }
      }
      if (w == 0)
      {
        xTemp = x + 1;
        yTemp = y + 2;
        movecount();
        t1 = movecount();
      }
      else
      {
        end1 = 1;
        t1 = 11;
      }
    }
    w = 0;
    if (x - 1 >= 0 && x - 1 <= siz && y + 2 >= 0 && y + 2 <= siz)
    {
      for (i = 0; i <= end; i++)
      {
        if (x - 1 == cx[i] && y + 2 == cy[i])
        {
          w = 1;
        }
      }
      if (w == 0)
      {
        xTemp = x - 1;
        yTemp = y + 2;
        movecount();
        t2 = movecount();
      }
      else
      {
        end2 = 1;
        t2 = 11;
      }
    }
    w = 0;
    if (x - 2 >= 0 && x - 2 <= siz && y + 1 >= 0 && y + 1 <= siz)
    {
      for (i = 0; i <= end; i++)
      {
        if (x - 2 == cx[i] && y + 1 == cy[i])
        {
          w = 1;
        }
      }
      if (w == 0)
      {
        xTemp = x - 2;
        yTemp = y + 1;
        movecount();
        t3 = movecount();
      }
      else
      {
        end3 = 1;
        t3 = 11;
      }
    }
    w = 0;
    if (x - 2 >= 0 && x - 2 <= siz && y - 1 >= 0 && y - 1 <= siz)
    {
      for (i = 0; i <= end; i++)
      {
        if (x - 2 == cx[i] && y - 1 == cy[i])
        {
          w = 1;
        }
      }
      if (w == 0)
      {
        xTemp = x - 2;
        yTemp = y - 1;
        movecount();
        t4 = movecount();
      }
      else
      {
        end4 = 1;
        t4 = 11;
      }
    }
    w = 0;
    if (x - 1 >= 0 && x - 1 <= siz && y - 2 >= 0 && y - 2 <= siz)
    {
      for (i = 0; i <= end; i++)
      {
        if (x - 1 == cx[i] && y - 2 == cy[i])
        {
          w = 1;
        }
      }
      if (w == 0)
      {
        xTemp = x - 1;
        yTemp = y - 2;
        movecount();
        t5 = movecount();
      }
      else
      {
        end5 = 1;
        t5 = 11;
      }
    }
    w = 0;
    if (x + 1 >= 0 && x + 1 <= siz && y - 2 >= 0 && y - 2 <= siz)
    {
      for (i = 0; i <= end; i++)
      {
        if (x + 1 == cx[i] && y - 2 == cy[i])
        {
          w = 1;
        }
      }
      if (w == 0)
      {
        xTemp = x + 1;
        yTemp = y - 2;
        movecount();
        t6 = movecount();
      }
      else
      {
        end6 = 1;
        t6 = 11;
      }
    }
    w = 0;
    if (x + 2 >= 0 && x + 2 <= siz && y - 1 >= 0 && y - 1 <= siz)
    {
      for (i = 0; i <= end; i++)
      {
        if (x + 2 == cx[i] && y - 1 == cy[i])
        {
          w = 1;
        }
      }
      if (w == 0)
      {
        xTemp = x + 2;
        yTemp = y - 1;
        movecount();
        t7 = movecount();
      }
      else
      {
        end7 = 1;
        t7 = 11;
      }
    }
  }
  int checkifdeadend()
  //checks if the knight cant move forward anymore
  {
    if (end0 == 1 && end1 == 1 && end2 == 1 && end3 == 1 && end4 == 1 && end5 == 1 && end6 == 1 && end7 == 1)
    {
      end0 = 0;
      end1 = 0;
      end2 = 0;
      end3 = 0;
      end4 = 0;
      end5 = 0;
      end6 = 0;
      end7 = 0;
      x = sx;
      y = sy;
      w = 0;
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
  }
  int domove()
  //does random move to the squares with the least moves forward possible
  {
    r = random() % 8;
    switch (r)
    {
    case 0:
      if (t0 <= t1 && t0 <= t2 && t0 <= t3 && t0 <= t4 && t0 <= t5 && t0 <= t6 && t0 <= t7 && t0 != 11)
      {
        x = x + 2;
        y = y + 1;
        count++;
        cx[count] = x;
        cy[count] = y;
      }
      break;
    case 1:
      if (t1 <= t0 && t1 <= t2 && t1 <= t3 && t1 <= t4 && t1 <= t5 && t1 <= t6 && t1 <= t7 && t1 != 11)
      {
        x = x + 1;
        y = y + 2;
        count++;
        cx[count] = x;
        cy[count] = y;
      }
      break;
    case 2:
      if (t2 <= t0 && t2 <= t1 && t2 <= t3 && t2 <= t4 && t2 <= t5 && t2 <= t6 && t2 <= t7 && t2 != 11)
      {
        x = x - 1;
        y = y + 2;
        count++;
        cx[count] = x;
        cy[count] = y;
      }
      break;
    case 3:
      if (t3 <= t0 && t3 <= t1 && t3 <= t2 && t3 <= t4 && t3 <= t5 && t3 <= t6 && t3 <= t7 && t3 != 11)
      {
        x = x - 2;
        y = y + 1;
        count++;
        cx[count] = x;
        cy[count] = y;
      }
      break;
    case 4:
      if (t4 <= t0 && t4 <= t1 && t4 <= t2 && t4 <= t3 && t4 <= t5 && t4 <= t6 && t4 <= t7 && t4 != 11)
      {
        x = x - 2;
        y = y - 1;
        count++;
        cx[count] = x;
        cy[count] = y;
      }
      break;
    case 5:
      if (t5 <= t0 && t5 <= t1 && t5 <= t2 && t5 <= t3 && t5 <= t4 && t5 <= t6 && t5 <= t7 && t5 != 11)
      {
        x = x - 1;
        y = y - 2;
        count++;
        cx[count] = x;
        cy[count] = y;
      }
      break;
    case 6:
      if (t6 <= t0 && t6 <= t1 && t6 <= t2 && t6 <= t3 && t6 <= t4 && t6 <= t5 && t6 <= t7 && t6 != 11)
      {
        x = x + 1;
        y = y - 2;
        count++;
        cx[count] = x;
        cy[count] = y;
      }
      break;
    case 7:
      if (t7 <= t0 && t7 <= t1 && t7 <= t2 && t7 <= t3 && t7 <= t4 && t7 <= t5 && t7 <= t6 && t7 != 11)
      {
        x = x + 2;
        y = y - 1;
        count++;
        cx[count] = x;
        cy[count] = y;
      }
      break;
    }
  }

  void solve()
  {
    srandom(time(NULL) ^ (getpid() << 16));
    while (count < end)
    {
      checkifmove();
      checkifdeadend();
      domove();
    }
    for (i = 0; i <= end; i++)
    {
      printf("sprung %d\n", i + 1);
      printf("x = %d\n", cx[i] + 1);
      printf("y = %d\n", cy[i] + 1);
      printf("--------\n");
    }
    for (i = 0; i <= end; i++)
    {
      board[cy[i]][cx[i]] = i + 1;
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
  // fork();
  // fork();
  // fork();
  // fork();
  // fork();
  // fork();
  solve();
}
