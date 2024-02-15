﻿#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <string>

using namespace std;


//Task String
class MyString
{
    char* str;
    static int count;
    int field = 69;
public:
    MyString()
    {
        str = new char[field];
        str[0] = '\0';
        count++;
    }
    MyString(const char* text)
    {
        str = new char[strlen(text) + 1];
        strcpy_s(str, strlen(text) + 1, text);
        count++;
    }

    MyString(const MyString& other)
    {
        str = new char[strlen(other.str) + 1];
        strcpy_s(str, strlen(other.str) + 1, other.str);
        count++;
    }

    MyString(const std::initializer_list<char>& ilist)
    {
        int size = ilist.size();
        str = new char[size + 1];
        int i = 0;
        for (char c : ilist)
        {
            str[i++] = c;
        }
        str[i] = '\0';
        count++;
    }

    MyString& operator=(const MyString& other)
    {
        if (this != &other)
        {
            delete[] str;
            str = new char[strlen(other.str) + 1];
            strcpy_s(str, strlen(other.str) + 1, other.str);
        }
        return *this;
    }

    MyString operator++()
    {
        int overload = strlen(str);
        char* temp = new char[overload + 2];
        strcpy_s(temp, overload + 2, str);
        temp[overload] = 'x';
        temp[overload + 1] = '\0';
        delete[] str;
        str = temp;
        return *this;
    }

    MyString operator--()
    {
        int overload = strlen(str);
        if (overload > 0)
        {
            char* temp = new char[overload];
            strncpy_s(temp, overload, str, overload - 1);
            temp[overload - 1] = '\0';
            delete[] str;
            str = temp;
        }
        return *this;
    }

    MyString operator++(int)
    {
        MyString postfixInc(*this);
        int overload = strlen(str);
        char* temp = new char[overload + 2];
        strcpy_s(temp, overload + 2, str);
        temp[overload] = 'x';
        temp[overload + 1] = '\0';
        delete[] str;
        str = temp;
        return postfixInc;
    }

    MyString operator--(int)
    {
        MyString postfixDic(*this);
        int overload = strlen(str);
        if (overload > 0)
        {
            char* temp = new char[overload];
            strncpy_s(temp, overload, str, overload - 1);
            temp[overload - 1] = '\0';
            delete[] str;
            str = temp;
        }
        return postfixDic;
    }

    MyString operator+(int n) const
    {
        MyString result(*this);
        int overload = strlen(result.str);
        char* temp = new char[overload + n + 1];
        strcpy_s(temp, overload + n + 1, result.str);
        for (int i = overload; i < overload + n; ++i)
        {
            temp[i] = 'x';
        }
        temp[overload + n] = '\0';
        delete[] result.str;
        result.str = temp;
        return result;
    }

    friend MyString operator+(int n, const MyString& Str)
    {
        return Str + n;
    }

    MyString operator-(int n) const
    {
        MyString result(*this);
        int overload = strlen(result.str);
        if (n < overload)
        {
            char* temp = new char[overload - n + 1];
            strncpy_s(temp, overload - n + 1, result.str, overload - n);
            temp[overload - n] = '\0';
            delete[] result.str;
            result.str = temp;
        }
        else
        {
            delete[] result.str;
            result.str = new char[1];
            result.str[0] = '\0';
        }
        return result;
    }

    void input()
    {
        char buffer[256];
        cout << "Enter your string: ";
        cin.getline(buffer, 256);
        delete[] str;
        str = new char[strlen(buffer) + 1];
        strcpy_s(str, strlen(buffer) + 1, buffer);
    }

    void output() const
    {
        cout << "String: " << str << endl;
    }

    static int getCount()
    {
        return count;
    }
    ~MyString()
    {
        delete[] str;
        count--;
    }
};


int MyString::count = 0;

int main()
{
    //Task String

    MyString newString{ 'H', 'e', 'l', 'l', 'o' };
    newString.output();

    cout << "String count: " << newString.getCount() << endl;

    return 0;
}
