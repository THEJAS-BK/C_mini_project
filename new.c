#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
char tasks[25][25];
void printTable(int n)
{
    int i;
    printf("\nINDEX\t\tTASKS \n");
    for (i = 0; i < n; i++)
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
        printf("\nenter the index of the task to delete :");
        scanf("%d", &idx);
        if (idx >= 0 && idx < n)
        {
            break;
        }
        else
        {
            printf("Invalid index!!!\n");
        }
    }
    for (int i = idx - 1; i < n - 1; i++)
    {
        strcpy(tasks[i], tasks[i + 1]);
    }
    tasks[n - 1][0] = '\0';
    return n - 1;
}
void writeTasksToFile(int n)
{
    FILE *fptr = fopen("tasks_output.txt", "w");
    if (fptr == NULL)
    {
        printf("Error opening file for writing!\n");
        return;
    }
    fprintf(fptr, "Saved Tasks:\n");
    for (int i = 0; i < n; i++)
    {
        if (tasks[i][0] != '\0')
        {
            fprintf(fptr, "%d. %s\n", i + 1, tasks[i]);
        }
    }
    fclose(fptr);
    printf("Tasks written to tasks_output.txt\n");
}

void main()
{
    char user_inp;
    int i, n = 3, val;
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
        while (1)
        {
            printf("enter (S to edit) to delete elements (Q to quit) :");
            scanf("%c", &del);
            if (toupper(del) == 'S')
            {
                Edit_mode(val);
                printTable(val);
                break;
            }
            else if (toupper(del) == 'Q')
            {
                printTable(val);
                break;
            }
            else
            {
                printf("invalid input!!!\n");
                getchar();
            }
        }
        writeTasksToFile(val);
        printf("the tasks are saved successfully \n\n");
        exit(0);
    }
}