# Simple Login System in C

A secure console-based login system implemented in C with authentication controls and user management features.


## ✨ Features

- 🔒 **Secure Authentication**: Username/password verification with 3-attempt lockout
- 👤 **User Profile**: View account details (username, status, role)
- 🔄 **Password Management**: Change password with confirmation validation
- 🚪 **Session Control**: Logout functionality to end user session
- 🛡️ **Input Safety**: Uses `fgets()` with newline sanitization to prevent buffer issues

## 🚀 Quick Start

### Compilation
```bash
gcc Simple_Login_System.c -o login_system