#pragma once
#ifndef TASK_H
#define TASK_H

#include <string>
#include <string_view>
#include <iostream>

class Task
{
private:
    std::string m_name{};
	std::string m_description{};
    int m_id{};
    bool m_completed{ false };

public:
    // Construtor
    Task(std::string_view name, std::string_view description, int id, bool completed);

    // Getters
    int getId() const;
    std::string getName() const;
	std::string getDescription() const;
    bool isCompleted() const;

    // Setters and utility methods
	void setId(int id);
    void setName(std::string_view name);
	void setDescription(std::string_view description);
    void markCompleted();

    // Output Operator
    friend std::ostream& operator<<(std::ostream& os, const Task& task);
};

#endif // TASK_H
