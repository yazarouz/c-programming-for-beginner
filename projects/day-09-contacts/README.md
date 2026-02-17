# 📇 Simple Phonebook Application

A lightweight console-based phonebook application written in **C** that allows users to manage contacts efficiently with file persistence support.

> **Author:** yazarouz  
> **Date:** February 12, 2026  
> **Language:** C (C99 Standard)

---

## ✨ Features

- ➕ **Add Contacts**: Add multiple contacts with name and phone number
- 🔍 **Search Contacts**: Find contacts instantly by name
- 📋 **Display All**: View all saved contacts in a formatted list
- 💾 **File Persistence**: Automatically save and load contacts from `phonebook.txt`
- 🎯 **User-Friendly Menu**: Simple interactive CLI interface

---

## 🛠️ Technical Details

| Component | Description |
|-----------|-------------|
| **Data Structure** | `struct Contact` with name & phone fields |
| **Storage Format** | Plain text file (`name|phone` delimited) |
| **Max Contacts** | 20 (configurable via `MAX_CONTACTS`) |
| **Input Handling** | `fgets()` with newline sanitization |
| **File I/O** | `fopen`, `fscanf`, `fprintf` |

---

## 🚀 How to Compile & Run

### Using GCC:
```bash
gcc -o phonebook phonebook.c -std=c99
./phonebook