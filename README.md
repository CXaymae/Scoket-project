# Scoket-project

This is a C program that creates a client socket and connects to a server. The program prompts the user to enter their username and password, sends this information to the server, and waits for a response. If the server responds with "LOGIN échoué," the program allows the user to try to log in again up to three times before closing the connection. If the server responds with the user's profile, the program sends the profile to the client and closes the connection.

The program includes the following header files:

stdio.h: Standard Input and Output library
stdlib.h: Standard Library header
string.h: String Manipulation functions header
sys/socket.h: Socket programming header
netinet/in.h: Contains constants and structures needed for internet domain addresses.
arpa/inet.h: Contains definitions for internet operations.
The program also defines a constant, PORT, which is set to 1234. The main function takes two arguments, argc and argv.

The program begins by creating a client socket using the socket function. If the socket cannot be created, the program prints an error message and exits with a failure code. The program then initializes a sockaddr_in structure with the server's IP address and port number.

Next, the program prompts the user to enter their username and password and sends this information to the server using the send function. The program then waits for a response from the server using the recv function.

If the server responds with "LOGIN échoué," the program allows the user to try to log in again up to three times before closing the connection. If the server responds with the user's profile, the program sends the profile to the client and closes the connection.

The program also includes a function, get_user_profile, that reads a file containing user information and returns the profile of a specified user. If the specified user is not found, the function returns NULL.

The program uses the strtok function to parse the lines in the user information file and extract the relevant information. The program also uses the fopen function to open the user information file and the fclose function to close it.

Overall, this program demonstrates how to create a client socket, connect to a server, send and receive data, and parse information from a file.
