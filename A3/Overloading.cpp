/******************************************************************************

                                A3 - Overloading
 Create a complex number class with real and imaginary values being the data members. (X)
 Create custom constructor to input the numbers inline. (X)
 Write two methods to get the modulus, argument and the inverse of a complex number. (X)
 Overload the +, -, * and / operators to do complex algebra. (X)
 Use function templates to handle different data types. (X)
 Also overload the insertion operator to display a complex number. (X)

*******************************************************************************/

#include <iostream>
#include <cmath>
#include <ostream>

using namespace std;

template <class T>
class Complex
{
public:

    //real and imaginary data members
    T real, imaginary;

    //Custom Constructor
    Complex(T real, T imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }

    //modulus method
    float modulus(Complex num)
    {
        float modulus = 0;
        modulus += sqrt((num.real * num.real) + (num.imaginary * num.imaginary));
        return modulus;
    }

    //argument method
    float argument(Complex num)
    {
        float argument = 0;
        if (num.imaginary == 0) {
            return 0;
        }
        if (num.real == 0) {
            return 0;
        }
        argument += atan(num.imaginary / num.real);
        return argument;
    }

    //inverse method
    void inverse(Complex num)
    {
        double real = 0, imag = 0;

        if (num.imaginary > 0) {
            real = num.real / ((num.real * num.real) + (num.imaginary * num.imaginary));
            imag = (-num.imaginary) / ((num.real * num.real) - (-(num.imaginary * num.imaginary)));
        }
        else if (num.imaginary < 0) {
            real = num.real / ((num.real * num.real) + (num.imaginary * num.imaginary));
            imag = (-num.imaginary) / ((num.real * num.real) - (-(num.imaginary * num.imaginary)));
        }

        cout << real << " + " << imag << "i " << endl;
    }

    //overloaded addition
    Complex operator + (Complex num)
    {
        Complex temp(0, 0);
        temp.real = real + num.real;
        temp.imaginary = imaginary + num.imaginary;
        return temp;
    }

    //overloaded subtraction
    Complex operator - (Complex num)
    {
        Complex temp(0, 0);
        temp.real = real - num.real;
        temp.imaginary = imaginary - num.imaginary;
        return temp;
    }

    //overloaded multiplication
    Complex operator * (Complex num)
    {
        Complex temp(0, 0);
        temp.real = (real * num.real) - (imaginary * num.imaginary);
        temp.imaginary = (real * num.imaginary) + (imaginary * num.real);
        return temp;
    }

    //overloaded division
    Complex operator / (Complex num)
    {
        Complex temp(0, 0);
        double divisor = (num.real * num.real) + (num.imaginary * num.imaginary);
        temp.real = (real * num.real) + (imaginary * num.imaginary);
        temp.real /= divisor;
        temp.imaginary = (imaginary * num.real) - (real * num.imaginary);
        temp.imaginary /= divisor;
        return temp;
    }
};


//overloaded insertion operator
template <typename T>
ostream& operator <<(ostream& output, Complex<T> num)
{
    output << num.real << " + " << num.imaginary << "i " << endl;
    return output;
}



int main()
{

    double num1_real, num1_imag, num2_real, num2_imag;
    double num3_real, num3_imag, num4_real, num4_imag;


    // double type
    cout << "- Complex with double data type -" << endl;
    cout << "Input the real portion of the first number: ";
    cin >> num1_real;
    cout << "Input the imaginary portion of the first number: ";
    cin >> num1_imag;

    cout << "Input the real portion of the second number: ";
    cin >> num2_real;
    cout << "Input the imaginary portion of the second number: ";
    cin >> num2_imag;

    cout << endl;

    Complex<double> num1(num1_real, num1_imag);
    Complex<double> num2(num2_real, num2_imag);

    cout << num1 << endl;
    cout << num2 << endl;

    cout << "Modulus of the first complex number: " << num1.modulus(num1) << endl;
    cout << "Modulus of the second complex number: " << num2.modulus(num2) << endl;

    cout << "Argument of the first complex number: " << num1.argument(num1) << endl;
    cout << "Argument of the second complex number: " << num2.argument(num2) << endl;

    cout << "Inverse of the first complex number: ";
    num1.inverse(num1);

    cout << "Inverse of the second complex number: ";
    num2.inverse(num2);

    cout << "First complex number + Second complex number: ";
    cout << num1 + num2;

    cout << "First complex number - Second complex number: ";
    cout << num1 - num2;

    cout << "First complex number * Second complex number: ";
    cout << num1 * num2;

    cout << "First complex number / Second complex number: ";
    cout << num1 / num2;


    // float type
    cout << "- Complex with double data type -" << endl;
    cout << "Input the real portion of the first number: ";
    cin >> num3_real;
    cout << "Input the imaginary portion of the first number: ";
    cin >> num3_imag;

    cout << "Input the real portion of the second number: ";
    cin >> num4_real;
    cout << "Input the imaginary portion of the second number: ";
    cin >> num4_imag;

    cout << endl;

    Complex<float> num3(num3_real, num3_imag);
    Complex<float> num4(num2_real, num2_imag);

    cout << num3 << endl;
    cout << num4 << endl;

    cout << "Modulus of the first complex number: " << num3.modulus(num3) << endl;
    cout << "Modulus of the second complex number: " << num4.modulus(num4) << endl;

    cout << "Argument of the first complex number: " << num3.argument(num3) << endl;
    cout << "Argument of the second complex number: " << num4.argument(num4) << endl;

    cout << "Inverse of the first complex number: ";
    num3.inverse(num3);

    cout << "Inverse of the second complex number: ";
    num4.inverse(num4);

    cout << "First complex number + Second complex number: ";
    cout << num3 + num4;

    cout << "First complex number - Second complex number: ";
    cout << num3 - num4;

    cout << "First complex number * Second complex number: ";
    cout << num3 * num4;

    cout << "First complex number / Second complex number: ";
    cout << num3 / num4;

};
