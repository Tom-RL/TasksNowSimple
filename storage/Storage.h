#pragma once
#ifndef STORAGE_H
#define STORAGE_H

#include <vector>
#include "../task/Task.h"

static std::vector<Task> taskList{}; //task list global variable

bool saveTaskListInFile(const std::vector<Task>& taskList, const std::string& filename);
std::vector<Task> loadTaskList(const std::string& filename);

#endif // STORAGE_H
