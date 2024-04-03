from pynput.keyboard import Controller, Key
import time

keyboard = Controller()

def type_from_file(filename, delay_between_chars=0.05, delay_between_lines=0.5):
    with open(filename, 'r') as file:
        for line in file:
            for char in line.strip():
                keyboard.type(char)
                time.sleep(delay_between_chars)
            keyboard.press(Key.enter)
            keyboard.release(Key.enter)
            time.sleep(delay_between_lines)
time.sleep(10)
type_from_file('input.txt', delay_between_chars=0.01, delay_between_lines=0.1)