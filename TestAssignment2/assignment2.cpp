#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <fstream>

using namespace std;

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

//==================================== Your code ====================================
int move(string moves)
{   
    int x = 0, y = 0;
    for (size_t i = 0; i < moves.size(); i++)
    {
        int temp = 0;
        switch (moves[i])
        {         
        case 'U':
            for (i++; i < moves.size(); i++)
            {
                if (moves[i] >= '0' && moves[i] <= '9')
                    temp = temp * 10 + moves[i] - 48;
                else
                {             
                    y += temp;                    
                    i--;
                    break;
                }
            }
            if (i == moves.size())
                y += temp;              
            break; 

        case 'L':
            for (i++; i < moves.size(); i++)
            {
                if (moves[i] >= '0' && moves[i] <= '9')
                    temp = temp * 10 + moves[i] - 48;
                else
                {
                    x -= temp;                
                    i--;
                    break;
                }
            }
            if (i == moves.size())
                x -= temp;
            break;
        case 'R':
            for (i++; i < moves.size(); i++)
            {
                if (moves[i] >= '0' && moves[i] <= '9')
                    temp = temp * 10 + moves[i] - 48;
                else
                {
                    x += temp;
                    i--;
                    break;
                }
            }
            if (i == moves.size())
                x += temp;
            break;
        case 'D':
            for (i++; i < moves.size(); i++)
            {
                if (moves[i] >= '0' && moves[i] <= '9')
                    temp = temp * 10 + moves[i] - 48;
                else
                {
                    y -= temp;
                    i--;
                    break;
                }
            }
            if (i == moves.size())
                y -= temp;

            break;
        }
    }
    return round(sqrt(pow(x, 2) + pow(y, 2)));
}

bool isPrime(int n)
{   
    int count = 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            count += 1;
    }
    if (count >= 1)
        return false;
    else
        return true;
}

bool isSquared(int n)
{
 
    int s = sqrt(n);
    if (pow(s, 2) == n)
        return true;
    else
        return false;
}
//===================================================================================

 int main()
 {
     string str, pathTestcase, pathSolution, index, expect, actual;
     int distance, flag = 1;
     bool primality, squared;

     for (size_t i = 0; i < 888; i++)
     {
         index = createIndex(i + 1);
         fflush(stdin);
         pathTestcase = ".\\Testcase\\testcase_" + index + ".txt";
         ifstream testcase(pathTestcase);
         getline(testcase, str);
         testcase.close();

         distance = move(str);

         fflush(stdin);
         pathSolution = ".\\Solution\\solution_" + index + ".txt";
         ifstream solution(pathSolution);

         getline(solution, expect);
         //cout << actual << endl << expect;
         actual = "Khoang cach xe da di chuyen tu vi tri ban dau toi diem hien tai: " + to_string(distance);
         if (actual.compare(expect))
         {
             cout << "Fail at testcase " << index << endl;
             flag = 0;
             continue;
         }

         getline(solution, expect);
         actual = "";
         primality = isPrime(distance);
         if (primality)
         {
             actual = "So " + to_string(distance) + " la so nguyen to";
         }
         if (actual.compare(expect))
         {
             cout << "Fail at testcase " << index << endl;
             flag = 0;
             continue;
         }

         getline(solution, expect);
         actual = "";
         squared = isSquared(distance);
         if (squared)
         {
             actual = "So " + to_string(distance) + " la so chinh phuong";
         }
         if (actual.compare(expect))
         {
             cout << "Fail at testcase " << index << endl;
             flag = 0;
             continue;
         }
         solution.close();
     }

     if (flag)
         cout << "Pass all testcases!!\n";
     return 0;
 }