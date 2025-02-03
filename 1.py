import json


class Student:
    def __init__(self, student_id, name, grades):
        self.student_id = student_id
        self.name = name
        self.grades = grades

    def __repr__(self):
        return f"学号: {self.student_id}, 姓名: {self.name}, 成绩: {self.grades}"


class StudentManagementSystem:
    def __init__(self):
        self.students = []
        self.load_data()

    def add_student(self, student_id, name, grades):
        if any(s.student_id == student_id for s in self.students):
            print("学号已存在，请重新输入。")
            return
        new_student = Student(student_id, name, grades)
        self.students.append(new_student)
        self.save_data()
        print("学生信息添加成功。")

    def query_student(self, search_term):
        for student in self.students:
            if student.student_id == search_term or student.name == search_term:
                print(student)
                return
        print("未找到学生。")

    def modify_student(self, student_id, new_name=None, new_grades=None):
        for student in self.students:
            if student.student_id == student_id:
                if new_name:
                    student.name = new_name
                if new_grades:
                    student.grades = new_grades
                self.save_data()
                print("学生信息修改成功。")
                return
        print("未找到学生。")

    def delete_student(self, student_id):
        for student in self.students:
            if student.student_id == student_id:
                self.students.remove(student)
                self.save_data()
                print("学生信息删除成功。")
                return
        print("未找到学生。")

    def display_students(self, sort_by='student_id'):
        if sort_by == 'student_id':
            self.students.sort(key=lambda s: s.student_id)
        elif sort_by == 'grades':
            self.students.sort(key=lambda s: sum(s.grades.values()) / len(s.grades))

        for student in self.students:
            print(student)

    def calculate_statistics(self):
        if not self.students:
            print("没有学生数据。")
            return

        total_score = 0
        highest_score = float('-inf')
        lowest_score = float('inf')
        count = 0

        for student in self.students:
            average_score = sum(student.grades.values()) / len(student.grades)
            total_score += average_score
            highest_score = max(highest_score, average_score)
            lowest_score = min(lowest_score, average_score)
            count += 1

        print(f"平均成绩: {total_score / count:.2f}")
        print(f"最高分: {highest_score:.2f}")
        print(f"最低分: {lowest_score:.2f}")

    def save_data(self):
        with open('students.json', 'w', encoding='utf-8') as file:
            json.dump([s.__dict__ for s in self.students], file, ensure_ascii=False, indent=4)

    def load_data(self):
        try:
            with open('students.json', 'r', encoding='utf-8') as file:
                students_data = json.load(file)
                self.students = [Student(**data) for data in students_data]
        except FileNotFoundError:
            self.students = []


if __name__ == "__main__":
    system = StudentManagementSystem()

    while True:
        print("\n学生成绩管理系统")
        print("1. 添加学生")
        print("2. 查询学生")
        print("3. 修改学生")
        print("4. 删除学生")
        print("5. 显示所有学生信息")
        print("6. 统计信息")
        print("7. 退出")

        choice = input("请选择操作: ")
        if choice == '1':
            student_id = input("输入学号: ")
            name = input("输入姓名: ")
            grades = {}
            while True:
                course = input("输入课程名 (输入 'done' 完成): ")
                if course == 'done':
                    break
                score = float(input(f"输入 {course} 成绩: "))
                grades[course] = score
            system.add_student(student_id, name, grades)

        elif choice == '2':
            search_term = input("输入学号或姓名: ")
            system.query_student(search_term)

        elif choice == '3':
            student_id = input("输入学号: ")
            new_name = input("输入新姓名 (留空则不修改): ")
            new_grades = {}
            while True:
                course = input("输入课程名 (输入 'done' 完成): ")
                if course == 'done':
                    break
                score = float(input(f"输入 {course} 新成绩: "))
                new_grades[course] = score
            system.modify_student(student_id, new_name, new_grades)

        elif choice == '4':
            student_id = input("输入学号: ")
            system.delete_student(student_id)

        elif choice == '5':
            sort_by = input("选择排序方式（学号或成绩）: ")
            system.display_students(sort_by)

        elif choice == '6':
            system.calculate_statistics()

        elif choice == '7':
            print("退出系统。")
            break

        else:
            print("无效输入，请重新选择。")