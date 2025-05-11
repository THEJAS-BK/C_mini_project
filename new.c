#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
char tasks[25][25];
void printTable(int n)
{
    int i, length = 0;
    length += n;
    printf("\nindex\t\tTasks \n");
    for (i = 0; i < length; i++)
    {
        if (tasks[i][0] != '\0')
            printf("%d\t\t%s \n", i + 1, tasks[i]);
    }
    printf("\n");
}
int ask_user()
{
    int userinp, i;
    while (1)
    {
        printf("enter the number of tasks to add (max 20) :");
        scanf("%d", &userinp);
        getchar();
        if (userinp <= 20 && userinp > 0)
        {
            printf("\n");
            for (i = 3; i < (userinp + 3); i++)
            {
                printf("enter task %d :", i + 1);
                fgets(tasks[i], sizeof(tasks[i]), stdin);
                if (tasks[i][strlen(tasks[i]) - 1] == '\n')
                {
                    tasks[i][strlen(tasks[i]) - 1] = '\0';
                }
            }
            printTable(userinp + 3);
            break;
        }
    }
    return userinp + 3;
}
int Edit_mode(int n)
{
    int idx;

    while (1)
    {
        printf("enter the index of the task to delete :");
        scanf("%d", &idx);
        if (idx > 0 && idx < n)
        {
            break;
        }
        else if (idx == 0)
        {
            break;
        }
        {
            printf("Invalid index!!!\n");
        }
    }

    strcpy(tasks[idx - 1], "");
    for (int i = idx - 1; i < n - 1; i++)
    {
        strcpy(tasks[i], tasks[i + 1]);
    }
    tasks[n - 1][0] = '\0';
    return n - 1;
}

void main()
{
    char user_inp;
    int i, n = 3, val, val2;
    printf("\n    Github : THEJAS-BK\n\n");
    printf("\n       TODO LIST \n\n");
    printf("Let's plan your day (c to create)");
    scanf("%c", &user_inp);
    getchar();
    if ((toupper(user_inp)) == 'C')
    {
        printf("      min 3 inputs\n\n");
        for (i = 0; i < n; i++)
        {
            printf("enter tasks %d :", i + 1);
            fgets(tasks[i], sizeof(tasks[i]), stdin);
            if (tasks[i][strlen(tasks[i]) - 1] == '\n')
            {
                tasks[i][strlen(tasks[i]) - 1] = '\0';
            }
        }
        printf("\n");
        printTable(n);
        printf("\n");
        val = ask_user();
        char del;
        printf("enter (S) to delete elements (Q to quit) :");
        scanf("%c", &del);
        if (toupper(del) == 'S')
        {
            val2 = Edit_mode(val);
            printTable(val);
        }
        else
        {
            printTable(val);
            exit(0);
        }
    }
}