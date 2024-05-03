// Lab_2_Crypto.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

void cipherDecryption(std::string cypheredText, std::string key) {

    std::string result{};
    int keyIterator{};
    for (int i = 0; i < cypheredText.length(); i++) {
        int temp = ((cypheredText[i] ^ key[keyIterator]) ^ key[keyIterator] ) ^ key[keyIterator];
        keyIterator++;
        if (keyIterator > key.length())
            keyIterator = 0;
        result.push_back(temp);

    }

    std::cout << result << std::endl;


}

int main()
{
 

    std::string myStr("Hi Alice, this is Bob. To work on our website, you need to log in to the administration panel.The login credentials are provided in the following email.");
    std::cout << myStr.length() << std::endl;

    std::fstream myFile;
    myFile.open("C:\\Users\\dsmet\\source\\repos\\Lab_2_Crypto\\Lab_2_Crypto\\CryptoText.txt", std::ios::out | std::ios::in);
    std::string fileString{};
    std::string initVec{ "0102030405060708090a0b0c0d0e0f0f -" };
    if(myFile.is_open())
        while (std::getline(myFile, fileString)) {

            cipherDecryption(fileString, initVec);

        }


}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
