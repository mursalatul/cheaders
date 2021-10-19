#ifndef NUMBER_H
#define NUMBER_H


// macros
typedef signed long long int ll;

// return number of digits of a integer number
int size_int(ll n)
{
    int size = 0;
    while (1)
    {
        if (n > 0)
        {
            size++;
            n /= 10;
        }
        else
        {
            break;
        }
    }
    return size;
}


#endif