#include <iostream>
using namespace std;
class Polynomial {
public:
    Polynomial(int size = 1) {
        this->size = size;
        coefficients = new int[size];
        for (int i = 0; i < size; i++) {
            coefficients[i] = 0;
        }
    }

    Polynomial(const Polynomial& other) {
        size = other.size;
        coefficients = new int[size];
        for (int i = 0; i < size; i++) {
            coefficients[i] = other.coefficients[i];
        }
    }

    ~Polynomial() {
        delete[] coefficients;
    }

    int Degree() const { return size - 1; }

    int GetCoefficient(int exponent) const {
        if (exponent >= size) {
            return 0;
        }
        return coefficients[exponent];
    }

    void SetCoefficient(int exponent, int coefficient) {
        if (exponent >= size) {
            int newSize = exponent + 1;
            int* newCoefficients = new int[newSize];
            for (int i = 0; i < size; i++) {
                newCoefficients[i] = coefficients[i];
            }
            for (int i = size; i < newSize; i++) {
                newCoefficients[i] = 0;
            }
            delete[] coefficients;
            coefficients = newCoefficients;
            size = newSize;
        }
        coefficients[exponent] = coefficient;
    }

    Polynomial& operator+=(const Polynomial& other) {
        int newSize = std::max(size, other.size);
        int* newCoefficients = new int[newSize];
        for (int i = 0; i < newSize; i++) {
            int thisCoefficient = GetCoefficient(i);
            int otherCoefficient = other.GetCoefficient(i);
            newCoefficients[i] = thisCoefficient + otherCoefficient;
        }
        delete[] coefficients;
        coefficients = newCoefficients;
        size = newSize;
        return *this;
    }

    Polynomial& operator-=(const Polynomial& other) {
        int newSize = std::max(size, other.size);
        int* newCoefficients = new int[newSize];
        for (int i = 0; i < newSize; i++) {
            int thisCoefficient = GetCoefficient(i);
            int otherCoefficient = other.GetCoefficient(i);
            newCoefficients[i] = thisCoefficient - otherCoefficient;
        }
        delete[] coefficients;
        coefficients = newCoefficients;
        size = newSize;
        return *this;
    }

    Polynomial operator+(const Polynomial& other) const {
        Polynomial result = *this;
        result += other;
        return result;
    }

    Polynomial operator-(const Polynomial& other) const {
        Polynomial result = *this;
        result -= other;
        return result;
    }

    Polynomial& operator=(const Polynomial& other) {
        if (this == &other) {
            return *this;
        }
        delete[] coefficients;
        size = other.size;
        coefficients = new int[size];
        for (int i = 0; i < size; i++) {
            coefficients[i] = other.coefficients[i];
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Polynomial& polynomial) {
        for (int i = polynomial.size - 1; i >= 0; i--) {
            if (polynomial.GetCoefficient(i) != 0) {
                os << polynomial.GetCoefficient(i);
                if (i > 0) {
                    os << "x^" << i;
                }
                if (i > 0 && polynomial.GetCoefficient(i - 1) != 0) {
                    os << " + ";
                }
            }
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Polynomial& polynomial) {
        int degree;
        is >> degree;
        polynomial.size = degree + 1;
        delete[] polynomial.coefficients;
        polynomial.coefficients = new int[polynomial.size];
        for (int i = 0; i <= degree; i++) {
            int coefficient;
            is >> coefficient;
            polynomial.SetCoefficient(i, coefficient);
        }
        return is;
    }

private:
    int* coefficients;
    int size;
};

int main() {
    Polynomial polynomial1;
    polynomial1.SetCoefficient(0, 2);
    polynomial1.SetCoefficient(1, 3);
    polynomial1.SetCoefficient(2, 1);

    Polynomial polynomial2;
    polynomial2.SetCoefficient(1, 1);
    polynomial2.SetCoefficient(1, 2);
    polynomial2.SetCoefficient(2, 3);

    Polynomial polynomial3 = polynomial1 + polynomial2;
    Polynomial polynomial4 = polynomial1 - polynomial2;

    cout << "Polynomial 1: " << polynomial1 << endl;
    cout << "Polynomial 2: " << polynomial2 << endl;
    cout << "Polynomial 1 + Polynomial 2: " << polynomial3 << endl;
    cout << "Polynomial 1 - Polynomial 2: " << polynomial4 << endl;

    return 0;
}