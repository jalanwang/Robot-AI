#include <iostream>
#include <algorithm>
#include <optional>
#include <stdexcept>
#include <string>
#include <vector>

struct Student {
    int id;
    std::string name;
    int age;
};

class StudentRepository {
public:
    void initSchema() {}

    void clear() {
        storage_.clear();
    }

    void create(const Student& s) {
        if (getById(s.id)) {
            throw std::runtime_error("Student already exists: id=" + std::to_string(s.id));
        }
        storage_.push_back(s);
    }

    std::optional<Student> getById(int id) const {
        auto it = findById(id);
        if (it == storage_.end()) {
            return std::nullopt;
        }
        return *it;
    }

    std::vector<Student> getAll() const {
        return storage_;
    }

    void update(const Student& s) {
        auto it = findById(s.id);
        if (it == storage_.end()) {
            throw std::runtime_error("Student not found: id=" + std::to_string(s.id));
        }
        *it = s;
    }

    void remove(int id) {
        auto it = findById(id);
        if (it == storage_.end()) {
            throw std::runtime_error("Cannot remove missing student id=" + std::to_string(id));
        }
        storage_.erase(it);
    }

private:
    std::vector<Student> storage_;

    std::vector<Student>::iterator findById(int id) {
        return std::find_if(storage_.begin(), storage_.end(),
            [id](const Student& s) { return s.id == id; });
    }

    std::vector<Student>::const_iterator findById(int id) const {
        return std::find_if(storage_.cbegin(), storage_.cend(),
            [id](const Student& s) { return s.id == id; });
    }
};

void printAll(const std::vector<Student>& students) {
    std::cout << "\n== Current students ==\n";
    for (const auto& s : students) {
        std::cout << "#" << s.id << " " << s.name << " (" << s.age << ")\n";
    }
    if (students.empty()) {
        std::cout << "(empty)\n";
    }
}

int main() {
    try {
        StudentRepository repo;
        repo.initSchema();
        repo.clear();

        repo.create({1, "Alice", 20});
        repo.create({2, "Bob", 22});
        repo.create({3, "Carol", 23});
        printAll(repo.getAll());

        if (auto bob = repo.getById(2)) {
            std::cout << "\nFound id=2 -> " << bob->name << "\n";
        }

        repo.update({2, "Bob Stone", 23});
        repo.remove(1);
        printAll(repo.getAll());

        repo.remove(3);
        printAll(repo.getAll());
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }
}
