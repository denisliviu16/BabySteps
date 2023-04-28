#include "signup.h"

SignUp::SignUp()
{

}

int charToInt(char c) {
    return static_cast<char>(c);
}

string vectorToString(const vector<int>& vec) {
    stringstream ss;
    for (int i = 0; i < vec.size(); i++) {
        ss << vec[i];
    }
    return ss.str();
}


string SignUp::HashFunction(string Password)
{
    int PassWordLength = Password.length();
    unsigned char* HashedPassword = new unsigned char[2 * PassWordLength+1];
    HashedPassword[2 * PassWordLength] = '\n';
    unsigned char C1;
    unsigned char C2;
    for (int i = 0; i < PassWordLength; i++)
    {
        C1 = Password[i] >> 4;
        C2 = Password[i] << 4;
        C2 = C2 >> 4;

        HashedPassword[2*i] = C1;
        HashedPassword[2*i + 1] = C2;

    }

    int nrCycles = PassWordLength + HashedPassword[PassWordLength * 2 - 4]/PassWordLength;
    for (int i = 0; i < nrCycles; i++)
    {
        if (i % 3 == 0)
        {
            for (int j = 0; j < PassWordLength; j++)
            {
                HashedPassword[j] = HashedPassword[j] + HashedPassword[PassWordLength * 2 - j-1];
            }
        }
        if (i % 3 == 1)
        {
            for (int j = 0; j < PassWordLength; j++)
            {
                HashedPassword[PassWordLength * 2 - j-1] = HashedPassword[j] + HashedPassword[PassWordLength * 2 - j];
            }
        }
        if (i % 3 == 2)
        {
            for (int j = 0; j < PassWordLength; j++)
            {
                HashedPassword[PassWordLength * 2 - j - 1] = HashedPassword[PassWordLength * 2 - j - 1] / 2;
                HashedPassword[j] = HashedPassword[j] / 2;
            }
        }

    }
    Password.clear();
    for (int i = 0; i < PassWordLength * 2; i++)
        Password.push_back(HashedPassword[i]);

    return Password;
}


bool SignUp::VerifyLogin(QString Username, QString Password)
{
    string PassW=Password.toStdString();
    vector<int> vct;

    PassW=this->HashFunction(PassW);


    for (int i = 0; i<PassW.length(); i++)
        {
            int ascii = charToInt(PassW[i]);
            vct.push_back(ascii);
        }

    string albinuta = vectorToString(vct);

    if(Username=="denis"&&albinuta=="15284774106-12337708-62-9924-821005325")
        return true;

    return false;
}
