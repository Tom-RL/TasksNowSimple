#include "Storage.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <sstream>
#include <iostream>

using json = nlohmann::ordered_json;

bool saveTaskListInFile(const std::vector<Task>& taskList, const std::string& filename)
{
    json jTasks{ json::array() };

    try {
        std::ofstream file(filename, std::ios::binary);
        if (!file)
        {
            std::cerr << "Could not open file for writing: " << filename << '\n';
            return false;
        }

        json jTasks = json::array();

        for (const auto& task : taskList)
        {
            jTasks.push_back({
                { "id", task.getId() },
                { "name", task.getName() },
                { "description", task.getDescription() },
                { "completed", task.isCompleted() }
                });
        }

        file << jTasks.dump(4);
    }
    catch (const std::exception& e) {
		std::cerr << "Error saving task list\n";
        // std::cerr << "Could not open file for writing: " << e.what() << '\n';
        return false;
    }

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
        if (jTasks.is_null() || !jTasks.is_array())
        {
            std::cerr << "Invalid JSON format in file: " << filename << '\n';
            return tasks;
		}

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
        std::cerr << "Error loading list\n";
		// std::cerr << "Could not read file: " << e.what() << '\n';
    }

    return tasks;
}
