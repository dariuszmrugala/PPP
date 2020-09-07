// ex7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    char input_char{};
    char* table_of_chars = new char[2];
    int size_of_chars_table{2};

    std::cin >> input_char;
    //std::putchar(input_char);
    table_of_chars[0] = input_char;
    table_of_chars[1] = '\0';
    if (input_char == '!')
    {
        delete[] table_of_chars;
        return 0;
    }

    while (true) {


        std::cin >> input_char;
        //std::putchar(input_char);
        if (input_char == '!')
        {
            std::cout << table_of_chars << '\n';
            return 0;
        }

        char* temporary_table_of_chars = new char[size_of_chars_table + 1];
        for (int counter = 0; counter < size_of_chars_table - 1 ; ++counter)
        {
            temporary_table_of_chars[counter] = table_of_chars[counter];
        }
        delete[] table_of_chars;
        temporary_table_of_chars[size_of_chars_table - 1 ] = input_char;
        temporary_table_of_chars[size_of_chars_table] = '\0';
        ++size_of_chars_table;
        table_of_chars = temporary_table_of_chars;
    }

    std::cout << '\n' << table_of_chars << '\n';
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
