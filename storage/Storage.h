#pragma once
#ifndef STORAGE_H
#define STORAGE_H

#include <vector>
#include "../task/Task.h"

bool saveTaskListInFile(const std::vector<Task>& taskList, const std::string& filename);
std::vector<Task> loadTaskList(const std::string& filename);

#endif // STORAGE_H
