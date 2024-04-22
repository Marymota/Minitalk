# Minitalk

## Summary
Minitalk is a small data exchange program using UNIX signals.

## Mandatory Part
Communication program in the form of a client and a server.
1. The server starts first, printing its PID.
2. The client takes two parameters: the server PID and the string to send.
3. The client sends the string passed as a parameter to the server.
4. Once received, the server prints the string quickly.
4. The server can handle multiple clients without needing to restart.
5. Communication between client and server is done only using UNIX signals.

## Bonus Part
The server acknowledges every message received by sending back a signal to the client and the program has Unicode characters support.


---
# 42 School
This project is an integral part of the curriculum at [42 Lisboa](https://42lisboa.com/), emphasizing practical learning, collaboration, and problem-solving. It sets the stage for your journey into the world of programming, equipping you with essential skills and knowledge for future endeavors.
