#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

struct Recipe {
    std::string name;
    std::vector<std::string> ingredients;
    std::vector<std::string> steps;
};

std::vector<Recipe> recipes;

void addRecipe() {
    Recipe r;
    std::cout << "Enter recipe name: ";
    std::getline(std::cin, r.name);

    int numIngredients;
    std::cout << "How many ingredients? ";
    std::cin >> numIngredients;
    std::cin.ignore();

    for (int i = 0; i < numIngredients; i++) {
        std::string ingredient;
        std::cout << "Enter ingredient " << i + 1 << ": ";
        std::getline(std::cin, ingredient);
        r.ingredients.push_back(ingredient);
    }

    int numSteps;
    std::cout << "How many steps? ";
    std::cin >> numSteps;
    std::cin.ignore();

    for (int i = 0; i < numSteps; i++) {
        std::string step;
        std::cout << "Enter step " << i + 1 << ": ";
        std::getline(std::cin, step);
        r.steps.push_back(step);
    }

    recipes.push_back(r);
    std::cout << "Recipe added successfully!\n";
}

void displayAll() {
    if (recipes.empty()) {
        std::cout << "No recipes found.\n";
        return;
    }
    for (int i = 0; i < recipes.size(); i++) {
        std::cout << "\n" << i + 1 << ". " << recipes.at(i).name << "\n";
        std::cout << "   Ingredients:\n";
        for (const std::string& ing : recipes.at(i).ingredients)
            std::cout << "     - " << ing << "\n";
        std::cout << "   Steps:\n";
        for (int j = 0; j < recipes.at(i).steps.size(); j++)
            std::cout << "     " << j + 1 << ". " << recipes.at(i).steps.at(j) << "\n";
    }
}

void searchRecipes() {
    std::string keyword;
    std::cout << "Enter name or ingredient to search: ";
    std::getline(std::cin, keyword);

    std::string keyLower = keyword;
    std::transform(keyLower.begin(), keyLower.end(), keyLower.begin(), ::tolower);

    bool found = false;
    for (const Recipe& r : recipes) {
        std::string nameLower = r.name;
        std::transform(nameLower.begin(), nameLower.end(), nameLower.begin(), ::tolower);

        if (nameLower.find(keyLower) != std::string::npos) {
            std::cout << "  - " << r.name << "\n";
            found = true;
            continue;
        }
        for (const std::string& ing : r.ingredients) {
            std::string ingLower = ing;
            std::transform(ingLower.begin(), ingLower.end(), ingLower.begin(), ::tolower);
            if (ingLower.find(keyLower) != std::string::npos) {
                std::cout << "  - " << r.name << " (contains: " << ing << ")\n";
                found = true;
                break;
            }
        }
    }
    if (!found) std::cout << "No recipes found matching that search.\n";
}

void removeRecipe() {
    if (recipes.empty()) { std::cout << "No recipes to remove.\n"; return; }
    displayAll();
    std::cout << "Enter recipe number to remove: ";
    int num;
    std::cin >> num;
    std::cin.ignore();
    if (num < 1 || num > recipes.size()) {
        std::cout << "Invalid selection.\n";
        return;
    }
    recipes.erase(recipes.begin() + num - 1);
    std::cout << "Recipe removed.\n";
}

void showStats() {
    if (recipes.empty()) { std::cout << "No recipes in collection.\n"; return; }

    int totalIngredients = 0, totalSteps = 0;
    for (const Recipe& r : recipes) {
        totalIngredients += r.ingredients.size();
        totalSteps += r.steps.size();
    }

    std::cout << "\nCOLLECTION STATISTICS\n";
    std::cout << "--------------------\n";
    std::cout << "Total recipes: " << recipes.size() << "\n";
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Average ingredients per recipe: " << (double)totalIngredients / recipes.size() << "\n";
    std::cout << "Average steps per recipe: " << (double)totalSteps / recipes.size() << "\n";
}

int main() {
    int choice;

    std::cout << "DYNAMIC RECIPE MANAGER\n";
    std::cout << "---------------------\n";

    do {
        std::cout << "\n1. Add Recipe\n";
        std::cout << "2. Display All Recipes\n";
        std::cout << "3. Search Recipes\n";
        std::cout << "4. Remove Recipe\n";
        std::cout << "5. Show Statistics\n";
        std::cout << "6. Exit\n";
        std::cout << "\nEnter choice: ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) addRecipe();
        else if (choice == 2) displayAll();
        else if (choice == 3) searchRecipes();
        else if (choice == 4) removeRecipe();
        else if (choice == 5) showStats();
        else if (choice != 6) std::cout << "Invalid choice.\n";

    } while (choice != 6);

    std::cout << "Goodbye!\n";
    return 0;
}