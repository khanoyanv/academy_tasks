# academy_tasks

server.c is a file for our server process. It just prints it's pid, so that we can pass it to client and send data to it by that way.
Whenever server gets SIGUSR1, that means that the current bit of current character of string is 0, and if it gets SIGUSR2 signal, it means that the current bit of current character of string is 1. rec function assembles those digits together, and per 8 digit it prints the resulted character.

client.c is a file for our client process. It has 2 parameters:
  1. The text that has to be sent to server.
  2. Server pid. (For sending signals to server)

In client.c, we get the string from it's parameters, and loop through each symbol of that string, and for each symbol, we get every bit of it and send corresponding signal (SIGUSR1 or SIGUSR2) to the server.

How to test:
  1. Complie and run server.c (gcc -o server.o server.c). This should print you server pid.
  2. Open new terminal tab.
  3. Compile client.c (gcc -o client.o client.c).
  4. Run client.o by passing some string that you want server to recieve and server pid. (./client.o Hello server_id).
