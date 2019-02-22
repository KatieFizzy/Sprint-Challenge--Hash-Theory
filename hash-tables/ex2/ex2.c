#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "ex2.h"

char **reconstruct_trip(Ticket **tickets, int length)
{
  HashTable *ht = create_hash_table(16);
  char **route = malloc(length * sizeof(char *));

  /* PSUEDOCODE / LOGIC 

  // change value of NONE to 'start' and 'end' 
  char route = [start] 

  for (ticket in tickets) {
    if ticket.source == NONE {
      ticket.source = start
    }
    if ticket.destination == NONE {
      ticket.destination = end 
    }

  //populate hashtable 
  for (ticket in tickets) {
    h[ticket.source] = ticket.destination // assign/insert source to keys, and destination to values 
  }

  current_city = start // set current city to start

  while current_city != end { // as long as current city hasn't reached 'end', continue to loop 
    current_ciy = h[current_city] 
    append current_city to route  // fill in route with entry for each city visited
  }
  current_city = end // set current city to end
  append current_city to route // 

 */
  return route;
}

void print_route(char **route, int length)
{
  for (int i = 0; i < length; i++) {
    printf("%s\n", route[i]);
  }
}



#ifndef TESTING
int main(void)
{
  // Short test
  Ticket **tickets = malloc(3 * sizeof(Ticket *));

  Ticket *ticket_1 = malloc(sizeof(Ticket));
  ticket_1->source = "NONE";
  ticket_1->destination = "PDX";
  tickets[0] = ticket_1;

  Ticket *ticket_2 = malloc(sizeof(Ticket));
  ticket_2->source = "PDX";
  ticket_2->destination = "DCA";
  tickets[1] = ticket_2;

  Ticket *ticket_3 = malloc(sizeof(Ticket));
  ticket_3->source = "DCA";
  ticket_3->destination = "NONE";
  tickets[2] = ticket_3;

  print_route(reconstruct_trip(tickets, 3), 3); // PDX, DCA, NONE

  return 0;
}
#endif
