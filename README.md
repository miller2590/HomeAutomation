# Home Automation

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [What I learned](#what-i-learned)
- [License](#license)

## Introduction

This project is a home automation system implemented in C++. It leverages the principles of Object-Oriented Programming (OOP) to model various smart devices such as a thermostat, television, lights, and a security system. Each device is represented as a class (Thermostat, Television, Lights, SecuritySystem), inheriting from a base SmartDevice class, demonstrating the OOP principle of inheritance.

The system is controlled through a Menu class, which encapsulates the user interaction logic, demonstrating the OOP principle of encapsulation. The HomeController class acts as a coordinator between the Menu and the device classes, demonstrating the OOP principle of association.

The GenerateUUID class is used to generate unique identifiers for each device, demonstrating the OOP principle of abstraction. The use of OOP in this project helps in organizing and structuring the codebase, making it easier to understand, maintain, and extend.

## Features

- Smart Thermostat: The Thermostat class models a smart thermostat. It allows setting and getting the current, AM, and PM temperatures. This class demonstrates the OOP principles of encapsulation and inheritance.

- Smart Television: The Television class models a smart television. It allows changing the channel. This class demonstrates the OOP principles of encapsulation and inheritance.

- Smart Lights: The Lights class models smart lights. It allows turning the lights on and off. This class demonstrates the OOP principles of encapsulation and inheritance.

- Smart Security System: The SecuritySystem class models a smart security system. It allows setting the sensitivity and checking the status of the system. This class demonstrates the OOP principles of encapsulation and inheritance.

- User Interaction: The Menu class provides a user interface for interacting with the smart devices. It encapsulates the user interaction logic, demonstrating the OOP principle of encapsulation.

- System Control: The HomeController class coordinates the interaction between the Menu and the device classes. It demonstrates the OOP principle of association.

- Unique Identifiers: The GenerateUUID class generates unique identifiers for each device. It demonstrates the OOP principle of abstraction.

## Requirements

To build and run this project, you will need the following tools and libraries:

- C++ Compiler: A modern C++ compiler supporting C++14 or later. For example, GCC 5.0 or later, or Clang 3.4 or later.
- CMake: CMake version 3.10 or later is required for building the project. CMake is a cross-platform build system that can generate build files for the system of your choice.
- Standard Library: This project uses the standard C++ library. No additional libraries are required.

Please ensure that these tools are installed and properly configured on your system before attempting to build and run the project.

## Installation

Follow these steps to install and build the project:

1. Clone the Repository: Use the following command to clone the repository:

   ```
   git clone https://github.com/miller2590/HomeAutomation.git
   ```

2. Navigate to the Project Directory: Use the following command to navigate to the project directory:

   ```
   cd HomeAutomation
   ```

3. Create a Build Directory: Use the following command to create a new directory named build and navigate into it:

   ```
   mkdir build && cd build
   ```

4. Configure the Project: Use the following command to configure the project:

   ```
   cmake ..
   ```

5. Build the Project: Use the following command to build the project:
   ```
   make
   ```

After following these steps, you should have a built executable of the home automation system in the build directory.

## Usage

- After building the project, you can run the home automation system by executing the generated file:

  ```
  ./HomeAutomation
  ```

- This will start the menu, and you can interact with the system by following the prompts.

  - Here's an example of how you might interact with the system:

    ```
    Welcome to the Home Automation System!
    1. List all devices
    2. Interact with a device
    3. Exit
    Enter your choice: 1

    Devices:
    1. Thermostat
    2. Television
    3. Lights
    4. Security System
    Enter the number of the device you want to interact with: 2

    Television Menu:
    1. Change channel
    2. Get current channel
    3. Back
    Enter your choice: 1

    Enter the new channel: 5
    Channel changed successfully!
    ```

- In this example, the user lists all devices, chooses to interact with the Television, and changes the channel. The exact options and prompts may vary depending on the state of the system and the devices.

## What I Learned

This project was a great opportunity to learn and practice various aspects of C++ and Object-Oriented Programming. Here are some key takeaways:

- **Object-Oriented Programming**: This project reinforced the principles of OOP such as inheritance, encapsulation, and abstraction. Each device in the system is modeled as a class, with common functionality factored out into a base `SmartDevice` class.

- **C++ Programming**: Working on this project helped improve my understanding of C++ syntax, standard library functions, and features such as constructors, destructors, and virtual functions.

- **Project Organization**: This project helped me understand how to structure and organize a larger codebase. I learned how to separate code into different files and directories based on their functionality.

- **Build Systems**: I learned how to use CMake to manage the build process of the project, which is a valuable skill for larger C++ projects.

- **Version Control**: Using Git for version control helped me keep track of changes and made it easier to experiment with new features and roll back changes when necessary.

## License

This project is licensed under the terms of the MIT license.

MIT License

Copyright (c) [2024] [Gage Miller]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
