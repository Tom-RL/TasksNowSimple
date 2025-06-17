#include "Storage.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool saveTaskListInFile(const std::vector<Task>& taskList, const std::string& filename)
{
    std::ofstream file(filename);
    if (!file)
    {
        std::cerr << "Failed to open " << filename << " for writing.\n";
        return false;
    }

    for (const auto& task : taskList)
    {
        file << task.getId() << ';'
            << task.getName() << ';'
            << task.getDescription() << ';'
            << task.isCompleted() << '\n';
    }

    return true;
}

std::vector<Task> loadTaskList(const std::string& filename)
{
    std::vector<Task> tasks;
    std::ifstream file(filename);
    if (!file)
        return tasks;

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string idStr, name, description, completedStr;

        std::getline(ss, idStr, ';');
        std::getline(ss, name, ';');
        std::getline(ss, description, ';');
        std::getline(ss, completedStr);

        int id = std::stoi(idStr);
        bool completed = (completedStr == "1");

        tasks.emplace_back(Task{ name, description, id, completed });
    }

    return tasks;
}
