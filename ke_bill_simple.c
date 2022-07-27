#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>
// #include <strings.h>

COORD c = {0, 0};

void setxy(int x, int y)
{
    c.X = x;
    c.Y = y; // Set X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int main()
{
    system("cls");
    int j;
    int previous_reading = 0;
    int current_reading = 0;
    int unit, bill;
    bool answer = true;
    char reply[4];
    int reply_value;

    while (answer)
    {
        system("cls");

        // Top Header
        setxy(16, 0);
        for (j = 0; j < 20; j++)
            printf("%c", 174);
        printf(" KE Bill ");
        for (j = 0; j < 20; j++)
            printf("%c", 175);

        // Top border line of Box
        setxy(4, 5);
        printf("%c", 201);

        setxy(4, 9);
        printf("%c", 204);

        setxy(4, 13);
        printf("%c", 200);
        for (j = 0; j < 72; j++)
        {
            if (j == 36)
            {
                setxy(5 + j, 5);
                printf("%c", 203);

                setxy(5 + j, 9);
                printf("%c", 206);

                setxy(5 + j, 13);
                printf("%c", 202);
                continue;
            }
            setxy(5 + j, 5);
            printf("%c", 205);

            setxy(5 + j, 9);
            printf("%c", 205);

            setxy(5 + j, 13);
            printf("%c", 205);
        }
        setxy(77, 5);
        printf("%c", 187);

        setxy(77, 9);
        printf("%c", 185);

        setxy(77, 13);
        printf("%c", 188);

        // Left and Right border of Box
        for (j = 0; j < 3; j++)
        {
            // Upper Part of Box
            setxy(4, 6 + j);
            printf("%c", 186);

            setxy(41, 6 + j);
            printf("%c", 186);

            setxy(77, 6 + j);
            printf("%c", 186);

            // Bottom Part of Box
            setxy(4, 10 + j);
            printf("%c", 186);

            setxy(41, 10 + j);
            printf("%c", 186);

            setxy(77, 10 + j);
            printf("%c", 186);
        }

        setxy(6, 7);
        printf("Enter Previous Meter Reading : ");
        setxy(43, 7);
        printf("Enter Current Meter Reading : ");

        setxy(37, 7);
        scanf("%d", &previous_reading);
        setxy(73, 7);
        scanf("%d", &current_reading);

        if (current_reading == 0 || previous_reading == 0)
        {
            setxy(0, 15);
            printf("Reading cannot be Zero\n");
            printf("Press any Key to Enter values again");
            getch();
            continue;
        }

        unit = current_reading - previous_reading;

        if (unit <= 100)
            bill = unit * 7;
        else if (unit <= 200)
            bill = (100 * 7) + (unit - 100) * 10;
        else if (unit <= 300)
            bill = (100 * 7) + (100 * 10) + (unit - 200) * 13;
        else
            bill = (100 * 7) + (100 * 10) + (100 * 13) + (unit - 300) * 17;

        setxy(6, 11);
        printf("Unit Consumed: %d", unit);
        setxy(43, 11);
        printf("Your Bill is: %d", bill);

        setxy(0, 15);
        printf("Do you want to Generate another Bill 'yes' or 'no'? ");
        scanf("%s", reply);
        reply_value = strcmp(reply, "no");
        if (reply_value == 0)
            answer = FALSE;
        else
            continue;
    }
    printf("\n");
    getch();
}