#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

struct Weapon {
    std::string Weapon_name;
    std::string Weapon_type;
    int Damage;
    float Weight;
    std::string Primary_stats;
};

void printWeaponData(std::vector<Weapon>& weapon) {
    std::ifstream inFile;
    inFile.open("C:/Users/doria/OneDrive - Dundalk Institute of Technology/Year 2/C++/CA1/CA1_text.csv");

    if (!inFile) {
        std::cout << "Error: Could not open file!" << std::endl;
        return;
    }
    std::string line;
    std::getline(inFile, line);

    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        Weapon weapons;
        std::string Damage, Weight;

        std::getline(ss, weapons.Weapon_name, ',');
        std::getline(ss, weapons.Weapon_type, ',');
        std::getline(ss, Damage, ',');
        std::getline(ss, Weight, ',');
        std::getline(ss, weapons.Primary_stats, ',');

        weapons.Damage = std::stoi(Damage);
        weapons.Weight = std::stof(Weight);

        weapon.push_back(weapons);
    }
    inFile.close();
    std::cout <<"Data loaded"<< std::endl;
}
int main(){
    std::vector<Weapon> weapons;

    printWeaponData(weapons);

    std::cout << "Total weapons loaded: " << weapons.size() << std::endl;

    return 0;
}