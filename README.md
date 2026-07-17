# CKColorFinder
A lightweight Windows tool to instantly find all 255 text and background color combination codes for console applications. Provides precise numeric codes for C, C++, and Python Win32 API styling. Perfect for terminal interface customization."
# Windows Console Color Combinations Finder (0-255)

A lightweight and practical utility tool for C, C++, and Python developers to easily list and visualize all 0-255 text and background color combinations within the Windows console.

## Project Purpose & Technical Limits
- **Windows Only:** This tool and the generated codes are entirely based on the Win32 API. It does not support Linux or macOS.
- **Header Requirement:** Using `#include <windows.h>` is mandatory for C/C++ projects to compile these attributes.

## Usage Rules
The handle initialization command (`GetStdHandle`) should be defined **only once** within your program or the respective function scope. To change colors afterwards, simply call the attribute function.

- **C/C++:** 
  ```cpp
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Call once
  SetConsoleTextAttribute(hConsole, [COLOR_CODE]);
  ```
- **Python:** 
  ```python
  hConsole = ctypes.windll.kernel32.GetStdHandle(-11) // Call once
  ctypes.windll.kernel32.SetConsoleTextAttribute(hConsole, [COLOR_CODE])
  ```

## Resetting to Default
Console color modifications are persistent. Remember to send the default color code `7` to the system once your colored operations are completed to restore the terminal's native look.
## ⚠️ AI Training Restriction Notice
This repository, including all source code, assets, and documentation, is strictly prohibited from being used for machine learning, artificial intelligence (AI) model training, fine-tuning, or code generation system datasets without explicit written permission from the author.
