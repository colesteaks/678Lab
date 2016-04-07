##Lab 7 Report
####Nicholas Jurden 2415098

1. *Describe the asymmetric solution. How does the asymmetric solution guarantee the philosophers never enter a deadlocked state?*
  Because alternating philosophers attempt to pick up opposite resources, meaning that philosophers next to each others will try for the same resource, and one will not be able to acquire it.
2. *Does the asymmetric solution prevent starvation? Explain.*
  No, if the "rhythm" of the acquisition of resources is off, one philosopher could be at a disadvantage.
3. *Describe the waiter's solution. How does the waiter's solution guarantee the philosophers never enter a deadlocked state?*
  The waiters allow the resources to be acquired atomically, thus preventing deadlock by guaranteeing that, if a philosopher acquires one resource, at also acquires the other.
4. *Does the waiter's solution prevent starvation? Explain.*
  No. It doesn't guarantee fairness between all philosophers.
5. *Consider a scenario under a condition variable based solution where a philosopher determines at the time it frees its chopsticks that both chopsticks of another philosopher (Phil) it shares with are free, and so it sends the (possibly) waiting Phil a signal. Under what circumstances may Phil find that both of its chopsticks are NOT free when it checks?*
  Phil may find that, in the interim, another philosopher has picked up one or both of his chopsticks. 
