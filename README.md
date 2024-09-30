# minitalk

### Introduction

The minitalk project is a simple communication program that enables message transfer between two processes: a server and a client. The communication occurs via Unix signals (specifically `SIGUSR1` and `SIGUSR2`), allowing the client to send a string message to the server, which then displays it.

### Key Concepts

- Signals: The project utilizes Unix signals for process communication. Specifically, SIGUSR1 and SIGUSR2 are used to encode the message as a series of bits.
- Server: The server process waits for signals and decodes the incoming bits back into characters, ultimately printing the received message.
- Client: The client sends the message to the server, one bit at a time, by sending the appropriate signals.

### Implementation

1. Client-Side Message Encoding: On the client side, each character from the message is converted to its binary representation and then sent to the server as individual bits using Unix signals (`SIGUSR1` for 0 and `SIGUSR2` for 1).
- Binary Conversion:
  - The parse_string() function converts each character of the string to its binary equivalent. For each character, the ASCII value is repeatedly divided by 2, and the remainder (0 or 1) is stored in the tmp array.
  - This array holds the binary bits for each character (up to 7 bits for standard ASCII characters).
  - The bits are stored in reverse order, so after the conversion, the array is padded with 0s to ensure it has 7 bits for each character.
- Signal Sending:
  - The send_charachter() function sends each bit of the character to the server by using the `kill()` system call, which sends either SIGUSR1 or SIGUSR2 depending on whether the bit is 0 or 1.
  - A delay `usleep(200)` ensures that the server has time to process each signal before receiving the next.

2. Server-Side Message Reception: On the server side, signals are captured and decoded. Each time the server receives a signal (SIGUSR1 or SIGUSR2), it appends the corresponding bit to a buffer. Once a full character (7 bits) is received, it is converted back to its ASCII value and printed.
