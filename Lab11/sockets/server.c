#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/un.h>

#define QSIZE 5
#define BSIZE 256
#define SOCKET_ADDRESS "mysock"

/*
 * Convert a null-terminated sting (one whose end is denoted by a byte
 * containing '\0') to all upper case letters by starting at the
 * beginning and going until the null byte is found.
 */
void
convert_string (char *cp)
{
  char *currp;	/* pointer to current position in the input string */
  int c;        /* return value of toupper is the converted letter */

  for (currp = cp; *currp != '\0'; currp++) {
    c = toupper (*currp);
    *currp = (char) c;
  }
}

int main(int argc, char *argv[])
{
  int handshake_sockfd, session_sockfd, ret;
  struct sockaddr_un saun;
  char buf[BSIZE];
   
#if 0
  /* Add Code: Populate the sockaddr_un struct */
 
  /* Add Code: Create the handshake socket */
  if (handshake_sockfd < 0) {
    fprintf(stderr, "\nError Opening Socket, ERROR#%d\n", errno);
    return EXIT_FAILURE;
  }


  /* 
   * We need to unlink the address before binding to ensure the
   * address is free before attempting to bind.
   */
  unlink(SOCKET_ADDRESS);

  /* Add Code: Bind the handshake socket to the sockaddr. */ 
  if (ret < 0) {
    fprintf(stderr, "\nError Binding Socket, ERROR#%d\n", errno);
    return EXIT_FAILURE;
  }

  /* Add Code: Make the handshake socket a listening socket, with a
   * specified Queue Size
   */
  if (ret < 0) {
    fprintf(stderr, "\nError Listening on Socket, ERROR#%d\n", errno);
    return EXIT_FAILURE;
  }

  /* Add Code: Accept a connection on the handshake socket,
   * giving the session socket as the return value.
   */
  if (session_sockfd < 0) {
    fprintf(stderr, "\nError Accepting Socket, ERROR#%d\n", errno);
    return EXIT_FAILURE;
  }

  /* Add Code: Read lines one at a time from the connected session
   * socket. Convert each line to uppercase using convert_string, and
   * write the line back to the client. Continue until there are no
   * more lines to read.
   */
  while (?) {
    printf("RECEIVED:\n%s", buf);
    printf("SENDING:\n%s\n", buf);
  }

  close(session_sockfd);
  close(handshake_sockfd);
#endif
}
