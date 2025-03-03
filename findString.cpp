#include <iostream>
#include <string>
using namespace std;

int bruteForceSearch(string text, string pattern)
{
    int textLength = text.length();
    int patternLength = pattern.length();

    for (int i = 0; i <= textLength - patternLength; i++)
    {
        int j;
        for (j = 0; j < patternLength; j++)
        {
            if (text[i + j] != pattern[j])
            {
                break;
            }
        }
        if (j == patternLength)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    string text = "IT IS VERY DIFFICULT TO FIND A HAPPY PERSON IN THIS WORLD";
    string pattern = "HAPPY";

    int position = bruteForceSearch(text, pattern);

    if (position != -1)
    {
        cout << "Pattern '" << pattern << "' found at index: " << position << endl;
    }
    else
    {
        cout << "Pattern '" << pattern << "' not found in the given text." << endl;
    }

    return 0;
}
