class GradeManager:
    def __init__(self):
        self.grades = []

    
    def add_grade(self, grade):
        if 0 <= grade <= 100: 
            self.grades.append(grade)
            print(f"Added grade: {grade}")
        else:
            print("Invalid grade! Please enter a value between 0 and 100.")

    
    def calculate_average(self):
        if not self.grades:
            print("No grades available to calculate average.")
            return 0
        return sum(self.grades) / len(self.grades)

    
    def display_grades(self):
        if not self.grades:
            print("No grades available.")
        else:
            print("\n--- Student Grades ---")
            for idx, grade in enumerate(self.grades, 1):
                print(f"{idx}. Grade: {grade}")
            print("----------------------")



if __name__ == "__main__":
    grade_manager = GradeManager()
    
    
    grade_manager.add_grade(85)
    grade_manager.add_grade(92)
    grade_manager.add_grade(78)
    grade_manager.add_grade(102)  # Invalid grade
    
    
    grade_manager.display_grades()
  
    average = grade_manager.calculate_average()
    print(f"\nAverage Grade: {average:.2f}")
