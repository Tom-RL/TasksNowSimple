#include "Task.h"

// Constructor
Task::Task(std::string_view name, std::string_view description, int id, bool completed=false)
    : m_name{ name }
    , m_description{ description }
    , m_id{ id }
    ,m_completed { completed }
{}

// Getters
int Task::getId() const { return m_id; }
std::string Task::getName() const { return m_name; }
std::string Task::getDescription() const { return m_description; }
bool Task::isCompleted() const { return m_completed; }

// Setters
void Task::setId(int id) { m_id = id; }
void Task::setName(std::string_view name) { m_name = name; }
void Task::setDescription(std::string_view description) { m_description = description; }
void Task::markCompleted() { m_completed = true; }

// Output Operator
std::ostream& operator<<(std::ostream& os, const Task& task)
{
    os << "ID: " << task.m_id
        << " | Name: " << task.m_name
		<< " | Description: " << task.m_description
        << " | Completed: " << (task.m_completed ? "Yes" : "No");
    return os;
}
