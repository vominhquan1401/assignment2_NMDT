#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

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

int main()
{
    string str;
    int distance;
    bool primality, squared;

    
    cin >> str;
    distance = move(str);

    
    cout << "Khoang cach xe da di chuyen tu vi tri ban dau toi diem hien tai: "
        << distance << '\n';

    primality = isPrime(distance);
    squared = isSquared(distance);

    if (primality) {
        cout << "So " << distance << " la so nguyen to\n";
    }
    if (squared) {
        cout << "So " << distance << " la so chinh phuong\n";
    }

    return 0;
}