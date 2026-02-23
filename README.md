# 📝 TasksNowSimple (TNS)

**TasksNowSimple (TNS)** is a simple and fast terminal-based task manager written in C++. It's designed for users who want to keep track of their tasks directly from the command line with ease and speed.

> ⚙️ Lightweight. 🔤 JSON-based. ✨ No distractions — just productivity.

---

## 🚀 Features

* ✅ Add tasks
* 📋 List pending and completed tasks
* 🗑️ Remove tasks
* 🖊️ Edit task descriptions *(coming soon)*
* ✔️ Mark/unmark tasks as done
* 💾 Saves tasks in a local JSON file

---

## 📦 Getting Started

### Clone the Repository

```bash
git clone https://github.com/Tom-RL/TasksNowSimple.git
cd TasksNowSimple
```

### Compile

**On Linux:**

> ⚠️ Currently still in development and the next version will be the only one version.

**On Windows Visual Studio(Linux will be the main version):**

* Open the `.sln` file
* Build in `Debug` or `Release` mode

---

## 📁 Project Structure

```
TasksNowSimple/
├── nlohmann/                 # JSON library (json.hpp)
│   └── json.hpp
│
├── storage/                  # Handles reading/writing data
│   ├── Storage.cpp
│   └── Storage.h
│
├── task/                     # Task data structure and logic
│   ├── Task.cpp
│   └── Task.h
│
├── TasksNowSimple.cpp        # Main program entry point (CLI)
├── README.md
├── LICENSE
├── .gitignore
└── .gitattributes
```

---

## 🔄 Upcoming Remake (v2)

TNS is evolving! A complete redesign is planned to improve scalability, maintainability, and cross-platform support.

> 🛠️ The project will be split into three parts:

* **Core (C++ DLL):** Handles all task logic and data operations
* **CLI (C++):** Terminal interface using the core as a dynamic library
* **GUI (C# + Avalonia) or (QT):** Cross-platform graphical interface built on top of the core

This change will allow both terminal lovers and GUI users to benefit from the same powerful backend.

---

## 💡 Future Plans

* [ ] Modular core as a shared library (DLL)
* [ ] Avalonia-based GUI or QT GUI (cross-platform)
* [ ] Command-line improvements (better UX)
* [ ] Settings system (themes, autosave, etc.)
* [ ] Database support (SQLite, optional)
* [ ] Installer / Deployment support

---

## 👤 About the Developer

**Richard Pierre**

> Passionate about simplicity, productivity, and building things that just work.

* 💻 Focused on C++, C#, and UI/UX
* 🧠 Always learning and improving
* 🔗 [LinkedIn](https://www.linkedin.com/in/richard-pierre-386194278/)

---

## 🤝 Contributing

Contributions, ideas, and suggestions are welcome! Feel free to open issues or submit pull requests.

---

## 📄 License

This project is licensed under the Apache 2.0 License — see the [LICENSE](LICENSE) file for details.

---

### 🌟 **Star this repo** if you like it — and stay tuned for the upcoming remake!
