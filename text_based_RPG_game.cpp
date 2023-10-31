#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Character {
public:
    Character(const std::string& name, int health, int damage) : name(name), health(health), damage(damage) {}

    void takeDamage(int amount) {
        health -= amount;
        if (health < 0) health = 0;
    }

    bool isAlive() const {
        return health > 0;
    }

    int getDamage() const {
        return damage;
    }

    const std::string& getName() const {
        return name;
    }

private:
    std::string name;
    int health;
    int damage;
};

class Monster {
public:
    Monster(const std::string& name, int health, int damage) : name(name), health(health), damage(damage) {}

    void takeDamage(int amount) {
        health -= amount;
        if (health < 0) health = 0;
    }

    bool isAlive() const {
        return health > 0;
    }

    int getDamage() const {
        return damage;
    }

    const std::string& getName() const {
        return name;
    }

private:
    std::string name;
    int health;
    int damage;
};

int main() {
    srand(static_cast<unsigned>(std::time(nullptr));

    std::cout << "Welcome to the Text-Based RPG Game!" << std::endl;

    Character player("Hero", 100, 20);

    while (player.isAlive()) {
        std::cout << "You are in a forest. What do you want to do?" << std::endl;
        std::cout << "1. Explore" << std::endl;
        std::cout << "2. Check Character Status" << std::endl;
        std::cout << "3. Quit" << std::endl;
        std::cout << "Choose an option: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int encounter = rand() % 3; // 0: No encounter, 1: Easy Monster, 2: Tough Monster
                if (encounter == 0) {
                    std::cout << "You explore the forest and find nothing of interest." << std::endl;
                } else if (encounter == 1) {
                    Monster monster("Goblin", 40, 10);
                    std::cout << "You encounter a Goblin!" << std::endl;
                    while (player.isAlive() && monster.isAlive()) {
                        player.takeDamage(monster.getDamage());
                        monster.takeDamage(player.getDamage());
                        std::cout << "You hit the Goblin for " << player.getDamage() << " damage." << std::endl;
                        std::cout << "The Goblin hits you for " << monster.getDamage() << " damage." << std::endl;
                    }
                    if (player.isAlive()) {
                        std::cout << "You defeat the Goblin and continue exploring." << std::endl;
                    } else {
                        std::cout << "You were defeated by the Goblin. Game over." << std::endl;
                        return 0;
                    }
                } else if (encounter == 2) {
                    Monster monster("Dragon", 80, 20);
                    std::cout << "You encounter a Dragon!" << std::endl;
                    while (player.isAlive() && monster.isAlive()) {
                        player.takeDamage(monster.getDamage());
                        monster.takeDamage(player.getDamage());
                        std::cout << "You hit the Dragon for " << player.getDamage() << " damage." << std::endl;
                        std::cout << "The Dragon hits you for " << monster.getDamage() << " damage." << std::endl;
                    }
                    if (player.isAlive()) {
                        std::cout << "You defeat the Dragon and continue exploring." << std::endl;
                    } else {
                        std::cout << "You were defeated by the Dragon. Game over." << std::endl;
                        return 0;
                    }
                }
                break;
            }
            case 2:
                std::cout << "Character Status:" << std::endl;
                std::cout << "Name: " << player.getName() << std::endl;
                std::cout << "Health: " << player.isAlive() ? std::to_string(player.isAlive()) : "Dead" << std::endl;
                std::cout << "Damage: " << player.getDamage() << std::endl;
                break;
            case 3:
                std::cout << "Thank you for playing! See you next time." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    }

    std::cout << "You have been defeated. Game over." << std::endl;

    return 0;
}
