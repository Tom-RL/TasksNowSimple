#include "Task.h"

// Construtor
Task::Task(int id, std::string_view name, bool completed)
    : m_id{ id }, m_name{ name }, m_completed{ completed }
{
}

// Getters
int Task::getId() const { return m_id; }
std::string Task::getName() const { return m_name; }
bool Task::isCompleted() const { return m_completed; }

// Setters
void Task::setName(std::string_view name) { m_name = name; }
void Task::markCompleted() { m_completed = true; }
void Task::toggleCompleted() { m_completed = !m_completed; }

// Operador de sa�da
std::ostream& operator<<(std::ostream& os, const Task& task)
{
    os << "ID: " << task.m_id
        << " | Nome: " << task.m_name
        << " | Conclu�da: " << (task.m_completed ? "Sim" : "N�o");
    return os;
}
