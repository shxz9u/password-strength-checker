#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable : 4267)
#pragma warning (disable : 6031)
#pragma warning (disable : 6054)

#include <stdio.h>
#include <string.h>
#include <Windows.h>

void menu()
{
    printf("======================\n");
    printf("   PASSWORD CHECKER\n");
    printf("======================\n");
    printf("\n\n\n");
    printf("Enter your password: ");
}

int main()
{
    char password[100];
    int length, special = 0, upper = 0, lower = 0, number = 0;
    int score = 0;

    menu();
    scanf("%s", password);

    length = strlen(password);

    for (int i = 0; i < length; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            upper = 1;
        }
        else if (password[i] >= 'a' && password[i] <= 'z')
        {
            lower = 1;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            number = 1;
        }
        else
        {
            special++;
        }
    }

    score += length;
    score += special;

    if (upper)
    {
        score += 2;
    }
    if (lower)
    {
        score += 2;
    }
    if (number)
    {
        score += 2;
    }

    if (score < 10)
    {
        MessageBox(NULL, TEXT("Week Password"), TEXT("Result"), MB_ICONWARNING | MB_OK);
    }
    else if (score < 20)
    {
        MessageBox(NULL, TEXT("Moderate Password"), TEXT("Result"), MB_ICONINFORMATION | MB_OK);
    }
    else 
    {
        MessageBox(NULL, TEXT("Strong Password"), TEXT("Result"), MB_ICONINFORMATION | MB_OK);
    }
    
    return 0;
}