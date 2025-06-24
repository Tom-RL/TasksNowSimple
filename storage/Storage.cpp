#include "Storage.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <sstream>
#include <iostream>

using json = nlohmann::ordered_json;

bool saveTaskListInFile(const std::vector<Task>& taskList, const std::string& filename)
{
    json jTasks{ json::array() };

    for (const auto& task : taskList)
    {
        jTasks.push_back({
            { "id", task.getId() },
            { "name", task.getName() },
            { "description", task.getDescription() },
            { "completed", task.isCompleted() }
        });
    }

    std::ofstream file(filename);
    if (!file)
    {
        std::cerr << "Could not open file for writing.\n";
        return false;
    }

    file << jTasks.dump(4);
    return true;
}

std::vector<Task> loadTaskList(const std::string& filename)
{
    std::vector<Task> tasks;
    std::ifstream file(filename);
    if (!file)
    {
        std::cerr << "file " << filename << " starting with empty task list.\n";
        return tasks;
    }

    json jTasks{};

    try {
        file >> jTasks;
        for (const auto& j : jTasks)
        {
            tasks.emplace_back(Task{
                j.at("name").get<std::string>(),
                j.at("description").get<std::string>(),
                j.at("id").get<int>(),
                j.at("completed").get<bool>()
                });
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error loading JSON: " << e.what() << '\n';
    }

    return tasks;
}
