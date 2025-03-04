#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

struct Weapon {
    std::string Weapon_name;
    std::string Weapon_type;
    int Damage;
    float Weight;
    std::string Primary_stats;
};

void showWeaponData(std::vector<Weapon>& weapon) {
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

void printWeapons(const std::vector<Weapon> &weapon) {
    std::cout << std::left << std::setw(30) << "Weapon Name"
    << std::setw(25) << "Type"
    << std::setw(10) << "Damage"
    << std::setw(10) << "Weight"
    << std::setw(30) << "Primary Stats" << std::endl;

    for (const auto& weapon : weapon) {
        std::cout << std::left << std::setw(30) << weapon.Weapon_name
        << std::setw(25) << weapon.Weapon_type
        << std::setw(10) << weapon.Damage
        << std::setw(10) << weapon.Weight
        << std::setw(30) << weapon.Primary_stats << std::endl;
    }
}

void findWeapon(const std::vector<Weapon> &weapon) {
    std::string id = "Katana";
    for (const auto& weapon : weapon) {
        if (weapon.Weapon_type == id) {
            std::cout << std::left << std::setw(30) << weapon.Weapon_name
            << std::setw(25) << weapon.Weapon_type
            << std::setw(10) << weapon.Damage
            << std::setw(10) << weapon.Weight
            << std::setw(30) << weapon.Primary_stats << std::endl;
        }
    }
}

int countWeapons(const std::vector<Weapon> &weapon) {
    std::string id = "Longbow";
    int count = 0;
    for (const auto& weapon : weapon) {
        if (weapon.Weapon_type == id) {
            count++;
            std::cout << std::left << std::setw(30) << weapon.Weapon_name
            << std::setw(25) << weapon.Weapon_type
            << std::setw(10) << weapon.Damage
            << std::setw(10) << weapon.Weight
            << std::setw(30) << weapon.Primary_stats << std::endl;
        }
    }
    cout << "Total number of " << id<<  " weapons: " << count << std::endl;
    return count;
}

double HigLowAvgData(const std::vector<Weapon> &weapon){
    int high= 0, low= 999, count = 0;
    double avg = 0;
    for (const auto& weapon:weapon) {
        if (weapon.Damage > high) {
            high = weapon.Damage;
        }
        if (weapon.Damage < low) {
            low = weapon.Damage;
        }
        count++;
        avg = avg + weapon.Damage;
    }
    avg = avg / count;
    cout << "The highest damage is "<< high << endl;
    cout << "The lowest damage is "<< low << endl;
    cout << "The average damage is "<< avg << endl;
    return avg;
}

void keyWordSearch(const std::vector<Weapon> &weapon) {
    std::string id = "Night";
    for (const auto& weapon:weapon) {
        if (weapon.Weapon_name.find(id) != std::string::npos) {
            std::cout << std::left << std::setw(30) << weapon.Weapon_name
            << std::setw(25) << weapon.Weapon_type
            << std::setw(10) << weapon.Damage
            << std::setw(10) << weapon.Weight
            << std::setw(30) << weapon.Primary_stats << std::endl;
        }
    }
}

// void sort(const std::vector<Weapon> &weapon) {
//     std::sort(weapon.begin(), weapon.end(), [](const weapon &a, const weapon &b));
//     for (const auto& weapon : weapon) {
//         std::cout << std::left << std::setw(30) << weapon.Weapon_name
//         << std::setw(25) << weapon.Weapon_type
//         << std::setw(10) << weapon.Damage
//         << std::setw(10) << weapon.Weight
//         << std::setw(30) << weapon.Primary_stats << std::endl;
//     }
// }

int main(){
    std::vector<Weapon> weapons;
    showWeaponData(weapons);
    std::cout << "Total weapons loaded: " << weapons.size() << std::endl;
    printWeapons(weapons);
    findWeapon(weapons);
    int count = countWeapons(weapons);
    double avg = HigLowAvgData(weapons);
    keyWordSearch(weapons);
    // sort(weapons);
    return 0;
}