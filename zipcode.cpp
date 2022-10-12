#include <iostream>
#include <string>
using namespace std;

class ZipCode
{
public:
    // Constructs a ZipCode from an integer zip code value
    ZipCode(int zip);

    // Constructs a ZipCode from a string of 1's and 0's
    ZipCode(const string &code);

    // Returns the zip code in numeric form
    int get_zip_code() const;

    // Returns the zip code in bar form
    string get_bar_code() const;

private:
    int zip;

    // Parse the given bar code, returns an integer.
    // Print an error message and exit if the bar code is invalid.
    int parse_bar_code(const string& code) const;
};

ZipCode::ZipCode(int z) : zip(z) {}

ZipCode::ZipCode(const string& code)
{
    zip = parse_bar_code(code);
}

int ZipCode::parse_bar_code(const string& code) const
{
    int value = 0;

    if (((code.length() - 2) % 5) != 0)
    {
        cout << "ERROR: '" << code << "' has invalid length " << endl
             << "       (Length must be 5*n+2, where n is the number of"
             << endl
             << "       digits in the zip code)" << endl;
        return -1;
    }
    else if ((code[0] != '1') || (code[code.length() - 1] != '1'))
    {
        cout << "ERROR: '" << code << "' must begin and end with '1'" << endl;
        return -1;
    }
    else
    {
        int digits = (code.length() - 2)/5;

        // Store each digit encode value in an array
        int values[] = { 7, 4, 2, 1, 0 };

        for (int d = 0; d < digits; d++)
        {
            int digit = 0;
            for (int i = 0; i < 5; i++)
            {
                char ch = code[d * 5 + i + 1];
                if (ch == '1')
                {
                    digit += values[i];
                }
                else if (ch != '0')
                {
                    cout << "ERROR: '" << code
                         << "' must contain only '1' and '0'" << endl;
                    return -1;
                }
            }

            if ((digit < 1) || (digit == 10) || (digit > 11))
            {
                cout << "ERROR: '" << code << "' has invalid sequence '"
                     << code.substr(d * 5 + 1, 5) << "'" << endl;
                return -1;
            }

            if (digit == 11)
            {
                digit = 0;
            }

            value = (value * 10) + digit;
        }
    }
    return value;
}


// Returns the zip code in numeric form
int ZipCode::get_zip_code() const
{
    return zip;
}

// Returns the zip code in bar form
string ZipCode::get_bar_code() const
{
    string code;
    int z, digit, numDigits, targetDigits;

    // Unique 5-digit bar code sequence represents digit 0-9. Store in an array.
    string digits[] =
            { "11000", "00011", "00101", "00110", "01001",
              "01010", "01100", "10001", "10010", "10100" };

    z = zip;
    numDigits = 0;

    // Work backwards through the zip code integer
    while (z > 0)
    {
        // Pull off the smallest digit
        digit = (z % 10);

        // Then throw that digit away
        z = z/10;

        // Prepend the digit to the code
        code = digits[digit] + code;

        numDigits++;
    }

    // Make sure we always have at least 5 or 9 digits (zip or zip+4)
    if (numDigits > 5)
    {
        targetDigits = 9;
    }
    else
    {
        targetDigits = 5;
    }

    while (numDigits < targetDigits)
    {
        code = digits[0] + code;
        numDigits++;
    }

    // Put a '1' on each end
    return "1" + code + "1";
}


// MAIN FUNCTION
int main()
{
    ZipCode zip1(99504),
            zip2("100101010011100001100110001"),
            zip3(12345),
            zip4(67890);

    cout << zip1.get_zip_code() << "'s bar code is '"
         << zip1.get_bar_code() << "'" << endl;
    cout << zip2.get_zip_code() << "'s bar code is '"
         << zip2.get_bar_code() << "'" << endl;
    cout << zip3.get_zip_code() << "'s bar code is '"
         << zip3.get_bar_code() << "'" << endl;
    cout << zip4.get_zip_code() << "'s bar code is '"
         << zip4.get_bar_code() << "'" << endl;

    cout << endl;

    // Test a range of values by first constructing a zip1 code with
    // an integer, then retrieving the bar code and using that to
    // construct another ZipCode.
    int zip_int = 0;
    for (int i = 0; i < 25; i++)
    {
        // Make an arbitrary 5-digit zip1 code integer, and use it
        // to construct a ZipCode
        int five_digit_zip = (zip_int * zip_int) % 100000;
        ZipCode z1(five_digit_zip);

        // Construct a second ZipCode from the first's bar code
        string z1_code = z1.get_bar_code();
        ZipCode z2(z1_code);

        cout.width(3);
        cout << (i + 1) << ": ";
        cout.width(5);
        cout << z2.get_zip_code() << " has code '"
             << z1_code << "'";

        if ((z1_code == z2.get_bar_code()) &&
            (z1.get_zip_code() == z2.get_zip_code()) &&
            (z2.get_zip_code() == five_digit_zip))
        {
            cout << " [OK]" << endl;
        }
        else
        {
            cout << " [ERR]" << endl;
        }

        // Increment the test value arbitrarily
        zip_int += (233 + zip_int % 7);
    }

    cout << endl;

    // Test some error conditions. This test assumes that
    // ZipCode will simply set its value to a flag that indicates
    // an error, and will not exit the program.
    int BAD_ZIP_COUNT = 5;
    string bad_zips[][2] = {
            { "10010101001110000110011001", "bad length" },
            { "000101010011100001100110001", "bad start/end character" },
            { "100101010011100001100110000", "bad start/end character" },
            { "100101010011100001100110021", "bad digit" },
            { "100101010011100001100111001", "bad sequence" }
    };
    for (int i = 0; i < BAD_ZIP_COUNT; i++)
    {
        cout << "Testing: " << bad_zips[i][1] << endl;
        ZipCode test(bad_zips[i][0]);
        cout << endl;
    }

    return 0;
}
