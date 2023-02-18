#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

class ItemTracker
{
private:
    std::map<std::string, int> itemFrequency;
    std::string inputFilename;
    std::string outputFilename;

public:
    ItemTracker(std::string inputFile, std::string outputFile)
    {
        inputFilename = inputFile;
        outputFilename = outputFile;
        updateItemFrequency();
        backupData();
    }

    void updateItemFrequency()
    {
        std::ifstream inputFile(inputFilename);
        std::string item;

        while (inputFile >> item)
        {
            itemFrequency[item] += 1;
        }

        inputFile.close();
    }

    void backupData()
    {
        std::ofstream outputFile(outputFilename);

        for (std::map<std::string, int>::iterator iter = itemFrequency.begin(); iter != itemFrequency.end(); ++iter)
        {
            outputFile << iter->first << " " << iter->second << std::endl;
        }

        outputFile.close();
    }

    int getFrequency(std::string item)
    {
        std::map<std::string, int>::iterator iter = itemFrequency.find(item);
        if (iter != itemFrequency.end())
        {
            return iter->second;
        }
        else
        {
            return 0;
        }
    }

    void printFrequencies()
    {
        for (std::map<std::string, int>::iterator iter = itemFrequency.begin(); iter != itemFrequency.end(); ++iter)
        {
            std::cout << iter->first << " " << iter->second << std::endl;
        }
    }

    void printHistogram()
    {
        for (std::map<std::string, int>::iterator iter = itemFrequency.begin(); iter != itemFrequency.end(); ++iter)
        {
            std::cout << iter->first << " ";
            for (int i = 0; i < iter->second; i++)
            {
                std::cout << "*";
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    ItemTracker itemTracker("input.txt", "frequency.dat");

    int option;
    string item;

    do
    {
        cout << "Please select an option:\n"
             << "1. Get frequency of a specific item\n"
             << "2. Print frequencies of all items\n"
             << "3. Print histogram of item frequencies\n"
             << "4. Exit program\n";
        cin >> option;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (option)
        {
        case 1:
            cout << "Please enter the item you wish to look for: ";
            cin >> item;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a word.\n";
                continue;
            }
            if (itemTracker.getFrequency(item) == 0)
            {
                cout << "The item \"" << item << "\" does not exist in the frequency data.\n";
            }
            else
            {
                cout << "The frequency of \"" << item << "\" is " << itemTracker.getFrequency(item) << ".\n";
            }
            break;
        case 2:
            itemTracker.printFrequencies();
            break;
        case 3:
            itemTracker.printHistogram();
            break;
        case 4:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid option. Please enter a number between 1 and 4.\n";
        }
    } while (option != 4);

    return 0;
}
