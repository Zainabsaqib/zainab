#include <iostream>
#include <fstream>
#include <ctime>
int main()
{
    time_t currentTime = time(0);
    tm* timeInfo = localtime(&currentTime);
    std::ofstream outFile("time_data.bin", std::ios::binary);
    if (!outFile)
    {
        std::cerr << "Failed to open the file for writing." << std::endl;
        return 1;

    }
    outFile.write(reinterpret_cast<char*>(timeInfo), sizeof(tm));
    outFile.close();
    std::ifstream inFile("time_data.bin", std::ios::binary);
    if (!inFile)
    {
        std::cerr << "Failed to open the file for reading." << std::endl;
        return 1;

    }
    tm readTimeInfo;
    inFile.read(reinterpret_cast<char*>(&readTimeInfo), sizeof(tm));
    inFile.close();
    std::cout << "Original Time: " << asctime(timeInfo);
    std::cout << "Read Time: " << asctime(&readTimeInfo);
    return 0;

}
