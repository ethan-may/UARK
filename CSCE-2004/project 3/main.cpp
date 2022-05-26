#include <iostream>
#include <string.h>
#include <cctype>
using namespace std;
int main()
{
    // Declaring Variables
    char userChar;
    int userShift;
    char userMsg[100];
    int N;
    int totChar;
    char change;
    char charCipher;
    
    // First outputs before loop
    cout << "Welcome to the Caesar Cipher, would you like the Caesar or the May Cipher?: (C or M) ";
    cin >> charCipher;
    cout << "Would you like to enconde or decode?: (E or D) ";
    cin >> userChar;
    
    // If statement for Caesar Cipher
    if (charCipher == 'C')
    {
    // Making sure they select "E" or "D"
    while ((userChar != 'E') && (userChar != 'D'))
    {
        cout << "Would you like to enconde or decode?: (E or D) ";
        cin >> userChar;
    }
    
    // Selecting encode or decode
    if ((userChar == 'E') || (userChar == 'D'))
    {
        cout << "Enter a shift between 1 and 25: ";
        cin >> userShift;
        // making sure it says in the bounds
        while ((userShift < 1) || (userShift > 25))
        {
            cout << "Enter a shift between 1 and 25: ";
            cin >> userShift;
        }
    }
    
    cin.getline(userMsg, 100);
    totChar = strlen(userMsg);
    
    // Starting actual encryption/decryption
    if (userChar == 'E') // Encryption
    {
        cout << "Enter a message to encode through the Caesar Cipher:" << endl;
        cin >> userMsg;
        if(userShift >= 0 && userShift <= 25)
        {
        for (int N = 0; userMsg[N] != '\0'; ++N)
        {
            change = userMsg[N];
            // Encrypt for lowercase
            if ((change >= 'a') && (change <= 'z'))
            {
                change = change + userShift;
                if (change > 'z')
                {
                    change = change + 'a' - 'z' - 1;
                }
                userMsg[N] = change;
            }
            // Encrypt for uppercase
            else if ((change >= 'A') && (change <= 'Z'))
            {
                change = change + userShift;
                if (change > 'Z')
                {
                    change = change - 'Z' + 'A' - 1;
                }
                userMsg[N] = change;
            }
        }
        cout << userMsg;
        }
    }
    else if (userChar == 'D') // Decryption
    {
        cout << "Enter a message to decode through the Caesar Cipher:" << endl;
        cin >> userMsg;
        
        if(userShift <= 25 && userShift >= 0)
        {
        for (int N = 0; userMsg[N] != '\0'; ++N)
        {
            change = userMsg[N];
            // Decrypt for lowercase
            if ((change >= 'a') && (change <= 'z'))
            {
                change = change - userShift;
                if (change < 'a')
                {
                    change = change + 'z' - 'a' + 1;
                }
                userMsg[N] = change;
            }
            // Decrypt for uppercase
            else if ((change >= 'A') && (change <= 'Z'))
            {
                change = change - userShift;
                if (change < 'A')
                {
                    change = change + 'Z' - 'A' + 1;
                }
                userMsg[N] = change;
            }
        }
        cout << userMsg;
        }
    }
    }
    else if (charCipher == 'M') // My own cipher // 
    {
    // Making sure they select "E" or "D"
    while ((userChar != 'E') && (userChar != 'D'))
    {
        cout << "Would you like to enconde or decode?: (E or D) ";
        cin >> userChar;
    }
    
    // Selecting encode or decode
    if ((userChar == 'E') || (userChar == 'D'))
    {
        cout << "Enter a shift between 1 and 25: ";
        cin >> userShift;
        // making sure it says in the bounds
        while ((userShift < 1) || (userShift > 25))
        {
            cout << "Enter a shift between 1 and 25: ";
            cin >> userShift;
        }
    }
    
    // Changing the user shift to make it my Cipher
    userShift = (userShift + 3) / 2;
    
    cin.getline(userMsg, 100);
    totChar = strlen(userMsg);
    
    // Starting actual encryption/decryption
    if (userChar == 'E') // Encryption
    {
        cout << "Enter a message to encode through the May Cipher:" << endl;
        cin >> userMsg;
        if(userShift <= 25 && userShift >= 0)
        {
        for (int N = 0; userMsg[N] != '\0'; ++N)
        {
            change = userMsg[N];
            // Encrypt for lowercase
            if ((change >= 'a') && (change <= 'z'))
            {
                change = change + userShift;
                if (change > 'z')
                {
                    change = change + 'a' - 'z' - 1;
                }
                userMsg[N] = change;
            }
            // Encrypt for uppercase
            else if ((change >= 'A') && (change <= 'Z'))
            {
                change = change + userShift;
                if (change > 'Z')
                {
                    change = change - 'Z' + 'A' - 1;
                }
                userMsg[N] = change;
            }
        }
        cout << userMsg;
        }
    }
    else if (userChar == 'D') // Decryption
    {
        cout << "Enter a message to decode through the May Cipher:" << endl;
        cin >> userMsg;
        
        if(userShift <= 25 && userShift >= 0)
        {
        for (int N = 0; userMsg[N] != '\0'; ++N)
        {
            change = userMsg[N];
            // Decrypt for lowercase
            if ((change >= 'a') && (change <= 'z'))
            {
                change = change - userShift;
                if (change < 'a')
                {
                    change = change + 'z' - 'a' + 1;
                }
                userMsg[N] = change;
            }
            // Decrypt for uppercase
            else if ((change >= 'A') && (change <= 'Z'))
            {
                change = change - userShift;
                if (change < 'A')
                {
                    change = change + 'Z' - 'A' + 1;
                }
                userMsg[N] = change;
            }
        }
        cout << userMsg;
        }
    }
    }
    
    return 0;
}
