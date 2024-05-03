// Lab_2_Crypto.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>


unsigned hexToDecimal(const std::string& hexString) {
    unsigned decimalValue;
    std::stringstream ss;
    ss << std::hex << hexString;
    ss >> decimalValue;
    return decimalValue;
}


unsigned asciiToDecimal(char symbol) {

    unsigned num = static_cast<int>(symbol);
    return num;

}

/*

void cipherDecryption(std::string cypheredText, std::string key) {

    std::string result{};
    int keyIterator{};
    for (int i = 0; i < cypheredText.length(); i++) {
        int temp = ((cypheredText[i] ^ cypheredText[i]));
       //keyIterator++;
        //if (keyIterator > key.length())
            //keyIterator = 0;
        result.push_back(temp);

    }

    std::cout << result << std::endl;


}
*/


std::string ascii_to_hex(const std::string& input_string) {
    std::stringstream hex_stream;
    hex_stream << std::hex << std::setfill('0');

    for (char c : input_string) {
        hex_stream << std::setw(2) << static_cast<int>(c);
    }

    return hex_stream.str();
}

unsigned cipherDecryption(unsigned plainSymbol, unsigned cipheredSymbol) {

    
    return plainSymbol ^ cipheredSymbol;

}

std::string hex_to_ascii(const std::string& hex_str) {
    std::stringstream result_stream;

    // Проходим по строке с шестнадцатеричным числом с шагом 2 (по два символа)
    for (size_t i = 0; i < hex_str.size(); i += 2) {
        // Извлекаем два символа, представляющих шестнадцатеричное число
        std::string hex_byte = hex_str.substr(i, 2);

        // Преобразуем шестнадцатеричное число в целое число
        int value;
        std::stringstream(hex_byte) >> std::hex >> value;

        // Преобразуем целое число в символ ASCII и добавляем его к результату
        result_stream << static_cast<char>(value);
    }

    return result_stream.str();
}


std::string hex_xor(const std::string& hex_str1, const std::string& hex_str2) {
    // Проверяем, что строки одинаковой длины
    if (hex_str1.size() != hex_str2.size()) {
        std::cerr << "Error: Strings must be of equal length." << std::endl;
        return "";
    }

    std::stringstream result_stream;
    for (size_t i = 0; i < hex_str1.size(); ++i) {
        // Преобразуем символы в числа
        int hex1, hex2;
        std::stringstream(hex_str1.substr(i, 1)) >> std::hex >> hex1;
        std::stringstream(hex_str2.substr(i, 1)) >> std::hex >> hex2;

        // Выполняем операцию XOR над числами и преобразуем результат обратно в шестнадцатеричное представление
        result_stream << std::hex << (hex1 ^ hex2);
    }

    return result_stream.str();
}

int main()
{
 
    /*
    std::string myStr("Hi Alice, this is Bob. To work on our website, you need to log in to the administration panel.The login credentials are provided in the following email.");
    std::cout << myStr.length() << std::endl;

    std::fstream myFile;
    myFile.open("C:\\Users\\dsmet\\OneDrive\\Документы\\GitHub\\Lab_2_Crypto\\CryptoText.txt", std::ios::out | std::ios::in);
    std::string fileString{};
    std::string initVec{ "0102030405060708090a0b0c0d0e0f0f -" };
    if(myFile.is_open())
        while (std::getline(myFile, fileString)) {

            cipherDecryption(fileString, initVec);

        }
    */


    std::string cipher1 = "5f991ecef9c68bd0460c90ac68726f9c984c0f38fc7b750f7fd5a8789e521b645e9d3c82f4b096540318491d23f8d429599b7663ad4bc4fec02186136f3630b4d1a817cbef838dd00a244ba914e8a55d61c8cd4d00d4d7a560bd71d41b91a3117a46ba005e073aca14e7f36f90dec63bb5ddd4217e244839c23ed12b0990261507dbc98386ab90f1021665e3d03030503da21035197d09f4";
    std::string cipher2 = "54825bebf0c19cdc0b4097e4676e3dd584193f77ed3c213e3ed58a64894b556a5dd869d7e7f48c580f47001927a78727599c3237e85dc5bdc62bd21169384faddefa0cc854825bebf0c19cdc0b4097e4676e3dd584193f77ed3c213e3ed58a64894b556a5dd869d7e7f48c580f47001927a78727599c3237e85dc5bdc62bd21169384faddefa0cc854825bebf0c19cdc0b4097e4676e3dd5";
    std::string myStr("Hi Alice, this is Bob. To work on our website, you need to log in to the administration panel.The login credentials are provided in the following email.");

    unsigned strIndex{};

    std::string ascii_hex{ hex_xor(ascii_to_hex(myStr), hex_xor(cipher1, cipher2))};
    std::cout << ascii_hex << std::endl;





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
