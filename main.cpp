#include <iostream>
#include <vector>

void printVector(std::vector<int> v)
{
    if (v.empty())
        std::cout << "Vector is empty!\n";
    else
    {
        for (int i = 0; i < v.size(); i++)
        {
            std::cout << v[i] << " ";
        }
        std::cout << "\n";
    }
}

std::vector<int> revertVector(std::vector<int> v)
{
    for (int i = 0; i < v.size() / 2; i++)
    {
        int buffer = v[i];
        v[i] = v[v.size() - 1 - i];
        v[v.size() - 1 - i] = buffer;
    }
    return v;
}

int main() {
    const int REAL_SIZE_LIMIT = 20;
    std::vector<int> v;
    v.reserve(REAL_SIZE_LIMIT);
    int command = 0;
    while (command != -1)
    {
        std::cout << "Enter the command: ";
        std::cin >> command;
        if (command != -1)
        {
            if (v.size() == REAL_SIZE_LIMIT)
            {
                v = revertVector(v);
                v.pop_back();
                v = revertVector(v);
                v.push_back(command);
            }
            else
            {
                v.push_back(command);
            }
        }
        else
        {
            printVector(v);
        }
    }
    std::cout << "Program is ended.\n";
    return 0;
}
