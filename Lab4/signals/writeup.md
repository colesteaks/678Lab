#Lab 4 WriteUp
##Nicholas Jurden 2415098

1.  I learned in this lab that we can override signals that normally stop a program, like SIGINT. With this in mind, it makes sense that there are KILL and STOP signals that cannot be overridden, or else a program could be engineered to run until power is shut off with no other remedy.

2.  pause() system call causes the current thread to sleep and wait for a signal to be emitted. We benefit in this case because we are working exclusively with signals, therefore saving on resources by not continuously running a thread.

3.  We mask other signals to prevent them from interfering with our program. Because we know the only signals we want to deliver successfully are SIGINT and SIGTSTP, we can safely mask other signals that might affect our program during runtime.

4.  Because we want the SIGALRM signal to deliver as we have perscribed in `catch_alrm`.
