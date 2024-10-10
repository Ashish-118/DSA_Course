#include <iostream>
#include <string>
#include <cstring>
#include <cwctype>
using namespace std;

void reverse(char name[], int n)
{
    int s = 0;
    int e = n - 1;

    while (s < e)
    {
        swap(name[s++], name[e--]);
    }
}
int get_len(char data[])
{
    int count = 0;

    for (int i = 0; data[i] != '\0'; i++)
    {
        count++;
    }
    reverse(data, count);
    return count;
}
// bool checkPalindrome(string s)
// {

//     int start = 0, end = s.length() - 1;

//     while (start <= end)
//     {
//         if (toupper(s[start++])!= toupper(s[end++]))
//         {
//             return false;
//         }
//         else
//         {

//             if (!iswalnum(s[start]))
//             {
//            start++;
//             }
//             if (!iswalnum(s[end]))
//             {
//            end++;
//             }
//             if (iswalnum(s[start]) && iswalnum(s[end]))
//             {
//                start++;
//                end--;
//             }
//
//         }

//     }
//     return true;
// }

// Above code if there is no special character ignoring and upper and lowercase are differnt
bool checkPalindrome(string s)
{
    bool val = true;
    int start = 0, end = s.length() - 1;

    while (start <= end)
    {

        if (!(isalpha(s[start]) || isdigit(s[start])))
        {

            start++;
        }
        if (!(isalpha(s[end]) || isdigit(s[end])))
        {

            end--;
        }
        if ((isalpha(s[start]) || isdigit(s[start])) && (isalpha(s[end]) || isdigit(s[end])))
        {

            if (s[start] == s[end] || s[start] == toupper(int(s[end])) || toupper(int(s[start])) == s[end])
            {
                start++;
                end--;
            }
            else
            {
                return false;
            }
        }
    }
    return val;
}

char getMaxOccCharacter(string s)
{
    int arr[26] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        int index = 0;
        // for lowercase
        if (ch >= 'a' && ch <= 'z')
        {

            index = ch - 'a';
        }
        // for uppercase
        else
        {
            index = ch - 'A';
        }
        arr[index]++;
    }

    int maxi = -1, ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (maxi < arr[i])
        {
            ans = i;
            maxi = arr[i];
        }
    }
    char finalAns = 'a' + ans;
    return finalAns;
}

string insertInSpace(string &str)
{

    string instr = "@40";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            str.insert(i, instr);
            i = i + 3;
            // cout<<str[i];
        }
    }
    return str;
}

///////// Reverse words in a string II
string reversetemp(string &temp)
{
    string reversed(temp.rbegin(), temp.rend());

    return reversed;
}

string reverseOrderWords(string &str)
{
    string temp = "";
    string fullsentence = "";
    for (int i = str.size() - 1; i >= -1; i--)
    {
        char c = str[i];
        if (c == ' ' || i == -1)
        {
            fullsentence = fullsentence + reversetemp(temp) + ' ';
            temp = "";
        }
        else
        {
            temp = temp + str[i];
        }
    }

    return fullsentence;
}

// Remove all Occurrences of a substring

// class Solution
// {
//     string verifyString(int st, int psize, string tempstr)
//     {
//         // string temp = "";
//         // for (int i = st; i <= en; i++)
//         // {
//         //     temp = temp + tempstr[i];
//         // }

//         //
//         string temp = tempstr.substr(st, psize);
//         return temp;
//     }
//     string remove(int st, int en, string tempstr)
//     {
//         // string finaltemp = "";
//         // for (int i = 0; i < tempstr.size(); i++)
//         // {
//         //     if (st <= i && i <= en)
//         //     {
//         //         continue;
//         //     }

//         //     finaltemp = finaltemp + tempstr[i];
//         // }
//         // tempstr.erase(str.begin()+st,str.begin()+en);

//         // effecient and accepatable
//         tempstr.erase(tempstr.begin() + st, tempstr.begin() + en + 1);
//         return tempstr;
//     }

// public:
//     string removeOccurrences(string s, string part)
//     {
//         string temporary = s;
//         int start = 0, end = part.size();
//         while (end <= temporary.size())
//         {
//             // cout<<"loop start   "<<temporary<<endl;
//             if (part == verifyString(start, part.size(), temporary))
//             {
//                 temporary = remove(start, (end - 1), temporary);
//                 start = 0;
//                 end = part.size();
//             }
//             else
//             {
//                 start++;
//                 end++;
//             }
//             // cout<<"loop end    "<<temporary<<endl;
//         }

//         return temporary;
//     }
// };


//best solution of the above problem
class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        while (s.length() != 0 && s.find(part) < s.length())
        {
            s.erase(s.find(part), part.length());
        }
            return s;
    }
};
int main()
{
    // char name[20];
    // cout<<"Enter :"<<endl
    // cin>>name;

    // cout<<"Lenght: "<<get_len(name)<<endl;

    // cout<<name<<endl;

    // cout<<int(char('@'));
    // cout << checkPalindrome("5?36@6?35") << endl;
    // cout << toupper('?') << endl;

    string word = "Ashish is a good boy";
    // cout<<getMaxOccCharacter(word)<<endl;
    // cout<<reverseOrderWords(word)<<endl;

    string s = "daabcbaabcbc";
    string part = "abc";
    Solution obj;
    cout << obj.removeOccurrences(s, part) << endl;
    return 0;
}