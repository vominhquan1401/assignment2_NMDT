#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

#define step 10

string createNumber(int n, int &result)
{
    string num = "";
    for (size_t i = 0; i < n; i++)
    {
        int temp = rand() % 10;
        num += '0' + temp;
        result = result * 10 + temp;
    }
    return num;
}

char createOrientation()
{
    int ori = rand() % 4;
    if (!ori)
        return 'U';
    if (ori == 1)
        return 'D';
    if (ori == 2)
        return 'L';
    return 'R';
}

string createCommand(int &x, int &y)
{
    string str = "";
    int lenDist, dist;
    char orientation;
    x = 0, y = 0;

    for (size_t i = 0; i < step; i++)
    {
        dist = 0;
        lenDist = rand() % 4 + 1;
        orientation = createOrientation();
        str += orientation + createNumber(lenDist, dist);
        switch (orientation)
        {
        case 'U':
            y += dist;
            break;
        case 'D':
            y -= dist;
            break;
        case 'L':
            x -= dist;
            break;
        case 'R':
            x += dist;
            break;
        }
    }
    return str;
}

string createIndex(int i)
{
    string res = "";
    while (i)
    {
        res = (char)('0' + i % 10) + res;
        i /= 10;
    }
    int len = res.length();
    if (len == 1)
        res = "00" + res;
    else if (len == 2)
        res = "0" + res;
    return res;
}

bool isPrime(int num)
{
    if (num < 2)
        return false;
    if (num == 2 || num == 3)
        return true;
    if (num % 2 == 0 || num % 3 == 0)
        return false;
    for (int i = 5; i <= sqrt(num); i+=6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}

bool isSquared(int n)
{
    int s = sqrt(n);
    if (pow(s, 2) == n)
        return true;
    return false;
}

int main()
{
    int distance, x, y;
    bool primality, squared;
    string pathTestcase, pathSolution, index;

    for (size_t i = 0; i < 888; i++)
    {
        fflush(stdin);
        string str = createCommand(x, y);
        index = createIndex(i + 1);
        pathTestcase = ".\\Testcase\\testcase_" + index + ".txt";
        ofstream testcase(pathTestcase);
        testcase << str;
        testcase.close();

        fflush(stdin);
        pathSolution = ".\\Solution\\solution_" + index + ".txt";
        ofstream solution(pathSolution);
        //
        distance = round(sqrt(x * x + y * y));

        solution << "Khoang cach xe da di chuyen tu vi tri ban dau toi diem hien tai: " << distance << '\n';

        primality = isPrime(distance);
        squared = isSquared(distance);

        if (primality)
        {
            solution << "So " << distance << " la so nguyen to\n";
        }
        if (squared)
        {
            solution << "So " << distance << " la so chinh phuong\n";
        }
        //
        solution.close();
    }

    cout << "Craete done!!";

    return 0;
}