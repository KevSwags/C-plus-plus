#include <iostream>
#include <cstdlib>

using namespace std;

struct Rat
{
    int num;
    int denom;
};

void input(Rat& r);
void output(Rat r);
Rat add(Rat r1, Rat r2);
Rat sub(Rat r1, Rat r2);
Rat mult(Rat r1, Rat r2);
Rat div(Rat r1, Rat r2);
Rat reduce(Rat r);
int lcm(int a, int b);
int gcd(int a, int b);

int main()
{
    Rat r1;
    Rat r2;
    Rat sum;
    Rat diff;
    Rat prod;
    Rat quot;

    char ans;

    do
    {
        input(r1);
        input(r2);
        sum = add(r1, r2);
        diff = sub(r1, r2);
        prod = mult(r1, r2);
        quot = div(r1, r2);

        cout << "r1 = ";
        output(r1);
        cout << "r2 = ";
        output(r2);
        cout << "r1 + r2 = ";
        output(sum);
        cout << "r1 - r2 = ";
        output(diff);
        cout << "r1 * r2 = ";
        output(prod);
        cout << "r1 / r2 = ";
        output(quot);

        cout << "Do you want to continue (y/n): ";
        cin >> ans;
    } while (ans == 'y');

    return 0;
}

void input(Rat& r)
{
    cout << "Input num: ";
    cin >> r.num;
    cout << "Input denom: ";
    cin >> r.denom;

    if (r.denom == 0)
    {
        cout << "Denominator cannot be zero" << endl;
        exit(1);
    }
    else if (r.denom < 0)
    {
        r.num = -r.num;
        r.denom = -r.denom;
    }
}

void output(Rat r)
{
    cout << r.num << "/" << r.denom << endl;
}

int gcd(int a, int b)
{
    a = static_cast<int>(abs(a));
    b = static_cast<int>(abs(b));
    int c;
    while (b != 0)
    {
        c = a;
        a = b;
        b = c % b;
    }
    return a;
}

int lcm(int a, int b)
{
    a = static_cast<int>(abs(a));
    b = static_cast<int>(abs(b));

    return (a * b) / gcd(a,b);
}


Rat add(Rat r1, Rat r2)
{
    Rat r;
    int m = lcm(r1.denom, r2.denom);
    r.num = r1.num * m / r1.denom + r2.num * m / r2.denom;
    r.denom = m;
    return reduce(r);
}

Rat sub(Rat r1, Rat r2)
{
    Rat r;
    int m = lcm(r1.denom, r2.denom);
    r.num = r1.num * m / r1.denom - r2.num * m / r2.denom;
    r.denom = m;
    return reduce(r);
}

Rat mult(Rat r1, Rat r2)
{
    Rat r;
    r.num = r1.num * r2.num;
    r.denom = r1.denom * r2.denom;
    return reduce(r);
}


Rat div(Rat r1, Rat r2)
{
    if (r2.num == 0)
    {
        cout << "Cannot divide by zero" << endl;
        exit(1);
    }
    Rat r;
    r.num = r1.num * r2.denom;
    r.denom = r1.denom * r2.num;
    return reduce(r);
}

Rat reduce(Rat r)
{
    int d = gcd(r.num, r.denom);
    Rat rr;
    rr.num = r.num / d;
    rr.denom = r.denom / d;
    return rr;
}