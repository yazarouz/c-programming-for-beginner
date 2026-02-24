// Author: yazarouz      || Date: 2026/02/22
// Tutorial: Understanding Functions in C - Beginner Friendly Guide
// Purpose: Learn how to create, call, and use functions effectively in C

#include <stdio.h>

//=============================================================================
// SECTION 1: WHAT IS A FUNCTION?
//=============================================================================
// A function is a reusable block of code that performs a specific task.
// Key benefits:
//1 . Code Reusability: Write once, use many times
//2 . Modularity: Break complex problems into smaller, manageable parts
//3 . Maintainability: Easier to debug and update
//4 . Readability: Makes code cleaner and more organized

//=============================================================================
// SECTION 2: FUNCTION SYNTAX & COMPONENTS
//=============================================================================
/*
   General Syntax:
    return_type function_name(parameters)
    {                                    
        // function body (code)          
        return value;  // if not void    
    }                                    
   

   Components:
   • return_type: Data type of value returned (int, float, char, void, etc.)
   • function_name: Descriptive name following variable naming rules
   • parameters: Input values (optional) - also called "formal parameters"
   • function body: Code that executes when function is called
   • return: Sends a value back to the caller (omit if return_type is void)
*/

//=============================================================================
// SECTION 3: THE FOUR TYPES OF FUNCTIONS
//=============================================================================

// TYPE 1: No parameters, No return value (void)
// Use when: You just want to execute some code without input/output
void printWelcomeMessage() {
    printf("=== Welcome to C Functions Tutorial! ===\n");
}

// TYPE 2: Has parameters, No return value (void)
// Use when: You need input to perform an action, but don't need a result back
void printStudentInfo(char name[], int studentId, float gpa) {
    printf("Name: %s\n", name);
    printf("ID: %d\n", studentId);
    printf("GPA: %.2f\n\n", gpa);
}

// TYPE 3: No parameters, Returns a value
// Use when: You want to get a computed value without providing input
int getFixedBonus() {
    // Returns a predefined bonus value
    return 500;
}

// TYPE 4: Has parameters AND returns a value (Most Common!)
// Use when: You need input to compute and return a result
float calculateAverage(int score1, int score2, int score3) {
    // Calculate sum first
    int total = score1 + score2 + score3;
    
    // Cast to float to ensure decimal division
    float average = (float)total / 3;
    
    return average;  // Send result back to caller
}

//=============================================================================
// SECTION 4: HELPER FUNCTIONS FOR BETTER LEARNING
//=============================================================================

// Function to print a visual separator line
void printSeparator() {
    printf("----------------------------------------\n");
}

// Function to demonstrate function calling another function
void demonstrateNestedCall() {
    printf("Calling a function from inside another function:\n");
    printWelcomeMessage();  // Calling Type 1 function
    printSeparator();
}

//=============================================================================
// SECTION 5: MAIN FUNCTION - WHERE EXECUTION STARTS
//=============================================================================
int main() {
    printf("\n🎓 C FUNCTIONS TUTORIAL - By yazarouz\n");
    printSeparator();

    // --- Example 1: Type 1 Function (No params, No return) ---
    printf("\n[Example 1] Type 1: void function without parameters\n");
    printWelcomeMessage();  // Simply call the function
    printSeparator();

    // --- Example 2: Type 2 Function (With params, No return) ---
    printf("\n[Example 2] Type 2: void function with parameters\n");
    // Pass arguments that match the parameter types and order
    printStudentInfo("Alex Johnson", 12345, 3.85);

    // --- Example 3: Type 3 Function (No params, Returns value) ---
    printf("\n[Example 3] Type 3: Function that returns a value (no params)\n");
    int bonus = getFixedBonus();  // Store returned value in a variable
    printf("Your bonus this month: $%d\n", bonus);
    printSeparator();

    // --- Example 4: Type 4 Function (With params AND return value) ---
    printf("\n[Example 4] Type 4: Function with parameters AND return value\n");
    
    // Calculate average for different students
    float avg1 = calculateAverage(85, 90, 88);
    printf("Student 1 Average: %.2f\n", avg1);
    
    float avg2 = calculateAverage(78, 82, 80);
    printf("Student 2 Average: %.2f\n", avg2);
    printSeparator();

    // --- Bonus: Nested Function Call ---
    printf("\n[Bonus] Nested Function Call\n");
    demonstrateNestedCall();
    printSeparator();

    // --- Practical Exercise: Combine Multiple Functions ---
    printf("\n[Practice] Building a Simple Grade Report\n");
    
    char studentName[] = "Sarah Smith";
    int id = 11223;
    int s1 = 92, s2 = 88, s3 = 95;
    
    // Use Type 2 function to print info
    printStudentInfo(studentName, id, 0.0);  // GPA calculated next
    
    // Use Type 4 function to calculate average
    float finalGPA = calculateAverage(s1, s2, s3);
    
    // Print final result with formatted output
    printf("Final GPA for %s: %.2f\n", studentName, finalGPA);
    
    // Grade evaluation logic
    if (finalGPA >= 90) {
        printf("Grade: A - Excellent!\n");
    } else if (finalGPA >= 80) {
        printf("Grade: B - Very Good!\n");
    } else if (finalGPA >= 70) {
        printf("Grade: C - Good!\n");
    } else {
        printf("Grade: Needs Improvement - Keep practicing!\n");
    }
    
    printSeparator();
    printf("Tutorial Complete! You now understand C functions!\n");

    return 0;  // main() always returns an integer
}

//=============================================================================
// SECTION 6: BEST PRACTICES & COMMON MISTAKES
//=============================================================================
/*

COMMON MISTAKES TO AVOID:
1 . Forgetting to call the function (declaration ≠ execution)
2 . Mismatched parameter types or order when calling
3 . Missing return statement in non-void functions
4 . Using variables before initializing them
5 . Not including necessary header files (#include <stdio.h>)
6 . Confusing parameters (in definition) with arguments (in call)

PRO TIPS:
1 . Functions are declared BEFORE main(), defined AFTER (or use prototypes)
2 . You can call a function multiple times with different arguments
3 . 'void' means "nothing" - no return value expected
4 . Always cast to float for decimal division: (float)sum / count
5 . Test each function individually before integrating

NEXT STEPS:
1. Modify this code: Change values and observe outputs
2. Create your own function: e.g., convertCelsiusToFahrenheit()
3. Experiment: Try passing arrays or pointers as parameters
4. Challenge: Write a function that returns multiple values using pointers

// Author: yazarouz - Happy Coding!
*/