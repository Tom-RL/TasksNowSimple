#pragma once
#ifndef TASK_H
#define TASK_H

#include <string>
#include <string_view>
#include <iostream>

class Task
{
private:
    int m_id{};
    std::string m_name{};
    bool m_completed{ false };

public:
    // Construtor
    Task(int id, std::string_view name, bool completed = false);

    // Getters
    int getId() const;
    std::string getName() const;
    bool isCompleted() const;

    // Setters e m�todos utilit�rios
    void setName(std::string_view name);
    void markCompleted();
    void toggleCompleted();

    // Operador de sa�da
    friend std::ostream& operator<<(std::ostream& os, const Task& task);
};

#endif // TASK_H
