# 📚 Simple Library Management System

> A console-based library management system written in C

## 📋 Overview

This project is a simple command-line application for managing a personal or small-scale library. It allows users to perform basic CRUD operations on books with data persistence using a text file.

## ✨ Features

| Feature | Description |
|---------|-------------|
| ➕ Add Book | Add new books with title, author, and unique ID |
| 📖 Borrow Book | Mark a book as borrowed (status = 0) |
| 🔄 Return Book | Mark a borrowed book as available (status = 1) |
| 🔍 Search by Title | Find books using exact title match |
| 🔍 Search by Author | Find books using exact author match |
| 📋 Display All | List all books with their current status |
| 🗑️ Delete Book | Remove a book from the library |
| 💾 File Persistence | Auto-load on start, auto-save on exit |

## 🗄️ Data Storage

Data is stored in `library.txt` with pipe-delimited format

## 🚀 How to Compile & Run

### Using GCC:
```bash
gcc -o library main.c
./library


