#include "../../include/lab1-task2/polynomial.hpp"
#include <cmath>
#include <iostream>
#include <stdexcept>

Polynomial::Polynomial(int degree) {

    m_degree = degree;
    double num = 0;
    bool is_ok = false;
    
    for (unsigned int i = 0; i <= abs(degree); ++i) {
        while (!is_ok) {
            std::cout << "Enter index: ";
            std::cin >> num;
            if (!std::cin) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid index format, retry." << '\n';
            }
            m_odds_array.push_back(num);
            is_ok = true;
        }
    }
}

Polynomial::Polynomial(const Polynomial &other) {
    m_degree = other.m_degree;
    m_odds_array = other.m_odds_array;
}

Polynomial Polynomial::operator +(const Polynomial &operand) {
    int degree1 = m_degree;
    int degree2 = operand.m_degree;
    Polynomial copy = operand;

    if (m_odds_array.size() > copy.m_odds_array.size()) {
        while (m_odds_array.size() > copy.m_odds_array.size()) {
            copy.m_odds_array.insert(copy.m_odds_array.begin(), 0);
        }
    }
    else if (m_odds_array.size() < copy.m_odds_array.size()) {
        while (m_odds_array.size() < copy.m_odds_array.size()) {
            m_odds_array.insert(m_odds_array.begin(), 0);
        }
    }
    for (unsigned int i = 0; i < m_odds_array.size(); ++i) {
        m_odds_array[i] += copy.m_odds_array[i];
    }

    return *this;
}

Polynomial Polynomial::operator -(const Polynomial &operand) {
    int degree1 = m_degree;
    int degree2 = operand.m_degree;
    Polynomial copy = operand;

    if (m_odds_array.size() > copy.m_odds_array.size()) {
        while (m_odds_array.size() > copy.m_odds_array.size()) {
            copy.m_odds_array.insert(copy.m_odds_array.begin(), 0);
        }
    }
    else if (m_odds_array.size() < copy.m_odds_array.size()) {
        while (m_odds_array.size() < copy.m_odds_array.size()) {
            m_odds_array.insert(m_odds_array.begin(), 0);
        }
    }
    for (unsigned int i = 0; i < m_odds_array.size(); ++i) {
        m_odds_array[i] -= copy.m_odds_array[i];
    }

    return *this;
}

Polynomial Polynomial::operator *(const Polynomial &operand) {
    m_degree *= operand.m_degree;
    std::vector<double> odds_array(m_degree + 1);
    for (unsigned int i = 0; i < m_odds_array.size(); ++i) {
        for (unsigned int j = 0; j < operand.m_odds_array.size(); ++j) {
            odds_array[i + j] += m_odds_array[i] * operand.m_odds_array[j];
        }
    }
    m_odds_array = odds_array;
    return *this;
}

double Polynomial::get_value(double x) {
    double sum = 0;
    for (unsigned int i = 0; i <= m_degree; ++i) {
        sum += m_odds_array[i] * pow(x, m_degree - i);
    }
    return sum;
}

void Polynomial::print_polynomial() {
    for (unsigned int i = 0; i <= m_degree; ++i) {
        std::cout << m_odds_array[i] << "x^" << m_degree - i;
        if (i != m_degree) {
            std::cout << " + ";
        }
    }
    std::cout << '\n';
}
