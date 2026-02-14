# Shopping List Manager

A lightweight C console application to manage shopping lists with file persistence and dynamic capacity control.

## ✨ Features

- 🛒 **Item Management**: Add items with name and quantity
- 💾 **File Persistence**: Auto-save/load to `shopping_list.txt`
- 📏 **Capacity Control**: Define maximum list size at runtime
- 🔒 **Input Safety**: Prevents buffer overflow and capacity overflow
- 👁️ **List Preview**: Displays current items after loading and before exit

## 🚀 Quick Start

### Compilation
```bash
gcc save-in-shopping-list -o shopping-list
./shopping-list