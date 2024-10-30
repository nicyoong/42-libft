import os
import glob

# Function to generate the shell script
def generate_shell_script(test_files):
    with open("run_tests.sh", "w") as f:
        f.write("#!/bin/bash\n")
        f.write("set -e\n\n")  # Exit immediately if a command exits with a non-zero status

        for testfile in test_files:
            # Check for the presence of '/' or '\' to determine the separator
            if '/' in testfile:
                function_name = testfile.replace("tests/test_", "").replace(".c", "")
                source_file = f"srcs/{function_name}.c"
                output_exe = f"{function_name}.out"  
            else:
                function_name = testfile.replace("tests\\test_", "").replace(".c", "")
                source_file = f"srcs/{function_name}.c"
                output_exe = f"{function_name}.out"
                testfile = testfile.replace("\\", "/") # Shell scripts are Unix, we change all to /

            # Ensure we are using forward slashes for Unix compatibility
            f.write(f'echo "Testing function: {function_name}"\n')
            f.write(f'echo "Compiling {testfile} with source file {source_file}..."\n')
            f.write(f'echo "gcc -o {output_exe} {testfile} {source_file} -Wall -Wextra -Werror"\n')  # Echo the compile command
            f.write(f'gcc -o {output_exe} {testfile} {source_file} -Wall -Wextra -Werror\n')
            f.write(f'echo "Running {output_exe}..."\n')
            f.write(f'./{output_exe}\n')
            f.write('read -p "Press Enter to continue or type \'finish\' to exit: " input\n')
            f.write('if [ "$input" == "finish" ]; then\n')
            f.write('  exit\n')
            f.write('fi\n\n')


# Function to generate the batch script
def generate_batch_script(test_files):
    with open("run_tests.bat", "w") as f:
        f.write("@echo off\n")
        f.write("setlocal\n")
        f.write("setlocal EnableDelayedExpansion\n\n")

        for testfile in test_files:
            # Check for the presence of '/' or '\' to determine the separator
            if '/' in testfile:
                function_name = testfile.replace("tests/test_", "").replace(".c", "")
                source_file = f"srcs\\{function_name}.c"
                output_exe = f"{function_name}.exe"
                testfile = testfile.replace("/", "\\") # Batch scripts are Windows, we change all / to \
            else:
                function_name = testfile.replace("tests\\test_", "").replace(".c", "")
                source_file = f"srcs\\{function_name}.c"
                output_exe = f"{function_name}.exe"  # Using .exe for Windows

            f.write(f'echo Testing function: {function_name}\n')
            f.write(f'echo Compiling {testfile} with source file {source_file}...\n')
            f.write(f'echo gcc -o {output_exe} "{testfile}" "{source_file}" -Wall -Wextra -Werror\n')  # Echo the compile command
            f.write(f'gcc -o {output_exe} "{testfile}" "{source_file}" -Wall -Wextra -Werror\n')
            f.write(f'if %errorlevel% neq 0 (\n')
            f.write(f'    echo Compilation failed for {testfile}. Exiting...\n')
            f.write(f'    exit /b 1\n')
            f.write(')\n')
            f.write(f'echo Running {output_exe}...\n')
            f.write(f'{output_exe}\n')
            f.write('set /p input="Press Enter to continue or type \'finish\' to exit: "\n')
            f.write('if /i "%input%"=="finish" exit /b\n\n')

def main():
    # Find all test files
    test_files = glob.glob("tests/test_*.c")
    
    # Generate the shell and batch scripts
    generate_shell_script(test_files)
    generate_batch_script(test_files)
    
    print("Shell script 'run_tests.sh' and Batch script 'run_tests.bat' have been generated.")

if __name__ == "__main__":
    main()
