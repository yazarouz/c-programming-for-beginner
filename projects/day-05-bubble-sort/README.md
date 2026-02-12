# Student Grade Sorter

A simple C program that collects student information, sorts them by grade in descending order, and displays a ranked leaderboard.

## Features ✨
- ✅ Collects student names and numeric grades (float)
- ✅ Sorts students using **bubble sort** algorithm (descending order)
- ✅ Safe string input handling with `fgets()` and newline sanitization
- ✅ Clean formatted output with ranking positions
- ✅ Fixed capacity for 5 students (`MAX_STUDENTS = 5`)

## Usage 🚀
```bash
gcc student_sorter.c -o sorter
./sorter