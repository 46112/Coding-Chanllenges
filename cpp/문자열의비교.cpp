#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

/*

<문자열의비교>
사전순으로 비교해서 첫번째 문자열이 앞서면 -1
두번째 문자열이 앞서면 1
일치하다면 0

*/

const int MAX_LENGTH = 100000;

class MyString{
    private:
        char *characters;
        int length;
    public:
        MyString(const char * str)
        {
            this->length = strnlen(str, MAX_LENGTH);
            this->characters = new char[this->length];
            for (int i = 0; i < this->length; i++)
            {
                this->characters[i] = str[i];
            }
        }

        MyString(const string & original)
        {
            this->length = original.length();
            this->characters = new char[this->length];
            for (int i = 0; i < this->length; i++)
            {
                this->characters[i] = original[i];
            }
        }

        ~MyString()
        {
            delete[] characters;
        }

        bool operator < (const MyString& o) const{
            int n = min(this->length, o.length);
            for (int i = 0; i < n; i++)
            {
                if(this->characters[i] > o.characters[i])
                    return false;
                else if (this->characters[i] < o.characters[i])
                    return true;
                else
                    continue;
            }

            // 기본적으로 n번까지는 동일한 문자열
            if (this->length < o.length) // 앞의 문자열이 더 짧을 경우
                return true;
            else
                return false; // 앞이 더 길거나 같을 경우
        }

        bool operator > (const MyString& o) const{
            int n = min(this->length, o.length);
            for (int i = 0; i < n; i++)
            {
                if(this->characters[i] > o.characters[i])
                    return true;
                else if (this->characters[i] < o.characters[i])
                    return false;
                else
                    continue;
            }
            
            // 기본적으로 n번까지는 동일한 문자열
            if (this->length > o.length) // 앞의 문자열이 더 길 경우
                return true;
            else
                return false; // 앞이 더 짧거나 같을 경우
        }

        bool operator == (const MyString& o) const{
            if (this->length != o.length)
                return false;

            int n = this->length;
            for (int i = 0; i < n; i++)
            {
                if(this->characters[i] != o.characters[i])
                    return false;
                else
                    continue;
            }
            return true; // 검증 전부 통과했을 때 true
        }
};

int main()  // 입력값 받아 검증
{
    string s1;
    string s2;
    cin >> s1 >> s2;

    MyString mys1(s1);
    MyString mys2(s2);

    if (mys1 < mys2)
    {
        printf("-1");
    }
    else if (mys1 > mys2)
    {
        printf("1");
    }
    else {
        printf("0");
    }

    return 0;
}
