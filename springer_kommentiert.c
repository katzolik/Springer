#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
int main()
{
  clock_t begin = clock();
  int x;  // x coordinate
  int y;  // y coordinate
  int inputX; //input for x
  int inputY; //input for y
  int randomNumber; //random number ganerated for each process
  int count = 0;  //jump counter
  int countTemp = 0;  //counter to check progress
  int i = 0;  //array increment
  int j = 0;  //array increment
  int terminateTry0 = 0;  //abort condition
  int terminateTry1 = 0;  //abort condition
  int terminateTry2 = 0;  //abort condition
  int terminateTry3 = 0;  //abort condition
  int terminateTry4 = 0;  //abort condition
  int terminateTry5 = 0;  //abort condition
  int terminateTry6 = 0;  //abort condition
  int terminateTry7 = 0;  //abort condition
  int squareVisited = 0;  //bool checks if square was visited
  int size; //inputsize of chessboard
  int fork();
  int getpid();
  //chessboard size input
  printf("Größe eingeben (5-9): ");
  scanf("%d", &size);
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
  //x start input
  printf("X eingaben (1-%d): ", size);
  scanf("%d", &inputX);
  if (inputX < 1)
  {
    printf("Zu klein.\n");
    main();
  }
  if (inputX > size)
  {
    printf("Zu groß.\n");
    main();
  }
  //y start input
  printf("Y eingeben (1-%d): ", size);
  scanf("%d", &inputY);
  if (inputY < 1)
  {
    printf("Zu klein.\n");
    main();
  }
  if (inputY > size)
  {
    printf("Zu groß.\n");
    main();
  }
  x = inputX - 1; //get real x coordinate
  y = inputY - 1; //get real y coordinate
  int siz = size - 1; // size for loops
  int arrsize = size * size;  //size for array of visited squares
  int end = arrsize - 1;  //end condition for loop
  int startX = x; //saved x startpoint
  int startY = y; //saved y startpoint
  int visitedX[arrsize];  //array for x coordiante of visited quares
  int visitedY[arrsize];  //array for y coordiante of visited quares
  int board[size][size];  //array for chessboard output
  //filling array of visited squares with -1 to prevent errors
  for (size_t j = 0; j <= end; j++)
  {
    visitedX[j] = -1;
    visitedY[j] = -1;
  }
  //saving startcoordinates for later use
  visitedX[0] = x;
  visitedY[0] = y;
  void solve()
  {
    //setting seed to time plus process ID to get different seed for each process
    srandom(time(NULL) ^ (getpid() << 16));
    while (count < end)
    {
      //reset of abort conditions for try when move is done
      if (count != countTemp)
      {
        terminateTry0 = 0;
        terminateTry1 = 0;
        terminateTry2 = 0;
        terminateTry3 = 0;
        terminateTry4 = 0;
        terminateTry5 = 0;
        terminateTry6 = 0;
        terminateTry7 = 0;
        countTemp = count;
      }
      //reset everything if no move possible
      if (terminateTry0 == 1 && terminateTry1 == 1 && terminateTry2 == 1 && terminateTry3 == 1 && terminateTry4 == 1 && terminateTry5 == 1 & terminateTry6 == 1 && terminateTry7 == 1)
      {
        x = startX;
        y = startY;
        terminateTry0 = 0;
        terminateTry1 = 0;
        terminateTry2 = 0;
        terminateTry3 = 0;
        terminateTry4 = 0;
        terminateTry5 = 0;
        terminateTry6 = 0;
        terminateTry7 = 0;
        count = 0;
        countTemp = 0;
        i = 0;
        j = 0;
        for (size_t j = 0; j <= end; j++)
        {
          visitedX[j] = -1;
          visitedY[j] = -1;
        }
        visitedX[0] = x;
        visitedY[0] = y;
      }
      randomNumber = random() % 8;  //gernerating random number
      //random move if move is possible for every direction possible
      switch (randomNumber)
      {
      case 0:
        squareVisited = 0;
        //checking if square was visited before
        for (i = 0; i <= end; i++)
        {
          if (x + 2 == visitedX[i] && y + 1 == visitedY[i])
          {
            squareVisited = 1;
          }
        }
        //checking if move is inside chessboard when yes give x and y new coordinates, counter++ and save new sqare ins arrar of visited squares
        if (x + 2 >= 0 && x + 2 <= siz && y + 1 >= 0 && y + 1 <= siz && squareVisited == 0)
        {
          x = x + 2;
          y = y + 1;
          count++;
          visitedX[count] = x;
          visitedY[count] = y;
          break;
        }
        //if move is not possible
        else
        {
          terminateTry0 = 1;
        }
        break;
      case 1:
        squareVisited = 0;
        for (i = 0; i <= end; i++)
        {
          if (x + 1 == visitedX[i] && y + 2 == visitedY[i])
          {
            squareVisited = 1;
          }
        }
        if (x + 1 >= 0 && x + 1 <= siz && y + 2 >= 0 && y + 2 <= siz && squareVisited == 0)
        {
          x = x + 1;
          y = y + 2;
          count++;
          visitedX[count] = x;
          visitedY[count] = y;
          break;
        }
        else
        {
          terminateTry1 = 1;
        }
        break;
      case 2:
        squareVisited = 0;
        for (i = 0; i <= end; i++)
        {
          if (x - 1 == visitedX[i] && y + 2 == visitedY[i])
          {
            squareVisited = 1;
          }
        }
        if (x - 1 >= 0 && x - 1 <= siz && y + 2 >= 0 && y + 2 <= siz && squareVisited == 0)
        {
          x = x - 1;
          y = y + 2;
          count++;
          visitedX[count] = x;
          visitedY[count] = y;
          break;
        }
        else
        {
          terminateTry2 = 1;
        }
        break;
      case 3:
        squareVisited = 0;
        for (i = 0; i <= end; i++)
        {
          if (x - 2 == visitedX[i] && y + 1 == visitedY[i])
          {
            squareVisited = 1;
          }
        }
        if (x - 2 >= 0 && x - 2 <= siz && y + 1 >= 0 && y + 1 <= siz && squareVisited == 0)
        {
          x = x - 2;
          y = y + 1;
          count++;
          visitedX[count] = x;
          visitedY[count] = y;
          break;
        }
        else
        {
          terminateTry3 = 1;
        }
        break;
      case 4:
        squareVisited = 0;
        for (i = 0; i <= end; i++)
        {
          if (x - 2 == visitedX[i] && y - 1 == visitedY[i])
          {
            squareVisited = 1;
          }
        }
        if (x - 2 >= 0 && x - 2 <= siz && y - 1 >= 0 && y - 1 <= siz && squareVisited == 0)
        {
          x = x - 2;
          y = y - 1;
          count++;
          visitedX[count] = x;
          visitedY[count] = y;
          break;
        }
        else
        {
          terminateTry4 = 1;
        }
        break;
      case 5:
        squareVisited = 0;
        for (i = 0; i <= end; i++)
        {
          if (x - 1 == visitedX[i] && y - 2 == visitedY[i])
          {
            squareVisited = 1;
          }
        }
        if (x - 1 >= 0 && x - 1 <= siz && y - 2 >= 0 && y - 2 <= siz && squareVisited == 0)
        {
          x = x - 1;
          y = y - 2;
          count++;
          visitedX[count] = x;
          visitedY[count] = y;
          break;
        }
        else
        {
          terminateTry5 = 1;
        }
        break;
      case 6:
        squareVisited = 0;
        for (i = 0; i <= end; i++)
        {
          if (x + 1 == visitedX[i] && y - 2 == visitedY[i])
          {
            squareVisited = 1;
          }
        }
        if (x + 1 >= 0 && x + 1 <= siz && y - 2 >= 0 && y - 2 <= siz && squareVisited == 0)
        {
          x = x + 1;
          y = y - 2;
          count++;
          visitedX[count] = x;
          visitedY[count] = y;
          break;
        }
        else
        {
          terminateTry6 = 1;
        }
        break;
      case 7:
        squareVisited = 0;
        for (i = 0; i <= end; i++)
        {
          if (x + 2 == visitedX[i] && y - 1 == visitedY[i])
          {
            squareVisited = 1;
          }
        }
        if (x + 2 >= 0 && x + 2 <= siz && y - 1 >= 0 && y - 1 <= siz && squareVisited == 0)
        {
          x = x + 2;
          y = y - 1;
          count++;
          visitedX[count] = x;
          visitedY[count] = y;
          break;
        }
        else
        {
          terminateTry7 = 1;
        }
        break;
      }
    }
    //output for every single move
    // for (i = 0; i <= end; i++)
    // {
    //     printf("sprung %d\n",i+1);
    //     printf("x = %d\n",visitedX[i]+1);
    //     printf("y = %d\n",visitedY[i]+1);
    //     printf("--------\n");
    // }
    //output as chessboard
    for (i = 0; i <= end; i++)
    {
      board[visitedY[i]][visitedX[i]] = i + 1;
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
    // printf("YEAH BOIIIIIIIIIIIIIIIIIIIIIIIIIII!!\n\n");
    //time spent to calculate (inaccurate)
    // clock_t end = clock(); 
    // double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    // printf("Rechenzeit = %f\n", time_spent);
    kill(0, SIGTERM);
    exit(1);
  }
  //generating processes
  fork();
  fork();
  fork();
  fork();
  fork();
  fork();
  //calling function to solve problem
  solve();
}
