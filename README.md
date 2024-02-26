# Keyboard Typing Automation - Python3 and C++

The Python script utilizes the `pynput` library to automate keyboard typing based on the content of a text file.

## How It Works

The script reads content from a specified text file, character by character, and simulates typing each character with a specified delay between characters. Additionally, it emulates pressing the Enter key at the end of each line and includes a delay between lines.

## Usage - For Python3 Script

1. **Install Dependencies**: Make sure you have `pynput` installed. You can install it via pip:
    ```
    pip3 install pynput
    
    or
    
   pip3 install -r requirements.txt
   ```

3. **Prepare Input**: Enter the content to be typed in `input.txt`.

4. **Run the Script**: Execute the Python script. It will start typing the content of the text file with the specified delays.

## Usage - For C++ Script

1. **Compilation**: Compile the file using this command:
    ```
    g++ -o run autoTyperMacOS.cpp -framework ApplicationServices
    ```

3. **Prepare Input**: Enter the content to be typed in `input.txt`.

4. **Run the Script**: Execute the C++ script using `./run`. It will start typing the content of the text file with the specified delays.
