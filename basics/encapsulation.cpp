#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    float grade;

public:
    Student(std::string n, float g) : name(n), grade(g) {}

    // Accessors (Getters)
    std::string getName() {
        return name;
    }

    float getGrade() {
        return grade;
    }

    // Mutators (Setters)
    void setName(std::string newName) {
        name = newName;
    }

    void updateGrade(float newGrade) {
        if (newGrade >= 0 && newGrade <= 100) {
            grade = newGrade;
        }
    }
};

int main() {
    Student student("John", 85.5);

    std::cout << "Name: " << student.getName() << ", Grade: " << student.getGrade() << std::endl;

    student.updateGrade(90.0);
    std::cout << "Updated Grade: " << student.getGrade() << std::endl;  // Output: "Updated Grade: 90"

    return 0;
}
