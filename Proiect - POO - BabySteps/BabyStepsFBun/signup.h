#ifndef SIGNUP_H
#define SIGNUP_H
#include "qstring.h"
#include <iostream>
#include <sstream>
using namespace std;


class SignUp
{
public:
    SignUp();
    bool VerifyLogin(QString Username, QString Password);
    string HashFunction(string Password);
};

#endif // SIGNUP_H
