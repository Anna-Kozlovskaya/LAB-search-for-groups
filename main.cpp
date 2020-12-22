#include <iostream>
#include <string>
#include <locale>
using namespace std;

int main() {
    locale::global( locale( "" ) );

    wstring input;
    wstring cache;
    int counter = 0;
    int current_state = 1;

    wcout << L"Введите строку, не используя пробелов:" << endl;
    wcin >> input;

    for (int i = 0; i <= input.size(); i++)
    {
        switch (current_state) 
        {
            case 1:
            {
                cache.clear();
                counter = 0;
                if ((int)input[i]  >= 48 && (int)input[i] <= 57)
                {
                    current_state = 2;
                    counter++;
                    cache += input[i];
                }
                else
                {
                    current_state = 1;
                }
                break;
            }
            case 2:
            {
                if ((int)input[i]  >= 48 && (int)input[i] <= 57)
                {
                    counter++;
                    current_state = 2;
                    if (counter > 2)
                    {
                        current_state = 1;
                    }
                    else
                    {
                        cache += input[i];
                    }
                }
                else if ((int)input[i] == 45)
                {
                    current_state = 3;
                    cache += input[i];
                }
                else
                {
                    current_state = 1;
                }
                break;
            }
            case 3:
            {
                if ((int)input[i]  >= 1040 && (int)input[i] <= 1071)
                {
                    current_state = 4;
                    cache += input[i];
                }
                else
                {
                    current_state = 1;
                }
                break;
            }
            case 4:
            {
                if ((int)input[i]  >= 1040 && (int)input[i] <= 1071)
                {
                    current_state = 4;
                    cache += input[i];
                }
                else if ((int)input[i] == 45) {
                    current_state = 5;
                    cache += input[i];
                }
                else
                {
                    current_state = 1;
                }
                break;
            }
            case 5:
            {
                if ((int)input[i]  >= 48 && (int)input[i] <= 57)
                {
                    current_state = 6;
                    cache += input[i];
                }
                else
                {
                    current_state = 1;
                }
                break;
            }
            default:
            {
                wcout << cache << endl;
                current_state = 1;
                break;
            }
        }
    }
    wcout << L"Работа завершена." << endl;
    return 0;
}
