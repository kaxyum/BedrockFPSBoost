#include "Utils.h"
#include <string>
#include <filesystem>
#include <fstream>


std::string Utils::getFileUsername()
{
    std::string username;
    for (auto it = std::filesystem::current_path().begin(); it != std::filesystem::current_path().end(); ++it)
    {
        if (*it == "Users" && std::next(it) != std::filesystem::current_path().end())
        {
            username = std::next(it)->string();
            break;
        }
    }
    return username;
}

void Utils::setFPSBoost()
{
    std::string path = "C:\\Users\\" + getFileUsername() + "\\AppData\\Local\\Packages\\Microsoft.MinecraftUWP_8wekyb3d8bbwe\\LocalState\\games\\com.mojang\\minecraftpe\\options.txt";
    std::ifstream file(path);
    std::ostringstream updatedFile;
    std::string line;

    while (std::getline(file, line))
    {
        if (line.find("gfx_vsync") != std::string::npos)
        {
            updatedFile << "gfx_vsync:0\n";
        }else{
            updatedFile << line << "\n";
        }
    }
    file.close();
    std::ofstream newUpdatedFile(path);
    newUpdatedFile << updatedFile.str();
}